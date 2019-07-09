#include "checkmate.h"

// print_board(board) gets a char array with a length of 64
// prints the given array
// requires : array length 64
void print_board(const char board[64]){
  for(int i = 1; i <= 64; ++i){
    char c = board[i-1];
    printf("%c", c);
    if(i%8 == 0){
      printf("\n");
    }
  }
}

// abs(x) returns the x value in absolute value
int abs(int x){
  if(x < 0){
    return -x;
  }else{
    return x;
  }
}
   
// same_cdr(a, b) gets two positions a and b returns
// true if a and b in same row or in same column or
// in same diagonal else returns false
bool same_cdr(const int a, const int b){
  int row_a = a / 8;
  int row_b = b / 8;
  int column_a = a % 8;
  int column_b = b % 8;
  int delta_row = abs(row_a - row_b);
  int delta_col = abs(column_a - column_b);
  if(row_a == row_b || column_a == column_b || delta_col == delta_row){
    return true;
  }else{
    return false;
  }
}

// can_capture_king(board) gets a char array with a length of
// 64 checks whether the king is in the position of possible queen
// moves or not returns true if it is else returns false
// requires : array length 64
bool can_capture_king(const char board[64]){
  int pos_queen[64] ={0};
  int queen_count = 0;
  int pos_king = 0;
  for(int i = 0; i < 64; ++i){
    if(board[i] == 'K'){
      pos_king = i;
    }else if(board[i] == 'Q'){
      pos_queen[queen_count] = i;
      queen_count++;
    }
  }
  for(int i = 0; i < queen_count; ++i){
    bool x = same_cdr(pos_king, pos_queen[queen_count]);
    if(x == true){
      return true;
    }
  }
    return false;
}

// generate(possible, board, old, pos) gets a two char arrays and
// two integers old for the old position of the king and pos for the 
// next possible move of the king. Generates a new board by mutating 
// the possible 
// effects: possible array mutates
void generate(char possible[64],const char board[64],const int old, const int pos){
  for(int i = 0; i < 64; ++i){
    possible[i] = board[i];
  }
  if(possible[pos] != 'Q'){
    possible[old] = '*';
    possible[pos] = 'K';
  }
}

// is_checkmate(board) gets a char array length of 64 returns true
// if it's a checkmate returns false if it's otherwise
// requires : array length 64
bool is_checkmate(const char board[64]){
  
  int pos_real_king = 0;
  for(int i = 0; i < 64; ++i){
    if(board[i] == 'K'){
      pos_real_king = i;
    }
  }
  int row_king = pos_real_king / 8;
  int column_king = pos_real_king % 8;
  int pos_king[9] = {0};
  int king_possible = 0;
  for(int i = -1; i <= 1; ++i){
    for(int j = -1; j <= 1; j++){
      int pos = (row_king + i) * 8 + (column_king + j);
      if((row_king + i) >= 0 && (column_king + j) >= 0){
        pos_king[king_possible] = pos;
        king_possible++;
      }
    }
  }
  for(int i = 0; i < king_possible; ++i){
    char possible[64] = {0};
    generate(possible, board, pos_real_king, pos_king[i]);
    bool x = can_capture_king(possible);
    if(x == false){
      return false;
    }
  }
    return true;
}


