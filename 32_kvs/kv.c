#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f= fopen(fname, "r");
  if(f == NULL){
    perror("could not open the file\n");
    return 0;
  }
  int c;
  if((c=fgetc(f)) != EOF){
  kvpair_t *p = NULL;
  char * curr=NULL;
  size_t sz;
  size_t i = 0;
  kvarray_t * arr = malloc(sizeof(*arr));
  arr->pairs = NULL;
  fseek(f, 0, SEEK_SET);  
  while(getline(&curr, &sz, f)>=0){
    p = malloc(sizeof(*p));
    p->key = strtok(curr, "=");
    p->value = strtok(NULL, "\n");
    arr->pairs= realloc(arr->pairs, (i + 1)*sizeof(*arr->pairs));
    arr->pairs[i] = p;
    curr = NULL;
    p = NULL;
    i++;
    arr->numPairs = i;
  }
  free(curr);
  
  free(p);
  if(fclose(f) != 0){
    return 0;
  }
  return arr;
}
  if(fclose(f) !=0){
    return 0;
  }
  else
    return NULL;
}

void freeKVs(kvarray_t * pairs){
  if(pairs != NULL){ 
  for(int i = 0; i < pairs->numPairs; i++){
    free(pairs->pairs[i]->key);
    //free(pairs->pairs[i]->value);
    free(pairs->pairs[i]);
    }

  free(pairs->pairs);
  free(pairs);
  }
}

void printKVs(kvarray_t * pairs) {
  if(pairs != NULL){
  for(int i=0; i< pairs->numPairs; i++){
  printf("key = '%s' value = '%s'\n",pairs->pairs[i]->key, pairs->pairs[i]->value);
  }
}
}
char * lookupValue(kvarray_t * pair, const char * key) {
  //WRITE ME
  if(pair != NULL){
  for(int i =0; i<pair->numPairs;i++){
    if(strcmp(key,pair->pairs[i]->key)==0){
      return  pair->pairs[i]->value;
    }
  }
  }
      return NULL;
}
