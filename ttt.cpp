#include <iostream>
#include <cstring>

using namespace std;

class Method {
public:

};

class Board {
public:
  char board[3][3] = {{'_','_','_'},{'_','_','_'},{'_','_','_'}};
  void printBoard();
  bool valid(char input[], bool isx);
  void placePiece(char input[], bool isx);
};

int main() {
  cout << endl;
  Board board;
  board.printBoard();
  char input[3];
  int turns = 9;
  bool xturn = true;
  cout << "this is tictactoe. format your inputs like 'a2'. letter is row, and number is column. x goes first." << endl;
  for(int i = 0; i < turns; i++) {
    do{
      cout << "enter a valid input" << endl;
      cin >> input;
      //  cout << input << endl;
      xturn = !(i%2);
    }while(board.valid(input, xturn) == false); /*keep requesting input until the input is valid*/
    //cout << input << " is a valid input" << endl;
    //cout << "xturn is: " << xturn << endl;
  }
  cout << "game over, bye" << endl;
  return 0;
}

void Board::printBoard(){ /*prints a visual representation of the board*/
  cout << "   1  2  3  " << endl;
  for(int i = 0; i < 3; i++){
    cout << (char)(i+97) << "  ";
    for(int j = 0; j < 3; j++){
      cout << board[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;
}

bool Board::valid(char input[], bool isx){ /*input should be formatted a2, */
  if (strlen(input) == 2){
    if (input[0] == 'a' || input[0] == 'b' || input[0] == 'c'){
      if (input[1] == '1' || input[1] == '2' || input[1] == '3'){
	//if (board[input[0]-97][input[1]-49] == '_'){
	  placePiece(input, isx);
	  printBoard();
	  return true;
	  //} else {
	  //return false;
	  //}
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

void Board::placePiece(char input[], bool isx){
  if(isx){
    board[input[0]-97][input[1]-49] = 'X'; /*converts input to two ascii numbers
    and then converts those numbers to grid coordinates*/
  } else {
    board[input[0]-97][input[1]-49] = 'O';
  }
  //cout << "Placed piece at: " << input[0]-97 << "," << input[1]-49 << endl;
}
