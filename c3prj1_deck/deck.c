#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "deck.h"

void print_hand(deck_t * hand){
   for(size_t i=0; i<hand->n_cards ; i++){ 
      print_card(*hand->cards[i]);
      printf("  "); 
     }
}

int deck_contains(deck_t * d, card_t c) {

 for(size_t i=0; i<d->n_cards; i++){
    if(d->cards[i]->value == c.value && d->cards[i]->suit == c.suit){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  card_t *temp;
  int randVar;
  //  srand(time(NULL));
  for(size_t i = 0; i<d->n_cards; i++){
    randVar= rand()%d->n_cards;
    temp = d->cards[i];
    d->cards[i] = d->cards[randVar];
    d->cards[randVar] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  card_t temp;
  for(size_t i=0; i< d->n_cards; i++){
      temp.value = d->cards[i]->value;
      temp.suit = d->cards[i]->suit;
      assert_card_valid(temp);
      assert(deck_contains(d, temp) == 1);
    }
}

//***************************************************************************//

void add_card_to(deck_t * deck, card_t c){

  card_t * temp = malloc(sizeof(*temp));
  //temp->value = c.value;
  //temp->suit = c.suit;
  *temp = c;
  deck->cards = realloc(deck->cards, (deck->n_cards + 1) * sizeof(*deck->cards));
  //deck->cards[deck->n_cards] = NULL;
  deck->cards[deck->n_cards] = temp;
  deck->n_cards++;
 
}

card_t * add_empty_card(deck_t * deck){
  card_t c = {0,
	     NUM_SUITS};
  add_card_to(deck,c);
  return deck->cards[deck->n_cards - 1];
  
}

deck_t * make_deck_exclude(deck_t * excluded_cards){
  
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = NULL;
  deck->n_cards = 0;
   for(unsigned i = 0; i < 52; i++){
     card_t c = card_from_num(i);
     int x = deck_contains(excluded_cards, c);
     if(x == 0){       
        add_card_to(deck, c);
     }
  }
  return deck;
}

deck_t *  build_remaining_deck(deck_t ** hands, size_t n_hands){

  deck_t * deck_ex = malloc(sizeof(*deck_ex));
  deck_t * deck = NULL;
  deck_ex->cards = NULL;
  deck_ex->n_cards = 0;
  for(size_t i =0; i<n_hands;i++){
    for(size_t j=0; j<hands[i]->n_cards; j++){
      add_card_to(deck_ex, *(hands[i]->cards[j]));
    }
  }  
  deck = make_deck_exclude(deck_ex);    
  free_deck(deck_ex);
  return deck;
  }

void free_deck(deck_t * deck){
  for(size_t i = 0; i < deck->n_cards; i++){
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}

