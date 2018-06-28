#include "unity.h"
#include "yxaexception.h"
#include "CException.h"
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

char *names[]={
  "ali",
  "david",
  "ah beng",
  "sally"
  
};
char *getName(int index){
  if((index>=4) || (index<0)){
    Throw("error: out of bound of the array.");
  }
  return names[index];

}

void test_getName_given1_expect_David(void){
  CEXCEPTION_T e;
  char *name;
  
  Try{
    name=getName(10);
    printf("not ok it should show error");
  } 
  Catch(e){
    printf("error code: %s",e);
  }
 // TEST_ASSERT_EQUAL_STRING("Davidx",name);
}


void test_getName_given_minus_1_expect_EER_OUT_OF_BOUND(void)
{
  CEXCEPTION_T e;
  char *name;
  Try{
    name=getName(3);
    //TEST_FAIL_MESSAGE("expected EER_OUT_OF_BOUND to be thrown, but none.");
    printf("ok no error");
  } 
  Catch(e){
    printf("error code: %s",e);
  }
}
