#ifndef REFEREE_H
#define REFEREE_H
#include <string>

class Referee
{
    public:
        Referee();
        virtual ~Referee();
        friend class Player;
        friend class Board;

    protected:

    private:
        bool pieceSelect(std::string playerpiece);
        bool isValid(int, int, int, int, int p1[][8], int p2[][8], std::string, std::string, std::string, std::string,bool&);
        void player1_Moves(int, int, int, int, int p1[][8], int p2[][8], std::string, std::string, std::string, std::string);
        void player2_Moves(int, int, int, int, int p1[][8], int p2[][8], std::string, std::string, std::string, std::string);
        void pieceCaptured(bool);
        void dukeCaptured(bool);
        int _score1,_score2;
        bool capture, dukecapture;
        int p1score();
        int p2score();
        void determineWinner(int);
};

#endif // REFEREE_H
