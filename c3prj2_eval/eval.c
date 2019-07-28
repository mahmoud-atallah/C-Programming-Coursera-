#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int card_ptr_comp(const void * vp1, const void * vp2){
  const card_t * const * cp1 = vp1;
  const card_t * const * cp2 = vp2;
  int x =(int)(*cp1)->value - (int)(*cp2)->value;
  int y =(int)(*cp1)->suit - (int)(*cp2)->suit;

  if(x > 0){
    return -1;
  }
  else if(x < 0){
      return 1;
    }
  else if(x == 0){
      if(y > 0){
	return -1;
      }
      else if(y < 0){
	return 1;
      }
    }
  return 0;
}

suit_t flush_suit(deck_t * hand) {
  int spades = 0;
  int hearts = 0;
  int diamonds = 0;
  int clubs = 0;
  
  for(size_t i=0; i < hand->n_cards; i++){
  if(hand->cards[i]->suit == SPADES){
    spades++;
  }
  else if(hand->cards[i]->suit == HEARTS){
    hearts++;
  }
  else if(hand->cards[i]->suit == DIAMONDS){
    diamonds++;
  }
  else if(hand->cards[i]->suit == CLUBS){
    clubs++;
  }
  }
  
  if(spades >= 5 ){
    return SPADES;
  }
  else if(hearts >= 5 ){
    return HEARTS;
  }
  else if(diamonds >= 5 ){
    return DIAMONDS;
  }
  else if(clubs >= 5 ){
    return CLUBS;
  }
  return NUM_SUITS;
}

unsigned get_largest_element(unsigned * arr, size_t n) {
  unsigned largest=arr[0];
  for(size_t i=0; i<n; i++){
    if(arr[i] > largest){
      largest = arr[i];
    }
  }
  return largest;
}

size_t get_match_index(unsigned * match_counts, size_t n,unsigned n_of_akind){
   size_t idx = 0;
  for(size_t i=0; i<n; i++){
    if(match_counts[i] == n_of_akind){
      idx = i;
      break;
    }
  }
  return idx;
}

ssize_t  find_secondary_pair(deck_t * hand,
			     unsigned * match_counts,
			     size_t match_idx) {
  
  //size_t index = match_idx + match_counts[match_idx];
  for(size_t i = 0; i < hand->n_cards; i++){
    if((match_counts[i] > 1) && (hand->cards[match_idx]->value != hand->cards[i]->value)){
      return i;
      
    }
  }
  return -1;
  
}

