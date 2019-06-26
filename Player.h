#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player();
        virtual ~Player();
        friend class Referee;
        friend class Board;

    protected:

    private:
        void playGame(int p1[][8], int p2[][8], int&, int&);

};

#endif // PLAYER_H
