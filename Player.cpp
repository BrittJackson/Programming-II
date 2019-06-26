#include "Player.h"
#include "Referee.h"
#include "Board.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{
    //ctor

}

Player::~Player()
{
    //dtor
}

void Player::playGame(int p1[][8], int p2[][8], int& p1_score, int& p2_score)
{
    //objects
    Board board;
    Referee referee;

    int x_piece, y_piece, x_, y_;
    bool inPlay=true,
         p1_turn = false,
         valid = true;

    string player,
           rook, duke,
           enemyPiece, enemyDuke,
           piece, movePiece;

    while (inPlay)
    {
        //players take turns
        if (p1_turn)
        {
            p1_turn = false;
            player = "player 2";
            rook = "x";
            duke = "X";
            enemyPiece = "o";
            enemyDuke = "O";
        }

        else
        {
            p1_turn = true;
            player = "player 1";
            rook = "o";
            duke = "O";
            enemyPiece = "x";
            enemyDuke = "X";
        }

        cout << player << " select piece to move(ex. h5) ";
        cin >> piece;
        cout<<piece<<" selected"<<endl<<endl;

        x_piece=piece[0]-'a'; //convert selection to integer
        y_piece=piece[1]-'0';

        //validate selection
        while(!referee.pieceSelect(piece))
        {
                board.printBoard(p1, p2);
                cout << player << " select piece to move(ex. h5) ";
                cin >> piece;
                x_piece=piece[0]-'a';
                y_piece=piece[1]-'0';
        }

        while ((board.gameBoard(x_piece, y_piece, p1, p2) != rook) && board.gameBoard(x_piece, y_piece, p1, p2) != duke)
        {
            cout<<"Cannot select opponent's piece"<<endl;
            cout<<"select piece to move (ex. h5) " ;
            cin >>piece;
            x_piece=piece[0]-'a';
            y_piece=piece[1]-'0';
        }

        valid = true;

        while (valid)  //while true, have players continue to move pieces
        {
            cout << player << " where to move piece (ex. e4)? ";
            cin >> movePiece;

            x_ = movePiece[0]-'a';
            y_ = movePiece[1]-'0';

            //if move is valid
            if (referee.isValid(x_piece, y_piece, x_, y_, p1, p2, enemyPiece, enemyDuke, rook, duke,valid))
            {
                ///Player 1
                if (p1_turn)
                {
                    p1[x_][y_] = p1[x_piece][y_piece]; //move piece to new space
                    p1[x_piece][y_piece] = 0; //clear previous spot from board

                    //check if player 1 moves result in capture
                    referee.player1_Moves(x_piece, y_piece, x_, y_, p1, p2, enemyPiece, enemyDuke, rook, duke);

                    if(referee.dukecapture)
                    {
                        referee._score1=8;
                        inPlay=false;
                    }
                    cout<<player<< " score = "<<referee._score1<<endl;
                }

                ///Player 2
                else
                {
                    p2[x_][y_] = p2[x_piece][y_piece];
                    p2[x_piece][y_piece] = 0;

                    //check if player 2 moves result in a capture
                    referee.player2_Moves(x_piece, y_piece, x_, y_, p1, p2, enemyPiece, enemyDuke, rook, duke);

                   if(referee.dukecapture)
                    {
                        referee._score2=8;
                        inPlay=false;
                    }
                    cout<<player<<" score = "<<referee._score2<<endl;
                }
                    valid = false; //break from loop
            }
            board.printBoard(p1, p2);
        }
            //player 1 wins
            if(referee._score1==8) //all pieces captured or duke immobilized
            {
                inPlay=false;
                referee.determineWinner(1);
            }

            //player 2 wins
            else if (referee._score2==8) //all pieces captured or duke immobilized
            {
                inPlay=false;
                referee.determineWinner(2);
            }

    }
    cout<<"Game Over"<<endl;
}
