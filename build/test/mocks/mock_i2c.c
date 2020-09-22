/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_i2c.h"

static const char* CMockString_i2c_readRegister = "i2c_readRegister";
static const char* CMockString_registerAddress = "registerAddress";

typedef struct _CMOCK_i2c_readRegister_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint16_t ReturnVal;
  int CallOrder;
  uint8_t Expected_registerAddress;

} CMOCK_i2c_readRegister_CALL_INSTANCE;

static struct mock_i2cInstance
{
  char i2c_readRegister_IgnoreBool;
  uint16_t i2c_readRegister_FinalReturn;
  char i2c_readRegister_CallbackBool;
  CMOCK_i2c_readRegister_CALLBACK i2c_readRegister_CallbackFunctionPointer;
  int i2c_readRegister_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE i2c_readRegister_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_i2c_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.i2c_readRegister_CallInstance;
  if (Mock.i2c_readRegister_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_i2c_readRegister);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.i2c_readRegister_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_i2c_Init(void)
{
  mock_i2c_Destroy();
}

void mock_i2c_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

uint16_t i2c_readRegister(uint8_t registerAddress)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_i2c_readRegister_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_i2c_readRegister);
  cmock_call_instance = (CMOCK_i2c_readRegister_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.i2c_readRegister_CallInstance);
  Mock.i2c_readRegister_CallInstance = CMock_Guts_MemNext(Mock.i2c_readRegister_CallInstance);
  if (Mock.i2c_readRegister_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.i2c_readRegister_FinalReturn;
    Mock.i2c_readRegister_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.i2c_readRegister_CallbackBool &&
      Mock.i2c_readRegister_CallbackFunctionPointer != NULL)
  {
    uint16_t cmock_cb_ret = Mock.i2c_readRegister_CallbackFunctionPointer(registerAddress, Mock.i2c_readRegister_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_i2c_readRegister,CMockString_registerAddress);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_registerAddress, registerAddress, cmock_line, CMockStringMismatch);
  }
  if (Mock.i2c_readRegister_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.i2c_readRegister_CallbackFunctionPointer(registerAddress, Mock.i2c_readRegister_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_i2c_readRegister(CMOCK_i2c_readRegister_CALL_INSTANCE* cmock_call_instance, uint8_t registerAddress)
{
  cmock_call_instance->Expected_registerAddress = registerAddress;
}

void i2c_readRegister_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint16_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_i2c_readRegister_CALL_INSTANCE));
  CMOCK_i2c_readRegister_CALL_INSTANCE* cmock_call_instance = (CMOCK_i2c_readRegister_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.i2c_readRegister_CallInstance = CMock_Guts_MemChain(Mock.i2c_readRegister_CallInstance, cmock_guts_index);
  Mock.i2c_readRegister_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.i2c_readRegister_IgnoreBool = (char)1;
}

void i2c_readRegister_CMockStopIgnore(void)
{
  if(Mock.i2c_readRegister_IgnoreBool)
    Mock.i2c_readRegister_CallInstance = CMock_Guts_MemNext(Mock.i2c_readRegister_CallInstance);
  Mock.i2c_readRegister_IgnoreBool = (char)0;
}

void i2c_readRegister_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t registerAddress, uint16_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_i2c_readRegister_CALL_INSTANCE));
  CMOCK_i2c_readRegister_CALL_INSTANCE* cmock_call_instance = (CMOCK_i2c_readRegister_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.i2c_readRegister_CallInstance = CMock_Guts_MemChain(Mock.i2c_readRegister_CallInstance, cmock_guts_index);
  Mock.i2c_readRegister_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_i2c_readRegister(cmock_call_instance, registerAddress);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void i2c_readRegister_AddCallback(CMOCK_i2c_readRegister_CALLBACK Callback)
{
  Mock.i2c_readRegister_IgnoreBool = (char)0;
  Mock.i2c_readRegister_CallbackBool = (char)1;
  Mock.i2c_readRegister_CallbackFunctionPointer = Callback;
}

void i2c_readRegister_Stub(CMOCK_i2c_readRegister_CALLBACK Callback)
{
  Mock.i2c_readRegister_IgnoreBool = (char)0;
  Mock.i2c_readRegister_CallbackBool = (char)0;
  Mock.i2c_readRegister_CallbackFunctionPointer = Callback;
}

