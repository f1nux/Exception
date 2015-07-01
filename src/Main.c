#include "Main.h"
#include "CException.h"
#include "ErrorObject.h"
#include <stdio.h>
#include <malloc.h>

int shouldFail =1;
void doThings(){
  
  //ErrorObject err;
  
  
 // Try{
   doSomething();
 // }Catch(err){
  //  printf("Error: %s\n", err->errorMsg);
  //  freeError(err);
    
  //}
  
  
  return;
}


int doSomething(){
  //ErrorObject *errorObj=malloc(sizeof(ErrorObject));
  
  if(shouldFail){
    throwError("Something sot",ERR_DUNNO_WHAT_HAPPEN);
  }
  return 1;
}


int specialAdd(int negval, int posval){
  


  if (negval>0) {
    throwError("num not -ve",ERR_NUMBER_NOT_NEGATIVE);
  }else if(posval<0){
    throwError("num not +ve",ERR_NUMBER_NOT_POSITIVE);
    
  }
    
  // printf("%d+%d=%d\n",negval,posval,(negval+posval));
 
  
  return (negval+posval);
}