#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t *c = malloc(sizeof(*c));
  c->counts = NULL;
  c->numCounts = 0;
  c->unknown =0;
  return c;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME55
  int flag = 0;
   one_count_t * oneCount = NULL;
   //oneCount->count=0;
   // oneCount->value=NULL;
   if(name == NULL){
     c->unknown++;
     flag++;
   }
   if(flag == 0){
   for(size_t i = 0; i < c->numCounts; i++){
    if(strcmp(name, c->counts[i]->value) == 0){
      c->counts[i]->count++;
      flag++;
    }
   }
  } 
  if(flag == 0){
    c->counts = realloc(c->counts, (c->numCounts+1)*sizeof(*c->counts));
    oneCount = malloc(sizeof(*oneCount));
    oneCount->value= (char*)name;
    oneCount->count = 1;
    c->counts[c->numCounts] = oneCount;
    c->numCounts++;
    oneCount = NULL;
}
  free(oneCount);
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(size_t i = 0; i < c->numCounts; i++){
    fprintf(outFile, "%s: %zu\n", c->counts[i]->value, c->counts[i]->count);
  }
  if(c->unknown >0){
    fprintf(outFile,"<unknown> : %zu\n",c->unknown);
  }
}

void freeCounts(counts_t * c) {
  
  for(size_t i = 0; i < c->numCounts; i++){
    free(c->counts[i]);
  }
  free(c->counts);
  free(c);
}
