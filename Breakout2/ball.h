#ifndef BALL_H
#define BALL_H
#include "cordinate.h"
#include "ledboardmanager.h"

class Ball
{
    public:
        Ball(LedBoardManager* brdManager);
        ~Ball();
        void updatePath();
        void setOrigin();
        bool updateBall(Cordinate pos, bool boxs[]);
    private:
        int m_xVel;
        int m_yVel;
        Cordinate m_position;
        LedBoardManager*   m_brdManager;
};

#endif // BALL_H
