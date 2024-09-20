#include <iostream>
#include <cstring>

using namespace std;

class Method {
public:

};

class Board {
public:
  char board[3][3];
  void printBoard();
  bool valid(char input[]);
};

int main() {
  cout << endl;
  Board board;
  board.printBoard();
  char input[3];
  do {
    cout << "enter a valid input" << endl;
    cin >> input;
    cout << input << endl;
  } while (board.valid(input) == false);
  cout << input << " is a valid input" << endl;
  
  cout << "bye" << endl;
  return 0;
}
/*
void Board::printBoard(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j] = ' ';
      cout << i << ',' << j << ":  " << char(board[i][j]) << endl;
    }
    cout << endl;
  }
}
*/

void Board::printBoard(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j] = 'X';
      cout << board[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;
}

bool Board::valid(char input[]){
  if (strlen(input) == 2){
    if (input[0] == 'a' || input[0] == 'b' || input[0] == 'c'){
      if (input[1] == '1' || input[1] == '2' || input[1] == '3'){
	return true;
      } else {
	return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }
}
