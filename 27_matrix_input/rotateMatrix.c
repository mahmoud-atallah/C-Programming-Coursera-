#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void rotate(char matrix[10][10]){
  int n = 10;
  int x = (n/ 2);
  int y = n - 1;
  char k;
  for (int i = 0; i < x; i++) {
    for (int j = i; j < y - i; j++) {
      k = *(*(matrix+i)+j);
      *(*(matrix+i)+j) = *(*(matrix+(y - j))+i);
      *(*(matrix+(y - j))+i) = *(*(matrix+(y - i))+(y - j));
      *(*(matrix+(y - i))+(y - j)) = *(*(matrix+j)+(y - i));
      *(*(matrix+j)+(y-i))=k;
    }
  }
}

int main(int argc, char **argv){
  char matrix[12][10];
  
  if(argc != 2){
    fprintf(stderr,"Usage: rotate matrix inputFileName\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");

  if(f == NULL){
    perror("Could not open file\n");
    return EXIT_FAILURE;
  }
  int i = 0;
  int c;
      if ((c=fgetc(f)) == EOF){
	fprintf(stderr,"empty file \n");
	return EXIT_FAILURE;
	}
  fseek(f, 0, SEEK_SET);
  
  while(fgets(matrix[i], 12, f) != NULL){
      if(strchr(matrix[i],'\n') == NULL){
	    fprintf(stderr, "line has too much chars\n");
	    return EXIT_FAILURE; 
	  }
      if(strlen(matrix[i]) < 11){
	fprintf(stderr,"short chars in a line\n");
	return EXIT_FAILURE;
      }
      ++i;
  }
  
  if (i != 10){
     	  fprintf(stderr,"too many lines\n");
	  return EXIT_FAILURE;
      } 
         	
     rotate(matrix);
    
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
	fprintf(stdout,"%c",matrix[i][j]);
      }
      fprintf(stdout,"\n");
    }
  if(fclose(f) != 0){
    perror("failed to close the input file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
