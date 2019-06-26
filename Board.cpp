#include "Board.h"
#include "Referee.h"
#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Board::Board()
{
    //ctor
    score1=0, //initialize scores
    score2=0;
}

Board::~Board()
{
    //dtor
}

void Board::startGame()
{
    Player play; //player object
    startBoard(p1, p2); //setup game
    printBoard(p1, p2);
    play.playGame(p1,p2,score1,score2);
}

string Board::gameBoard(int x, int y, int p1[][8], int p2[][8])
{
    string board = " ";
    if (p1[x][y] == 5)
    {
        board = "o";
    }
    else if (p1[x][y]==9)
    {
        board = "O";
    }
    if (p2[x][y] == 5)
    {
       board = "x";
    }
    else if (p2[x][y] == 9)
    {
        board = "X";
    }
    else if (p1[x][y]==0)
    {
        board=" ";
    }

    return board;
}

//setup values for game board
void Board::startBoard(int p1[][8], int p2[][8])
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            p1[i][j] = 0;
            p2[i][j] = 0;
        }
    p1[6][4] = 9; //player1 Duke, assigned same value as Queen in Chess
    p1[7][0] = 5; //piece assigned same value as Rook in Chess
    p1[7][1] = 5;
    p1[7][2] = 5;
    p1[7][3] = 5;
    p1[7][4] = 5;
    p1[7][5] = 5;
    p1[7][6] = 5;
    p1[7][7] = 5;

    p2[1][3] = 9; //player2 Duke
    p2[0][0] = 5;
    p2[0][1] = 5;
    p2[0][2] = 5;
    p2[0][3] = 5;
    p2[0][4] = 5;
    p2[0][5] = 5;
    p2[0][6] = 5;
    p2[0][7] = 5;
}


//print board according to p1 and p2 arrays indicating positions on the board
void Board::printBoard(int p1[][8], int p2[][8])
{
    cout<<"   "<<0<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<endl
      <<"  -----------------"<<endl;

  cout<<"a"<<" |"<<gameBoard(0,0,p1,p2)<<"|"<<gameBoard(0,1,p1,p2)<<"|"<<gameBoard(0,2,p1,p2)<<"|"<<gameBoard(0,3,p1,p2)<<"|"<<gameBoard(0,4,p1,p2)<<"|"<<gameBoard(0,5,p1,p2)<<"|"<<gameBoard(0,6,p1,p2)<<"|"<<gameBoard(0,7,p1,p2)<<"|"<<endl
  <<"  -----------------"<<endl;

  cout<<"b"<<" |"<<gameBoard(1,0,p1,p2)<<"|"<<gameBoard(1,1,p1,p2)<<"|"<<gameBoard(1,2,p1,p2)<<"|"<<gameBoard(1,3,p1,p2)<<"|"<<gameBoard(1,4,p1,p2)<<"|"<<gameBoard(1,5,p1,p2)<<"|"<<gameBoard(1,6,p1,p2)<<"|"<<gameBoard(1,7,p1,p2)<<"|"<<endl
      <<"  -----------------"<<endl;

  cout<<"c"<<" |"<<gameBoard(2,0,p1,p2)<<"|"<<gameBoard(2,1,p1,p2)<<"|"<<gameBoard(2,2,p1,p2)<<"|"<<gameBoard(2,3,p1,p2)<<"|"<<gameBoard(2,4,p1,p2)<<"|"<<gameBoard(2,5,p1,p2)<<"|"<<gameBoard(2,6,p1,p2)<<"|"<<gameBoard(2,7,p1,p2)<<"|"<<endl
      <<"  -----------------"<<endl;

  cout<<"d"<<" |"<<gameBoard(3,0,p1,p2)<<"|"<<gameBoard(3,1,p1,p2)<<"|"<<gameBoard(3,2,p1,p2)<<"|"<<gameBoard(3,3,p1,p2)<<"|"<<gameBoard(3,4,p1,p2)<<"|"<<gameBoard(3,5,p1,p2)<<"|"<<gameBoard(3,6,p1,p2)<<"|"<<gameBoard(3,7,p1,p2)<<"|"<<endl
             <<"  -----------------"<<endl;

  cout<<"e"<<" |"<<gameBoard(4,0,p1,p2)<<"|"<<gameBoard(4,1,p1,p2)<<"|"<<gameBoard(4,2,p1,p2)<<"|"<<gameBoard(4,3,p1,p2)<<"|"<<gameBoard(4,4,p1,p2)<<"|"<<gameBoard(4,5,p1,p2)<<"|"<<gameBoard(4,6,p1,p2)<<"|"<<gameBoard(4,7,p1,p2)<<"|"<<endl
      <<"  -----------------"<<endl;

  cout<<"f"<<" |"<<gameBoard(5,0,p1,p2)<<"|"<<gameBoard(5,1,p1,p2)<<"|"<<gameBoard(5,2,p1,p2)<<"|"<<gameBoard(5,3,p1,p2)<<"|"<<gameBoard(5,4,p1,p2)<<"|"<<gameBoard(5,5,p1,p2)<<"|"<<gameBoard(5,6,p1,p2)<<"|"<<gameBoard(5,7,p1,p2)<<"|"<<endl
      <<"  -----------------"<<endl;

  cout<<"g"<<" |"<<gameBoard(6,0,p1,p2)<<"|"<<gameBoard(6,1,p1,p2)<<"|"<<gameBoard(6,2,p1,p2)<<"|"<<gameBoard(6,3,p1,p2)<<"|"<<gameBoard(6,4,p1,p2)<<"|"<<gameBoard(6,5,p1,p2)<<"|"<<gameBoard(6,6,p1,p2)<<"|"<<gameBoard(6,7,p1,p2)<<"|"<<endl
      <<"  -----------------"<<endl;

  cout<<"h"<<" |"<<gameBoard(7,0,p1,p2)<<"|"<<gameBoard(7,1,p1,p2)<<"|"<<gameBoard(7,2,p1,p2)<<"|"<<gameBoard(7,3,p1,p2)<<"|"<<gameBoard(7,4,p1,p2)<<"|"<<gameBoard(7,5,p1,p2)<<"|"<<gameBoard(7,6,p1,p2)<<"|"<<gameBoard(7,7,p1,p2)<<"|"<<endl
      <<"  -----------------"<<endl<<endl;

}
