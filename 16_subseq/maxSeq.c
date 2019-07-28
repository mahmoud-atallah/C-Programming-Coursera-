#include <stdlib.h>
#include <stdio.h>

/*size_t maxSeq(int *array , size_t n){
  size_t min = 0;
  size_t max = 0;
  size_t length = 0;
  size_t maxLength= 1;

  if(n <= 0){
    return 0;
  }
  
  for(size_t i = 0; i < n; i++){
    if(array[i+1] > array[i]){
      max = i+1;
      length = max - min +1;
      //max++;
    }
    
    else{
      // min = max + 1;
      min = i +2;
      if (length > maxLength){
	maxLength = length;
      }
    }
  }
  return maxLength;
}
*/
size_t maxSeq(int  *array , size_t n){
  size_t min = 0;
  size_t max = 0;
  size_t length = 0;
  size_t maxLength= 1;
  
  if(n <= 0){
    return 0;
  }
  
  for(size_t i = 0; i < n-1; i++){
    
    if(array[i+1] > array[i]){
      max = i+1;
      length = max - min +1 ;
      //max++;
      //continue;
    }
    
    else{
      //min = max+1;
      //printf("%zu\n",min);
      //printf("%zu\n",length);
      min = i+1;
      //length = i - min +1;
      //min = i+2;
    }
    if (length > maxLength){
      maxLength = length;
    }
    
  }
  return maxLength;
}


/*
size_t maxSeq(int  *array , size_t n){
  size_t min = 0;
  size_t max = 0;
  size_t length = 0;
  size_t maxLength= 1;
  
  if(n <= 0){
    return 0;
  }
  
  for(size_t i = 0; i < n; i++){
    if(array[i+1] > array[i]){
      max = i+1;
      continue;
    }
   
    length = max - min +1;
    min = i+2;
    if (length > maxLength){
      maxLength = length;
    }
  }
  return maxLength;
}
*/
