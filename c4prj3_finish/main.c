#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

int main(int argc, char ** argv) {
  //YOUR CODE GOES HERE
  size_t n_hands;
  deck_t ** hands;
  deck_t * d;
  future_cards_t *fc = malloc(sizeof(*fc));
  int num_trails;
  unsigned result;
  int tie = 0;
  
  if(argc == 2){
    num_trails = 10000;
  }
  if(argc == 3){
    num_trails = atoi(argv[2]);
  }
  if(!(argc == 2 || argc == 3)){
    fprintf(stderr, "Usage, poker InputFileName");
    return EXIT_FAILURE;
  }
      
  FILE *f = fopen(argv[1], "r");
  if(f == NULL){
    perror("Could not open the file");
    return EXIT_FAILURE;
  }
  int c;
  if((c = fgetc(f)) == EOF){
    fprintf(stderr, "ERROR!!! empty file");
    return EXIT_FAILURE;
  }
  fseek(f, 0, SEEK_SET);
  
  hands = read_input(f, &n_hands, fc);

  d = build_remaining_deck(hands, n_hands);
  
  unsigned * counts = malloc((n_hands+1) * sizeof(*counts));
  for(int n = 0; n <= n_hands; n++){
    counts[n] = 0;
  }
  int index = 0;
  int flag = 0;
  for(int i = 0; i < num_trails; i++){
    shuffle(d);
    future_cards_from_deck(d, fc);
    index = 0;
    flag = 0;
    tie = 0;
    for(size_t i = 1; i < n_hands; i++){
      result = compare_hands(hands[index], hands[i]);
      if(result == 1){
	if(tie ==1 || (index < i-1)){
	    continue;
	  }
	else{
	index = i-1;
	flag = 0;
      }
      }
      else if (result == -1){
	index = i;
	flag = 0;
	tie = 0;
      }
      
      else if (result == 0){
	tie = 1;
	if ( i < n_hands){
	  flag = 1;
	}
      }
    }
    if (flag == 1){
	counts[n_hands]++;
      }
    else{
    counts[index]++;
  }
  }
    
    float p;
  for(size_t i = 0; i < n_hands; i++){
    p = ((float)counts[i] /(float) num_trails) * 100;
    printf("Hand %zu won %u / %u times (%.2f%%)\n", i, counts[i], num_trails, p);
  }
  printf("And there were %u ties\n", counts[n_hands]);

  //**************************FREEING****************************
  free(counts);
  free_deck(d);  
   
  for(size_t i=0; i < fc->n_decks; i++){
      free(fc->decks[i].cards);
    }
  free(fc->decks);
  free(fc);
  
  for(size_t i = 0; i < n_hands; i++){
      for(size_t j = 0; j < hands[i]->n_cards; j++){
      free(hands[i]->cards[j]);
      }
    free(hands[i]->cards);
    free(hands[i]);
  }
  free(hands);
  
  if(fclose(f) != 0){
    perror("Failes to close the open file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
