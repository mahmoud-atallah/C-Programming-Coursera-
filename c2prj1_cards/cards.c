#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >=2);
  assert(c.value <=VALUE_ACE);
  assert(c.suit >=SPADES);
  assert(c.suit <=CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  char *str = "STRAIGHT_FLUSH";
  switch(r){
    
  case STRAIGHT_FLUSH: str= "STRAIGHT_FLUSH";
    break;
  case FOUR_OF_A_KIND :str= "FOUR_OF_A_KIND";
    break;
  case FULL_HOUSE:str="FULL_HOUSE";
    break;
  case FLUSH:str="FLUSH";
    break;
  case STRAIGHT:str= "STRAIGHT";
    break;
  case THREE_OF_A_KIND:str= "THREE_OF_A_KIND";
    break;
  case TWO_PAIR:str="TWO_PAIR";
    break;
  case PAIR:str="PAIR";
    break;
  case NOTHING:str="NOTHING";
    break;
  }
  return str;

}
char value_letter(card_t c) {
  char x = '0';
  card_t c1;
  c1.value = c.value;
  switch(c1.value){
  case(2):x='0'+2;
    break;
  case(3):x='0'+3;
    break;
  case(4):x='0'+4;
    break;
  case(5):x='0'+5;
    break;
  case(6):x='0'+6;
    break;
  case(7):x='0'+7;
    break;
  case(8):x='0'+8;
    break;
  case(9):x='0'+9;
    break;
  case(10):x='0';
    break;
  case(VALUE_JACK):x='J';
    break;
  case(VALUE_QUEEN):x='Q';
    break;
  case(VALUE_KING):x='K';
    break;
  case(VALUE_ACE):x='A';
    break;
  default:
    break;
  }
  return x;
}
char suit_letter(card_t c) {
  char x='0';
  card_t c1;
  c1.value = c.value;
  c1.suit = c.suit;
  switch(c1.suit){
  case SPADES:  x='s';
    break;
  case HEARTS :x='h';
    break;
  case DIAMONDS: x='d';
    break;
  case CLUBS: x='c';
    break;
  case NUM_SUITS:x='n';
    break;
  default :
    break;
  }
  return x;
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp = {0,'c'}; 
  /*if(suit_let == 'h'){
    //temp.suit= '0'+HEARTS;
      }*/
  /*assert(value_let >=2);
  assert(value_let <=VALUE_ACE);
  assert(suit_let >=SPADES);
  assert(suit_let <=CLUBS);
*/  
    switch(suit_let){
    case 's':temp.suit=0;
      break;
    case 'h':temp.suit=1;
      break;
    case 'd':temp.suit=2;
      break;
    case 'c':temp.suit=3;
      break;
      //default: perror("error for suit let");
      // exit(EXIT_FAILURE);
    }
   
    switch(value_let){
    case('2'): temp.value='2'-'0';
      break;
    case('3'): temp.value='3'-'0';
      break;
    case('4'): temp.value='4'-'0';
      break;
    case('5'): temp.value='5'-'0';
      break;
    case('6'): temp.value='6'-'0';
      break;
    case('7'): temp.value= '7'-'0';
      break;
    case('8'): temp.value= '8'-'0';
      break;
    case('9'): temp.value= '9'-'0';
      break;
    case('0'): temp.value=10 ;
      break;
    case('J'): temp.value=11;
      break;
    case('Q'): temp.value=12;
      break;
    case('K'): temp.value=13;
      break;
    case('A'): temp.value= 14;
      break;
      // default: perror("error for suit let");
      // exit(EXIT_FAILURE);*/
    }
   
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  unsigned value = c%13;
  unsigned suit = c/13;
    
  //suit = c/13;
  // value = c%13;
    
  temp.suit= suit;
  temp.value=  value+2;

  return temp;
}