int is_straight_at(deck_t *hand, size_t index, suit_t fs){
  int flag = 0;
  int flag1 = 0;
  int flag2 = 0;
  int flag3 = 0;
    if(fs == NUM_SUITS){
    for(size_t i = 0; i < hand->n_cards-index-1 ; i++){
      if((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 0){
	continue;
      }
      else if((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 1){
        flag++;
      }
      else if((hand->cards[index+i]->value - hand->cards[index+i+1]->value) > 1){
	break;
      }
    }
    }
    unsigned count = 5;
    if((VALUE_ACE == hand->cards[index]->value) && ((fs == NUM_SUITS) || (hand->cards[index]->suit == fs))){       
      
       for(size_t i = index+1; i < hand->n_cards-index; i++){
	//if(((hand->cards[i]->value == 5)|| (hand->cards[i]->value == 4) || (hand->cards[i]->value == 3) || (hand->cards[i]->value == 2)) && (x < hand->cards[i-1]->value)) {

	 if((hand->cards[i]->value == count) && (count > 1) && ((fs == NUM_SUITS) || (hand->cards[i]->suit == fs))){
	   flag1++;
	   count--;
	 }
	 }
     }         
     
  
    if((fs == SPADES) || (fs == HEARTS) || (fs == CLUBS)){
    //    if(fs == SPADES){
	    //  for(size_t i = 0; i < hand->n_cards-index-1 ; i++){
      if(hand->cards[index]->suit != fs){
	//break;
	return 0;
      }
      unsigned count2 = hand->cards[index]->value;
      for(size_t i = 0; i < hand->n_cards-index-1;i++){
	if(hand->cards[index+i]->value == count && count > 1 && hand->cards[index+i]->suit ==fs){
	  flag2++;
	  count2--;
	}
      }
    }

	/*    if((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 0) {
	continue;
      }
      if((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 1){
	if((hand->cards[index+i]->suit == fs)&&(hand->cards[index+i+1]->suit == fs)){
	  flag2++;
	}
	else if((hand->cards[index+i+1]->value == hand->cards[index+i+2]->value) && (hand->cards[index+i+2]->suit == fs)){
	  flag2++;
	}
      }
      else if(((hand->cards[index+i]->value - hand->cards[index+i+1]->value) > 1)&&((hand->cards[index+i]->suit == fs)&&(hand->cards[index+i+1]->suit == fs))) {
	break;
      }
    }
    }
*/
    
    /*    if(fs == HEARTS){
      for(size_t i = 0; i < hand->n_cards-index-1 ; i++){
	if(hand->cards[index]->suit != fs){
	  break;
	  //  return 0;
	}
	if((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 0){
	  if((hand->cards[index+i]->value == hand->cards[index+i+1]->value) && (hand->cards[index+i]->suit == fs)){
	    flag2++;
	  }
	  else{
	    continue;
	  }
	}
	if((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 1){
	  if((hand->cards[index+i]->suit == fs)&&(hand->cards[index+i+1]->suit == fs)){
	    flag2++;
	  }
		    
	else if((hand->cards[index+i]->value == hand->cards[index+i-1]->value) && (hand->cards[index+i-1]->suit == fs)){
	  flag2++;
	}
      }
      else if(((hand->cards[index+i]->value - hand->cards[index+i+1]->value) > 1)&&((hand->cards[index+i]->suit == fs)&&(hand->cards[index+i+1]->suit == fs))) {
	break;
      }
    }
    */
    if(fs == DIAMONDS){
      for(size_t i = 0; i < hand->n_cards-index-1 ; i++){
	if(hand->cards[index]->suit != fs){
	  break;
	}
	if((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 0) {
	  continue;
	}
        if(((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 1)&&((hand->cards[index+i]->suit == fs)&&(hand->cards[index+i+1]->suit == fs))){
	  flag2++;
        }
	else if(((hand->cards[index+i]->value - hand->cards[index+i+1]->value) > 1)&&((hand->cards[index+i]->suit == fs)&&(hand->cards[index+i+1]->suit == fs))) {
	  break;
	}
      }
      }
    
    /*    if(fs == CLUBS){
      for(size_t i = 0; i < hand->n_cards-index-1 ; i++){
	if(hand->cards[index]->suit != fs){
	  break;
	}
	if((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 0) {
	  continue;
	}
	if(((hand->cards[index+i]->value - hand->cards[index+i+1]->value) == 1)&&((hand->cards[index+i]->suit == fs)&&(hand->cards[index+i+1]->suit == fs))){
          flag2++;
        }
	else if(((hand->cards[index+i]->value - hand->cards[index+i+1]->value) > 1)&&((hand->cards[index+i]->suit == fs)&&(hand->cards[index+i+1]->suit == fs))) {
	  break;
	}
      }
    }

    */
  
  if((flag >= 4)|| (flag2 >= 4) || (flag3 >= 4)){
    return 1;
  }
   if((flag1 == 4) && (VALUE_ACE == hand->cards[index]->value)){
  return -1;
  }
  return 0;  
}

hand_eval_t build_hand_from_match(deck_t * hand,
				  unsigned n,
				  hand_ranking_t what,
				  size_t idx) {


   hand_eval_t ans ={ what,
  		       {NULL,NULL,NULL,NULL,NULL}};

  
  if(n==3){
  for(size_t i=0; i<n; i++){
    ans.cards[i] = hand->cards[i+idx];
  }
     if(idx == 0){
       ans.cards[3] = hand->cards[3];
       ans.cards[4] = hand->cards[4];
     }
     else if(idx == 1){
       ans.cards[3] = hand->cards[0];
       ans.cards[4] = hand->cards[4];
     }
     else if(idx >= 2){
       ans.cards[3] = hand->cards[0];
       ans.cards[4] = hand->cards[1];
     }
  }
 else if(n == 4){
    for(size_t i = 0; i < n; i++){
      ans.cards[i] = hand->cards[i+idx];
    }
    if(idx == 0){
      ans.cards[4] = hand->cards[4];
    }
    else if(idx >= 1){
      ans.cards[4] = hand->cards[0];
    }
    
    }
 else if(n==2){
    for(size_t i = 0; i < n; i++){
      ans.cards[i] = hand->cards[i+idx];
    }
    if(idx == 0){
      ans.cards[2] = hand->cards[2];
      ans.cards[3] = hand->cards[3];
      ans.cards[4] = hand->cards[4];
    }
   else if(idx == 1){
      ans.cards[2] = hand->cards[0];
      ans.cards[3] = hand->cards[3];
      ans.cards[4] = hand->cards[4];
    }
   else if(idx == 2 ){
      ans.cards[2] = hand->cards[0];
      ans.cards[3] = hand->cards[1];
      ans.cards[4] = hand->cards[4];
    }
 else if(idx > 2){
      ans.cards[2] = hand->cards[0];
      ans.cards[3] = hand->cards[1];
      ans.cards[4] = hand->cards[2];
    }
    }
    if(n == 0){
    
     ans.cards[0] = hand->cards[0];
              
         if(idx == 0){
      ans.cards[1] = hand->cards[1];
      ans.cards[2] = hand->cards[2];
      ans.cards[3] = hand->cards[3];
      ans.cards[4] = hand->cards[4];
      }
  
   else if(idx == 1){
      ans.cards[1] = hand->cards[0];
      ans.cards[2] = hand->cards[2];
      ans.cards[3] = hand->cards[3];
      ans.cards[4] = hand->cards[4];
    }
   else if(idx == 2){
      ans.cards[1] = hand->cards[0];
      ans.cards[2] = hand->cards[1];
      ans.cards[3] = hand->cards[3];
      ans.cards[4] = hand->cards[4];
    }
   else if(idx == 3){
      ans.cards[1] = hand->cards[0];
      ans.cards[2] = hand->cards[1];
      ans.cards[3] = hand->cards[2];
      ans.cards[4] = hand->cards[4];
    }
   else if(idx == 4){
      ans.cards[1] = hand->cards[0];
      ans.cards[2] = hand->cards[1];
      ans.cards[3] = hand->cards[2];
      ans.cards[4] = hand->cards[3];
    }
    else if(idx > 4){
	ans.cards[1] = hand->cards[0];
	ans.cards[2] = hand->cards[1];
	ans.cards[3] = hand->cards[2];
	ans.cards[4] = hand->cards[3];
	}
	}
  return ans;
}
  

int compare_hands(deck_t * hand1, deck_t * hand2) {

  hand_eval_t h1;
  hand_eval_t h2;
  
  qsort(hand1->cards, hand1->n_cards, sizeof(hand1->cards[0] ), card_ptr_comp);
  qsort(hand2->cards, hand2->n_cards, sizeof(hand2->cards[0] ), card_ptr_comp);
  
  h1=evaluate_hand(hand1);
  h2=evaluate_hand(hand2);
  
  if(h1.ranking != h2.ranking){
    if(h1.ranking < h2.ranking){
      return 1;
    }
    else if(h1.ranking > h2.ranking){
      return -1;
  }
  }
  if(h1.ranking == h2.ranking){
    for(size_t i=0; i<5; i++){
      /*   if((h1.cards[i])->value  == (h2.cards[i])->value){
	
	continue;
	}*/
      if((h1.cards[i])->value  >  (h2.cards[i])->value){
	return 1; 
      }
      else if((h1.cards[i])->value < (h2.cards[i])->value){
	return -1;
    
	}
	
    }
  }
  return 0;
}



//You will write this function in Course 4.
//For now, we leave a prototype (and provide our
//implementation in eval-c4.o) so that the
//other functions we have provided can make
//use of get_match_counts.
unsigned * get_match_counts(deck_t * hand){
  int count = 0;
 unsigned int * matchCounts = malloc(hand->n_cards * sizeof(*matchCounts));
  for(int i = 0; i < hand->n_cards; i++){
    for(int j = 0; j < hand->n_cards; j++){
      if(hand->cards[i]->value == hand->cards[j]->value){
	  count++;
	}
    }
    matchCounts[i] = count;
    count = 0;
  }
  return matchCounts;
}
	
// We provide the below functions.  You do NOT need to modify them
// In fact, you should not modify them!


//This function copies a straight starting at index "ind" from deck "from".
//This copies "count" cards (typically 5).
//into the card array "to"
//if "fs" is NUM_SUITS, then suits are ignored.
//if "fs" is any other value, a straight flush (of that suit) is copied.
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if ((from->cards[ind]->value == nextv) &&
      (fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
    }
}



//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)
// in "hand".  It calls the student's is_straight_at for each possible
// index to do the work of detecting the straight.
// If one is found, copy_straight is used to copy the cards into
// "ans".
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    if (x != 0){
      if (x < 0) { //ace low straight
	assert(hand->cards[i]->value == VALUE_ACE &&
	       (fs == NUM_SUITS || hand->cards[i]->suit == fs));
	ans->cards[4] = hand->cards[i];
	size_t cpind = i+1;
	while(hand->cards[cpind]->value != 5 ||
	      !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
	  cpind++;
	  assert(cpind < hand->n_cards);
	}
	copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
	copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.
//This function is longer than we generally like to make functions,
//and is thus not so great for readability :(
hand_eval_t evaluate_hand(deck_t * hand) {
  suit_t fs = flush_suit(hand);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    if(find_straight(hand, fs, &ans)) {
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  unsigned * match_counts = get_match_counts(hand);
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  if (n_of_a_kind == 4) { //4 of a kind
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
	ans.cards[copy_idx] = hand->cards[i];
	copy_idx++;
	if (copy_idx >=5){
	  break;
	}
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01
      //if other_pair_idx > 2, then, e.g. A A K Q Q
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q
      ans.cards[4] = hand->cards[4]; 
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}
