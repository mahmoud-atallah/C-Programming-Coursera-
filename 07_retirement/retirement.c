#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement(int startAge ,double initial, retire_info working, retire_info retired){
  int years;
  double savings;
  int mont;
  int y;
  //  int r;
  int f;
  int p=0;
  years=startAge/12;
  mont=startAge%12;
  y=years+working.months/12;
  if(mont>0){
    
    savings= initial;
    
    printf("Age %3d month %2d you have $%.2lf\n",years,mont,savings);
    
    for(int x=mont+1;x<12;x++ ){
      
      savings= initial + (initial * working.rate_of_return) + working.contribution;
      
      printf("Age %3d month %2d you have $%.2lf\n",years,x,savings);
              
      initial=savings;
    }
  }
  
  
  for(int i=years+1;y>=i;i++){
    //savings= initial +(initial*working.rate_of_return)+ working.contribution;
    for(int x=0;x<12;x++ ){
      
      savings= initial + (initial * working.rate_of_return) + working.contribution;
      
      printf("Age %3d month %2d you have $%.2lf\n", i,x,savings);
              
      initial=savings;
    }
  }

  //_________________________________

  f=y+retired.months/12;

  
  
  savings= initial + (initial * working.rate_of_return) + working.contribution;
  initial=savings;
  printf("Age %3d month %2d you have $%.2lf\n",y+1,p,savings);
  for(int z=1;z<12;z++ ){
    
    savings= initial + (initial * retired.rate_of_return) + retired.contribution;
    printf("Age %3d month %2d you have $%.2lf\n", y+1,z,savings);
            
    initial=savings;
  }
  
  for(int j=y+2;f>=j;j++){
    //savings= initial +(initial*working.rate_of_return)+ working.contribution;
    for(int z=0;z<12;z++ ){
      
      savings= initial + (initial * retired.rate_of_return) + retired.contribution;
      
      printf("Age %3d month %2d you have $%.2lf\n", j,z,savings);
              
      initial=savings;
    }

  }
}
int main(void){
  
  int init_months=327;
  double init_savings=21345;
  retire_info working;
  retire_info retired;
  
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=0.00375;
  
  retired.months=384;
  retired.contribution= -4000;
  retired.rate_of_return=(0.01/12);
  
  retirement(init_months,init_savings,working,retired);
  
  return 0;
  
}

    
