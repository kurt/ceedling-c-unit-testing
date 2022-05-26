/**
 * @file    test_foot_event_instance_write_integration.c
 * @ingroup foot_event_generator
 *
 * foot_event_generator integration test file.
 *
 * @par COPYRIGHT MARKING
 *      Bionic Power Inc. CONFIDENTIAL <br>
 *      Copyright 2022 Bionic Power Inc. <br>
 *      All Rights Reserved.
 *      @par
 *      NOTICE: All information contained herein is, and remains, the property of Bionic Power Inc.
 *      and its suppliers, if any. The intellectual and technical concepts contained herein are
 *      proprietary to Bionic Power Inc. and its suppliers and may be covered by Patents, pending
 *      patents, and are protected by trade secret or copyright law.
 *      @par
 *      Dissemination of this information or reproduction of this material is strictly forbidden
 *      unless prior written permission is obtained from Bionic Power Inc.
 *
 * @addtogroup foot_event_generator
 * @{
 */
#include "unity.h"

TEST_FILE("cmsis_gcc.c"); //when cexception_helper_str is needed


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

#include "mock_flt.h"

#include "mock_freertos_stubs.h"
#include "mock_printf.h"
#include "mock_OSAL_thread.h"
#include "mock_OSAL_kernel.h"
#include "mock_OSAL_mutex.h"
#include "mock_nvp.h"
#include "mock_dbglog.h"

#include "algfsr.h"
#include "foot_event_generator_port.h"
#include "foot_event_generator_private.h"
#include "foot_event_generator.h"
#include "foot_event_adapter.h"

#include "foot_event_generator_port.c"
#include "foot_event_test_helper.h"

#ifdef WINDOWS
 #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #define GetCurrentDir getcwd
#endif /* ifdef WINDOWS */

#define IntegrationTest1Done 0
#define IntegrationTestDone 0

//Made this global on purpose
struct footEventGenSmDescriptor FootEventGeneratorSmDescriptorTestInstance;

void setUp(void)
{
    //Test Setup
    FootEventGeneratorSmDescriptorTestInstance = helper_FootEventGenerator_INITIALIZE();
    helper_FootEventGenerator_Init(0);
    OSAL_mutexCreateStatic_IgnoreAndReturn(1);
    FootEventGenerator_Init(&FootEventGeneratorSmDescriptorTestInstance, HeelStrikeDetect);
    FLT_InterQuartileMean16S_Init_Ignore();
    FLT_InterQuartileMean16S_Init_Ignore();
    ALGFSR_Init();
}

void tearDown(void)
{
    FootEventGenerator_DeInit();
}

/*
 *@brief a function to call the updateAllFootStateParameters command timesToLoop times.
 *       The function calls the appropriate cmock expectations.
 *       It yields the processor to allow for other threads to run.
 *@input void * vargp: a pointer to the test value to write to the state parameters
 */
void * updateAllFootStateParameters_thread(void * vargp)
{
    int timesToLoop = 1;

    printf("Enter updateAllFootStateParameters_thread\n\r");
    fflush(stdout);
    bool retVal = false;
    while (retVal != true)
    {
        uint16_t testVal = *(int16_t *)vargp; //local is passed in through vargp
        OSAL_uptime_msec_IgnoreAndReturn(1);
        OSAL_uptime_msec_IgnoreAndReturn(2);
        for (int j = 0; j < MAX_STATE_COUNT * 2; j++)
        {
            NVP_GetParameter_IgnoreAndReturn(testVal);
        }
        for (int k = 0; k < MAX_STATE_COUNT; k++)
        {
            OSAL_mutexTake_IgnoreAndReturn(0);
            OSAL_mutexGive_IgnoreAndReturn(0);
        }
        OSAL_threadDelay_Ignore();
        printf("mid updateAllFootStateParameters_thread\n\r");
        fflush(stdout);
        retVal = updateAllFootStateParameters();
        sleep(1);
        printf("just yielded updateAllFootStateParameters_thread\n\r");
        fflush(stdout);
    }
}

/*
 *
 *@brief Success: this test spools a thread to run the "CLI" command to update the parameters for
 *       the foot_event_generator. Once the parameters have been added to the pendingSmDesc the test
 *       thread (main thread) will reset the updateStatePending back to invalidState. The test runs
 *       until all states have been executed. The test is validated by asserting that the HeelStrikeThresh
 *       and timeout_ms were written properly for each state.
 */
void test__updateAllFootStateParameters__WhenInvalidStateIsUpdated()
{
    //Test Setup
    int16_t testVal = 16;
    extern struct footEventGenSm footEventGen_Inst;
    pthread_t thread_id;
    pthread_attr_t tattr;
    size_t size = 0 + 0x989680;//10 megabyte
    int ret = pthread_attr_init(&tattr);

    ret = pthread_attr_setstacksize(&tattr, size);

    pthread_create(&thread_id, &tattr, updateAllFootStateParameters_thread, &testVal);

    OSAL_mutexTake_IgnoreAndReturn(1);
    OSAL_mutexTake_IgnoreAndReturn(1);
    OSAL_mutexTake_IgnoreAndReturn(1);
    OSAL_mutexTake_IgnoreAndReturn(1);
    OSAL_mutexTake_IgnoreAndReturn(1);
    OSAL_mutexTake_IgnoreAndReturn(1);
    OSAL_mutexGive_IgnoreAndReturn(1);
    OSAL_mutexGive_IgnoreAndReturn(1);
    OSAL_mutexGive_IgnoreAndReturn(1);
    OSAL_mutexGive_IgnoreAndReturn(1);
    OSAL_mutexGive_IgnoreAndReturn(1);
    OSAL_mutexGive_IgnoreAndReturn(1);

    for (int i = 0; i < MAX_STATE_COUNT; i++)
    {
        while (1)
        {
            FOOT_EVENT_GENERATOR_MUTEX_LOCK();
            enum footEventGenState state = footEventGen_Inst.updateStatePending;
            FOOT_EVENT_GENERATOR_MUTEX_UNLOCK();
            if (state != invalidState)
            {
                //All states will have the same heelStrikeVoltageThresh and timeout_ms
                FOOT_EVENT_GENERATOR_MUTEX_LOCK();
                TEST_ASSERT_EQUAL(testVal, footEventGen_Inst.pendingStateDesc.stateParameters.heelStrikeVoltageThresh_mV);
                TEST_ASSERT_EQUAL(testVal, footEventGen_Inst.pendingStateDesc.stateParameters.timeout_ms);
                footEventGen_Inst.updateStatePending = invalidState;
                FOOT_EVENT_GENERATOR_MUTEX_UNLOCK();
                break;
            }

            sched_yield();
            sleep(0.05);
        }
    }
    sleep(5);
}
