// Place your interface here

// print_board(board) gets a char array with a length of 64
// prints the given array
// requires : array length 64
void print_board(const char board[64]);
  
// same_cdr(a, b) gets two positions a and b returns
// true if a and b in same row or in same column or
// in same diagonal else returns false
bool same_cdr(const int a, const int b);
  
// can_capture_king(board) gets a char array with a length of
// 64 checks whether the king is in the position of possible queen
// moves or not returns true if it is else returns false  
// requires : array length 64
bool can_capture_king(const char board[64]);

// is_checkmate(board) gets a char array length of 64 returns true
// if it's a checkmate returns false if it's otherwise
// requires : array length 64
bool is_checkmate(const char board[64]);