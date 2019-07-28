#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include <ctype.h>

deck_t * hand_from_string(const char * str, future_cards_t * fc){
  
  int val;
  card_t *temp;
  card_t c;
  char *token;
  char  *t;
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = NULL;
  deck->n_cards = 0;
  t =strdup(str);
  token = strtok(t, " ");
  while(token != NULL){
    if(token[0] == '?'){
      temp = add_empty_card(deck);
      val = atoi(&token[1]);
      add_future_card(fc, val, temp);
	}
    else{
	c = card_from_letters(token[0], token[1]);
	if(c.value >= 2 && c.value <= VALUE_ACE && c.suit >=SPADES && c.suit <= CLUBS){ 
	  add_card_to(deck, c);
	}
    }
	token = strtok(NULL, " ");
  }
     if(deck->n_cards < 5){
    perror("too few cards in hand");
    fprintf(stderr,"error");
    return NULL;
    }
     free(t);
     return deck;  
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
 
  deck_t **deck = NULL;
  char * curr = NULL;
  char *cc;
  size_t sz;
  size_t i = 0;
  fc->decks = NULL;
  fc->n_decks=0;
  int c;
  if((c=fgetc(f)) == EOF){
    perror("error");
    return NULL;
  }
  fseek(f, 0,SEEK_SET);

  while(getline(&curr, &sz, f) >= 0){
    cc = strdup(curr);
    deck = realloc(deck, (i + 1) * sizeof(*deck));
    deck[i] = hand_from_string(cc, fc);
    //    curr = NULL;
    i++;
    *n_hands = i;
    free(cc);
  }
 
  free(curr);
 
  return deck;
}
