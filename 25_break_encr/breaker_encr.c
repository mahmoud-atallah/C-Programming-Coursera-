#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int  arrayMax(int * array, int n) {
  int max = 0;
  for(size_t i=0 ;i<n ; i++){
      if(array[i] > array[max]){
        max = i;
      }
    }
  return max;
}
int frequency_counts(FILE *f){
  int key;
  int c;
  int max;
  int arr[26]={0};
  char alphabit[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  while((c=fgetc(f)) != EOF){
    if(isalpha(c)){
      c -= 'a';
      arr[c]++;
    }
  }
    max = arrayMax(arr, 26);
    if(alphabit[max] >= 'e'){
      key = alphabit[max] - 'e';
    }
    else{
      key = 26 + (alphabit[max] - 'e');
    }

    return key;
}

int main(int argc, char ** argv) {
  int key;
  if (argc != 2) {    
    fprintf(stderr,"Usage: encrypt key inputFileName\n");    
    return EXIT_FAILURE;  
  }  
  
  FILE * f = fopen(argv[1], "r");  
  if (f == NULL) {    
    perror("Could not open file");    
    return EXIT_FAILURE;  
  }
  
  key = frequency_counts(f);

  if((key >= 0) && (key < 26)){
    printf("%d\n", key);
  }
  else{
    fprintf(stderr,"Usage: encrypt key is error");
    return EXIT_FAILURE;
  }
  
  if (fclose(f) != 0) {    
    perror("Failed to close the input file!");    
    return EXIT_FAILURE;  
  }  
  return EXIT_SUCCESS;
}
