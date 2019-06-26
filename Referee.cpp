#include "Referee.h"
#include "Board.h"
#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Referee::Referee()
{
    //ctor
   _score1=0;
   _score2=0;
   capture=true;
   dukecapture=false;

}

Referee::~Referee()
{
    //dtor
}

bool Referee::pieceSelect(std::string playerpiece)
{
    if(playerpiece == " " || playerpiece==" ")
    {
        cout<<"Piece not selected"<<endl;
        return false;
    }

    else
    {
        return true;
    }
}

//piece movement
bool Referee::isValid(int _x, int _y, int moveto_X, int moveto_Y, int p1[][8], int p2[][8], string op_Rook, string op_Duke, string playRook, string playDuke,bool& val)
{
    Board game;
    if (_x != moveto_X && _y != moveto_Y)
    {
        cout << "Pieces can only move horizontally or vertically"<<endl;
        return false;
    }
    else if (game.gameBoard(moveto_X, moveto_Y, p1, p2) != " ")
    {
        cout << "Piece cannot move to occupied space"<<endl;
        return false;
    }
    else
    {
        return true;
    }

}
void Referee::player1_Moves(int _x, int _y, int moveto_X, int moveto_Y, int p1[][8], int p2[][8], string op_Rook, string op_Duke, string playRook, string playDuke)
{
    Board board;
    if(board.gameBoard(moveto_X,(moveto_Y+1),p1,p2)==op_Rook&&board.gameBoard(moveto_X,(moveto_Y+2),p1,p2)==playRook)
    {
        pieceCaptured(capture);
        p2[moveto_X][moveto_Y+1]=0;
        p1score();

    }
    else if(board.gameBoard(moveto_X,(moveto_Y-1),p1,p2)==op_Rook&&board.gameBoard(moveto_X,(moveto_Y-2),p1,p2)==playRook)
    {
        pieceCaptured(capture);
        p2[moveto_X][moveto_Y-1]=0;
        p1score();
    }

    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+2),moveto_Y,p1,p2)==playRook)
    {
        pieceCaptured(capture);
        p2[moveto_X+1][moveto_Y]=0;
        p1score();
    }
    else if(board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X-2),moveto_Y,p1,p2)==playRook)
    {
        p2[moveto_X-1][moveto_Y]=0;
        p1score();
    }
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook) //trapped in corner
    {
        if (board.gameBoard(7,0,p1,p2)==op_Rook)
        {
            pieceCaptured(capture);
            p2[7][0]=0;
            p1score();
        }
    }
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+1),(moveto_Y-1),p1,p2)==playRook) //trapped in corner
    {
        if (board.gameBoard(7,7,p1,p2)==op_Rook)
        {
            pieceCaptured(capture);
            p2[7][7]=0;
            p1score();
        }
    }
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook) //trapped in corner
    {
        if (board.gameBoard(0,0,p1,p2)==op_Rook)
        {
            pieceCaptured(capture);
            p2[0][0]=0;
            p1score();
        }
    }
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook) //trapped in corner
    {
        if (board.gameBoard(0,7,p1,p2)==op_Rook)
        {
                pieceCaptured(capture);
                p2[0][7]=0;
                p1score();
        }
    }
    else if (board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook)
    {
        pieceCaptured(capture);
        p2[moveto_X-1][moveto_Y]=0;
        p1score();
    }

    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+2),moveto_Y,p1,p2)==playRook)
    {
        pieceCaptured(capture);
        p2[moveto_X+1][moveto_Y]=0;
        p1score();
    }

    ///Duke Capture
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X+2),moveto_Y,p1,p2)==playRook)
    {
        if(board.gameBoard((moveto_X+1),(moveto_Y-1),p1,p2)==playRook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook)
        {
            cout<<"duke captured"<<endl;
            p2[moveto_X+1][moveto_Y]=0;
            _score1=8;
        }
    }

    else if(board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X+2),moveto_Y,p1,p2)==op_Rook)
    {
        if(board.gameBoard((moveto_X+1),(moveto_Y-1),p1,p2)==op_Rook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==op_Rook)
        {
                cout<<"duke captured"<<endl;
                p2[moveto_X+1][moveto_Y]=0;
                _score1=8;
        }
    }

    else if (board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X-2),moveto_Y,p1,p2)==playRook)
    {
            if(board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook&&board.gameBoard((moveto_X-1),(moveto_Y+1),p1,p2)==playRook)
            {
                cout<<"duke captured"<<endl;
                p2[moveto_X-1][moveto_Y]=0;
                _score1=8;
            }
    }
    else if (board.gameBoard(moveto_X,(moveto_Y+1),p1,p2)==op_Duke&&board.gameBoard(moveto_X,(moveto_Y+2),p1,p2)==playRook)
    {
               if(board.gameBoard((moveto_X-1),(moveto_Y+1),p1,p2)==playRook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook)
                {
                    cout<<"duke captured"<<endl;
                    p2[moveto_X][moveto_Y+1]=0;
                    _score1=8;
                }
    }
    else if (board.gameBoard(moveto_X,(moveto_Y-1),p1,p2)==op_Duke&&board.gameBoard(moveto_X,(moveto_Y-2),p1,p2)==playRook)
    {
            if(board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook&&board.gameBoard((moveto_X+1),(moveto_Y-1),p1,p2)==playRook)
            {
                cout<<"duke captured"<<endl;
                p2[moveto_X][moveto_Y-1]=0;
                _score1=8;
            }
    }
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook&&board.gameBoard((moveto_X+2),moveto_Y,p1,p2)==playRook)
    {
        cout<<"duke captured 2"<<endl;
        p2[moveto_X+1][moveto_Y]=0;
        _score1=8;

    }

    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook)
    {
        if(board.gameBoard(7,0,p1,p2)==op_Duke)
        {
            cout<<"duke trapped in corner"<<endl;
            p2[moveto_X+1][moveto_Y]=0;
            _score1=8;
        }
    }
    else if (board.gameBoard(moveto_X,(moveto_Y-1),p1,p2)==op_Duke&&board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook)
    {
        if(board.gameBoard(7,0,p1,p2)==op_Duke)
        {
            cout<<"duke trapped in corner"<<endl;
            p2[moveto_X][moveto_Y-1]=0;
            _score1=8;
        }
    }

    else if (board.gameBoard(moveto_X,(moveto_Y+1),p1,p2)==op_Duke&&board.gameBoard((moveto_X-1),(moveto_Y+1),p1,p2)==playRook)
    {
        if(board.gameBoard(0,7,p1,p2)==op_Duke)
        {
            cout<<"duke trapped in corner"<<endl;
            p2[moveto_X][moveto_Y+1]=0;
            _score1=8;
        }
    }
    else if (board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X-1),(moveto_Y+1),p1,p2)==playRook)
    {
        if(board.gameBoard(0,0,p1,p2)==op_Duke)
        {
            cout<<"duke trapped in corner"<<endl;
            p2[moveto_X-1][moveto_Y]=0;
            _score1=8;
        }
    }

    else if (board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook)
    {
        if(board.gameBoard(0,7,p1,p2)==op_Duke)
        {
            cout<<"duke trapped in corner"<<endl;
            p2[moveto_X-1][moveto_Y]=0;
            _score1=8;
        }
    }

    else if (board.gameBoard(moveto_X,(moveto_Y-1),p1,p2)==op_Duke&&board.gameBoard((moveto_X+1),(moveto_Y-1),p1,p2)==playRook)
    {
        if(board.gameBoard(0,7,p1,p2)==op_Duke)
        {
            cout<<"duke trapped in corner"<<endl;
            p2[moveto_X][moveto_Y-1]=0;
            _score1=8;
        }
    }
    else if (board.gameBoard(moveto_X,(moveto_Y+1),p1,p2)==op_Duke&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook)
    {
        if(board.gameBoard(0,7,p1,p2)==op_Duke)
        {
            cout<<"duke trapped in corner"<<endl;
            p2[moveto_X][moveto_Y+1]=0;
            _score1=8;
        }
    }

    else if (board.gameBoard(moveto_X,(moveto_Y+1),p1,p2)==op_Duke&&board.gameBoard((moveto_X-1),(moveto_Y+1),p1,p2)==playRook)
    {
        if(board.gameBoard(7,7,p1,p2)==op_Duke)
        {
            cout<<"duke trapped in corner"<<endl;
            p2[moveto_X][moveto_Y+1]=0;
            _score1=8;
        }
    }

}
void Referee::player2_Moves(int _x, int _y, int moveto_X, int moveto_Y, int p1[][8], int p2[][8], string op_Rook, string op_Duke, string playRook, string playDuke)
{
    Board board;
     if(board.gameBoard(moveto_X,(moveto_Y+1),p1,p2)==op_Rook&&board.gameBoard(moveto_X,(moveto_Y+2),p1,p2)==playRook)
    {
            pieceCaptured(capture);
            p1[moveto_X][moveto_Y+1]=0;
            p2score();
    }

    else if(board.gameBoard(moveto_X,(moveto_Y-1),p1,p2)==op_Rook&&board.gameBoard(moveto_X,(moveto_Y-2),p1,p2)==playRook)
    {
        pieceCaptured(capture);
        p1[moveto_X][moveto_Y-1]=0;
        p2score();
    }

    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+2),moveto_Y,p1,p2)==playRook)
    {
        pieceCaptured(capture);
        p1[moveto_X+1][moveto_Y]=0;
        p2score();
    }
    else if(board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X-2),moveto_Y,p1,p2)==playRook)
    {
            pieceCaptured(capture);
            p1[moveto_X-1][moveto_Y]=0;
            p2score();
    }
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook) //trapped in corner
    {
        if (board.gameBoard(7,0,p1,p2)==op_Rook)
        {
            pieceCaptured(capture);
            p1[7][0]=0;
            p2score();
        }
    }
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+1),(moveto_Y-1),p1,p2)==playRook)
    {
        if (board.gameBoard(7,7,p1,p2)==op_Rook)
        {
            pieceCaptured(capture);
            p1[7][7]=0;
            p2score();
        }
    }
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook) //trapped in corner
    {
        if (board.gameBoard(0,0,p1,p2)==op_Rook)
        {
            pieceCaptured(capture);
            p1[0][0]=0;
            p2score();
        }
    }
   else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook) //trapped in corner
    {
        if (board.gameBoard(0,7,p1,p2)==op_Rook)
        {
            pieceCaptured(capture);
            p1[0][7]=0;
            p2score();
        }
    }

    else if (board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook)
    {
        pieceCaptured(capture);
        p1[moveto_X-1][moveto_Y]=0;
        p2score();
    }

    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Rook&&board.gameBoard((moveto_X+2),moveto_Y,p1,p2)==playRook)
    {
        pieceCaptured(capture);
        p1[moveto_X+1][moveto_Y]=0;
        p2score();
    }

    ///Duke immobilizing
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X+2),moveto_Y,p1,p2)==playRook)
    {
        if(board.gameBoard((moveto_X+1),(moveto_Y-1),p1,p2)==playRook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook)
        {
            cout<<"duke captured"<<endl;
            p1[moveto_X+1][moveto_Y]=0;
            _score2=8;

        }
    }

    else if (board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X-2),moveto_Y,p1,p2)==playRook)
    {
        if(board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook&&board.gameBoard((moveto_X-1),(moveto_Y+1),p1,p2)==playRook)
        {
            cout<<"duke captured"<<endl;
            p1[moveto_X-1][moveto_Y]=0;
            _score2=8;
        }
    }
    else if (board.gameBoard(moveto_X,(moveto_Y+1),p1,p2)==op_Duke&&board.gameBoard(moveto_X,(moveto_Y+2),p1,p2)==playRook)
    {
        if(board.gameBoard((moveto_X-1),(moveto_Y+1),p1,p2)==playRook&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook)
        {
            cout<<"duke captured"<<endl;
            p1[moveto_X][moveto_Y+1]=0;
            _score2=8;
        }
    }
    else if (board.gameBoard(moveto_X,(moveto_Y-1),p1,p2)==op_Duke&&board.gameBoard(moveto_X,(moveto_Y-2),p1,p2)==playRook)
    {
        if(board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook&&board.gameBoard((moveto_X+1),(moveto_Y-1),p1,p2)==playRook)
        {
            cout<<"duke captured"<<endl;
            p1[moveto_X][moveto_Y-1]=0;
            _score2=8;
        }
    }
    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook&&board.gameBoard((moveto_X+2),moveto_Y,p1,p2)==playRook)
    {
        cout<<"duke captured 2"<<endl;
        p1[moveto_X+1][moveto_Y]=0;
        _score2=8;
    }

    else if (board.gameBoard((moveto_X+1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook)
    {
        cout<<"duke trapped in corner"<<endl;
        p1[moveto_X+1][moveto_Y]=0;
        _score2=8;

    }
    else if (board.gameBoard(moveto_X,(moveto_Y-1),p1,p2)==op_Duke&&board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook)
    {
        cout<<"duke trapped in corner"<<endl;
        p1[moveto_X][moveto_Y-1]=0;
        _score2=8;
    }

    else if (board.gameBoard(moveto_X,(moveto_Y+1),p1,p2)==op_Duke&&board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook)
    {
        cout<<"duke trapped in corner"<<endl;
        p1[moveto_X][moveto_Y+1]=0;
        _score2=8;
    }
    else if (board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X-1),(moveto_Y+1),p1,p2)==playRook)
    {
        cout<<"duke trapped in corner"<<endl;
        p1[moveto_X-1][moveto_Y]=0;
        _score2=8;
    }

    else if (board.gameBoard((moveto_X-1),moveto_Y,p1,p2)==op_Duke&&board.gameBoard((moveto_X-1),(moveto_Y-1),p1,p2)==playRook)
    {
            cout<<"duke trapped in corner"<<endl;
            p1[moveto_X-1][moveto_Y]=0;
            _score2=8;
    }

    else if (board.gameBoard(moveto_X,(moveto_Y-1),p1,p2)==op_Duke&&board.gameBoard((moveto_X+1),(moveto_Y-1),p1,p2)==playRook)
    {
            cout<<"duke trapped in corner"<<endl;
            p1[moveto_X][moveto_Y-1]=0;
            _score2=8;

    }
    else if (board.gameBoard(moveto_X,(moveto_Y+1),p1,p2)==op_Duke&&board.gameBoard((moveto_X+1),(moveto_Y+1),p1,p2)==playRook)
    {
        cout<<"duke trapped in corner"<<endl;
        p1[moveto_X][moveto_Y+1]=0;
        _score2=8;
    }

}

//capturing
void Referee::pieceCaptured(bool capture)
{
    if(capture)
    {
         cout<<"Piece captured!"<<endl<<endl;
    }
}

void Referee::dukeCaptured(bool dukecapture)
{
    if(dukecapture)
    {
        cout<<"Duke captured!"<<endl;
    }

}

int Referee::p1score()
{
    _score1++;
    return _score1;

}

int Referee::p2score()
{
    _score2++;
    return _score2;
}

void Referee::determineWinner(int winner)
{
    if(winner==1)
    {
        cout<<"Player 1 wins!"<<endl;
    }

    else if (winner==2)
    {
        cout<<"Player 2 wins!"<<endl;
    }
}
