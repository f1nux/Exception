#include "ErrorObject.h"
#include "CException.h"
#include <malloc.h>


void throwError(char *message, ErrorCode errCode){
  
  ErrorObject *errorObj=malloc(sizeof(ErrorObject));
  errorObj->errorMsg =message;
  errorObj->errorCode=  errCode;
  Throw(errorObj);
  
  
  
  return;
}

void freeError(ErrorObject *errorObj){
  free(errorObj);
  
  
  return;
}