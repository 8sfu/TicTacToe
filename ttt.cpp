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
  bool checkWin(char c);
};

int main() {
  cout << endl;
  bool game = true;
  int xwin = 0;
  int owin = 0;
  char replayChar = ' ';
  while(game){
    Board board;
    board.printBoard();
    char input[80];
    bool xturn;
    int turns = 9;
    cout << "this is tictactoe. format your inputs like 'a2'. letter is row, and numb\
er is column. x goes first." << endl;

    for(int i = 0; i < turns; i++) {
      do{
	cout << "enter a valid input" << endl;
	cin >> input;
	cout << "input:" << input << endl;
	xturn = !(i%2);
      }while(board.valid(input,xturn) == false); /*keep requesting input until the input is valid*/
      cout << input << " is a valid input" << endl;
      cout << "turn: " << i+1 << endl;
      if(xturn){
	if(board.checkWin('X')){
	  cout << "X wins!" << endl;
	  xwin++;
	  cout << "X wins: " << xwin << endl;
	  cout << "O wins: " << owin << endl;
	  goto finished; //sorry for the disjointed nature of the program, without the break, the program attemps to fill every remaining space in the board.
	}
      } else {
	if(board.checkWin('O')){
	  cout << "O wins!" << endl;
	  owin++;
	  cout << "X wins: " << xwin << endl;
	  cout << "O wins: " << owin << endl;
	  goto finished;
	}
      }
    }
    cout << "tie" << endl;
    cout << "X wins: " << xwin << endl;
    cout << "O wins: " << owin << endl;
    finished:
    game = false;
    cout << "press y to keep playing" << endl;
    cout << endl;
    cin >> replayChar;
    if(replayChar == 'y'){
      game = true;
    }
  }
  cout << "bye" << endl;
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
        //cout << "formatcorrect" << endl;
        if (board[input[0]-97][input[1]-49] == '_'){
          //cout << "nopiecethere" << endl;
          //cout << "placing piece at: " << input[0]-97 << "," << input[1]-49 << endl;
          placePiece(input, isx);
          printBoard();
          cout << endl;
          return true;
        } else {
          //cout << "piecethere" << endl;
          //cout << "not placing piece at: " << input[0]-97 << "," << input[1]-49 << \
endl;
          //cout << endl;
          return false;
        }
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

bool Board::checkWin(char c){
  if((board[0][0] == c) && (board[0][1] == c) && (board[0][2] == c)){
    return true;
  } else if((board[1][0] == c) && (board[1][1] == c) && (board[1][2] == c)){
    return true;
  } else if((board[2][0] == c) && (board[2][1] == c) && (board[2][2] == c)){
    return true;
  } else if((board[0][0] == c) && (board[1][0] == c) && (board[2][0] == c)){
    return true;
  } else if((board[0][1] == c) && (board[1][1] == c) && (board[2][1] == c)){
    return true;
  } else if((board[0][2] == c) && (board[1][2] == c) && (board[2][2] == c)){
    return true;
  } else if((board[0][0] == c) && (board[1][1] == c) && (board[2][2] == c)){
    return true;
  } else if((board[0][2] == c) && (board[1][1] == c) && (board[2][0] == c)){
    return true;
  }
  return false;
}


