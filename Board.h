#ifndef BOARD_H
#define BOARD_H
#include <string>

class Board
{
    public:
        Board();
        virtual ~Board();
        void startGame();
        friend class Player;
        friend class Referee;

    protected:

    private:
        int p1[8][8];
        int p2[8][8];
        int score1, score2;
        std::string gameBoard(int, int, int [][8], int [][8]);
        void printBoard(int p1[][8], int p2[][8]);
        void startBoard(int p1[][8], int p2[][8]);
};

#endif // BOARD_H
