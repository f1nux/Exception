#include "unity.h"
#include "Main.h"
#include "CException.h"
#include "ErrorObject.h"
#include <malloc.h>

void setUp(void){}

void tearDown(void){}

void test_doThings(void){
	 ErrorObject *err;
  
  Try{
   doThings();
   TEST_FAIL_MESSAGE("expect ERR_DUNNO_WHAT_HAPPEN");
  }Catch(err){
    TEST_ASSERT_EQUAL_STRING("Something sot",err->errorMsg);
    freeError(err); 
  }
}

void test_specialAdd_given_neg5_11_should_return_6(){
  int result = specialAdd(-5,11);
  TEST_ASSERT_EQUAL(6,result);
}

void test_specialAdd_given_7_11_should_throw_ERR_NUMBER_NOT_NEGATIVE(){
  ErrorObject *err;
  Try{
   int result = specialAdd(7,11);
   ///TEST_FAIL_MESSAGE("expect ERR_DUNNO_WHAT_HAPPEN");
  }Catch(err){
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_NEGATIVE,err->errorCode);
    TEST_ASSERT_EQUAL_STRING("num not -ve",err->errorMsg);
  }
}

void test_specialAdd_given_neg7_NEG11_should_throw_ERR_NUMBER_NOT_POSITIVE(){
  ErrorObject *err;
  Try{
   int result = specialAdd(-7,-11);
   ///TEST_FAIL_MESSAGE("expect ERR_DUNNO_WHAT_HAPPEN");
  }Catch(err){
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_POSITIVE,err->errorCode);
    TEST_ASSERT_EQUAL_STRING("num not +ve",err->errorMsg);
  }
}