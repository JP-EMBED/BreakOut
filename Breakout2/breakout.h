#ifndef BREAKOUT_H
#define BREAKOUT_H
#include "cordinate.h"
#include "random.h"
#include "ball.h"
#include "ledboardmanager.h"

class BreakOut : public QObject
{
    Q_OBJECT
    public:
        BreakOut(LedBoardManager* brdManager);
        ~BreakOut();
    public slots:
        void newGame();
        void movePaddle(bool leftPress, bool rightPress);
        bool updateBall();
    private:
        Ball m_ball;
        Cordinate m_position;
        LedBoardManager*   m_brdManager;
        bool m_boxs[50];

};

#endif // BREAKOUT_H
