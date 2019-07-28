#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int *array , size_t n);
int main(void){

  int  mytest[]={-1,-2,-3,1,5};
  size_t x=maxSeq(mytest,5);
  if (x != 3){
      printf("error0");
  return (EXIT_FAILURE);
  	 }

  int mytest1[] = {-1,0,1,2};
  size_t y=maxSeq(mytest1,4);
  if(y != 4){
    printf("error1");
    return (EXIT_FAILURE);
    }
  int mytest3[]={12,12,12};
  size_t z=maxSeq(mytest3,3);
  if (z != 1){
    printf("error3");
    return (EXIT_FAILURE);
  }

  int mytest2[]={-4,-3,-2,-1};
  size_t c=maxSeq(mytest2 ,4);
  if(c != 4){
    printf("error2");
    return (EXIT_FAILURE);
		     }
  int arr[]={};
  size_t s=maxSeq(arr , 0);
  if (s != 0){
    printf("error4");
    
    return (EXIT_FAILURE);
			 }
  
  int test[]={5};
  size_t q=maxSeq(test , 1);
  if (q != 1){
    printf("error5");
    return(EXIT_FAILURE);
    }
   printf("correct");
  return EXIT_SUCCESS;
}
