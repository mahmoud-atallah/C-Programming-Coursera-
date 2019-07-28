#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void printData(char ** lines, size_t sz){
  for(size_t i=0; i<sz; i++){
    printf("%s", lines[i]);
    free(lines[i]);
  }
}

void getData(FILE *f){
    
    char ** lines = NULL;
    size_t sz = 0;
    char * curr = NULL;
    size_t n = 0;

    while((getline(&curr, &sz,f)) > 0){
      lines = realloc(lines, (n+1) * sizeof(*lines));
      lines[n] = curr;
      curr = NULL;
      n++;
    }
    free(curr);
    sortData(lines, n);
    printData(lines,n);
    free(lines);
}

int main(int argc, char ** argv){
  if(argc == 1){
    getData(stdin);
    getData(stdin);
  }

  else{
    for(int i=1; i<argc; i++){
      FILE *f = fopen(argv[i], "r");
      if(f == NULL){
	perror("Could not open the file\n");
	return EXIT_FAILURE;
      }
      getData(f);
      if(fclose(f) != 0){
	perror("Failed to close the input file\n");
	return EXIT_FAILURE;
      }
    }
  }
  
  return EXIT_SUCCESS;
}
