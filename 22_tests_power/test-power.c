#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

int main(void){
  unsigned p0;
  p0=power(0,2);
  if(p0 != 0 ){
    // printf("good0");
    exit(EXIT_FAILURE);
  }
  
  unsigned p1;
  p1=power(2,0);
  if(p1 != 1 ){
    //printf("good1");
    exit(EXIT_FAILURE);
  }
  
  unsigned p2;
  p2=power(1,1);
  if(p2 != 1 ){
    // printf("good2");
    exit(EXIT_FAILURE);
  }
  
  unsigned p3;
  p3=power(2,2);
  if(p3 != 4 ){
    // printf("good3");
    exit(EXIT_FAILURE);
  }
  
  unsigned p4;
  p4=power(2,3);
  if(p4 != 8){
    // printf("good4");
    exit(EXIT_FAILURE);
  }
  
  unsigned p5;
  p5=power(3,2);
  if(p5 != 9){
    //printf("good5");
    exit(EXIT_FAILURE);
  }
  
  unsigned p6;
  p6=power(-2,4);
  if(p6 != 16){
    // printf("good6"); 
    exit(EXIT_FAILURE);
  }
  
  unsigned p7;
  p7=power(2,-4);
  if(p7 !=0){
    // printf("good7");
    exit(EXIT_FAILURE);
  }
  
  unsigned p8;
  p8=power(-2,3);
  if(p8 != -8){
    // printf("good8");
    exit(EXIT_FAILURE);
  }
  
  unsigned p9;
  p9=power(0,0);
  if(p9 != 1 ){
    // printf("good9");
    exit(EXIT_FAILURE);
  }
  /*
  unsigned p10;
  p10=power(2,2.4);
  if(p10 != 5){
    printf("good10");
    exit(EXIT_FAILURE);
    }*/
  return EXIT_SUCCESS;
}
