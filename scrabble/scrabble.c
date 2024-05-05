#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
void scrabble();

int points(string s){
  short letters = strlen(s);
  int point = 0;
  for(int i = 0; i < letters; i++){
    const char cc = toupper(s[i]);
    if(cc == 'A' || cc == 'E' || cc == 'I' || cc == 'L' || cc == 'N' || cc == 'O' || (cc >= 'R' && cc < 'V')){
      point += 1;
    } else if (cc == 'D' || cc == 'G'){
      point += 2;
    } else if (cc == 'B' || cc == 'C' || cc == 'M' || cc == 'P') {
      point += 3;
    } else if (cc == 'F' || cc == 'H' || cc == 'V' || cc == 'W' || cc == 'Y'){
      point += 4;
    } else if (cc == 'K'){
      point += 5;
    } else if (cc == 'J' || cc == 'X'){
      point += 8;
    } else if (cc == 'Q' || cc == 'Z'){
      point += 10;
    }
  }
  return point;
}

int main(void){
  scrabble();
}

void scrabble(){
  string p1 = get_string("Player 1: ");
  string p2 = get_string("Player 2: ");

  if (points(p1) > points(p2)){
    printf("Player 1 wins!\n");
  } else if (points(p1) < points(p2)){
    printf("Player 2 wins!\n");
  } else{
    printf("Tie!");
  }
}
