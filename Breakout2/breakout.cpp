#include "breakout.h"

BreakOut::BreakOut(LedBoardManager* brdManager)
    :m_ball(brdManager), m_position(13,29), m_brdManager(brdManager)
{

}

BreakOut::~BreakOut()
{

}

void BreakOut::newGame()
{
    QColor color[5];

    color[4] = QColor(255, 0, 255);
    color[3] = QColor(255, 255, 0);
    color[2] = QColor(0, 255, 0);
    color[1] = QColor(0, 0, 255);
    color[0] = QColor(255, 150, 0);

    m_brdManager->sendClearBoard();
    m_ball.setOrigin();
    m_position.m_x = 13;
    m_position.m_y = 29;

    m_brdManager->sendLedColor(QColor(255,255,255));
    m_brdManager->sendLedSet(m_position.m_x, m_position.m_y);
    m_brdManager->sendLedSet(m_position.m_x+1, m_position.m_y);
    m_brdManager->sendLedSet(m_position.m_x+2, m_position.m_y);
    m_brdManager->sendLedSet(m_position.m_x+3, m_position.m_y);

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            m_boxs[((5*i)+j)] = true;
            if (j%2)
                m_brdManager->sendLedColor(color[(i%5)]);
            else
                m_brdManager->sendLedColor(color[4-(i%5)]);

            m_brdManager->sendLedSet((i*3)+1,(j*2)+1);
            m_brdManager->sendLedSet((i*3)+2,(j*2)+1);
            m_brdManager->sendLedSet((i*3)+3,(j*2)+1);
            m_brdManager->sendLedSet((i*3)+1,(j*2)+2);
            m_brdManager->sendLedSet((i*3)+2,(j*2)+2);
            m_brdManager->sendLedSet((i*3)+3,(j*2)+2);
        }
    }
}

void BreakOut::movePaddle(bool leftPress, bool rightPress)
{
    if (rightPress)
    {
        if (m_position.m_x < 28)
        {
            m_position.m_x += 1;
            m_brdManager->sendLedColor(QColor(0,0,0));
            m_brdManager->sendLedSet(m_position.m_x-1, m_position.m_y);
            m_brdManager->sendLedColor(QColor(255,255,255));
            m_brdManager->sendLedSet(m_position.m_x+3, m_position.m_y);

        }
    }
    else if (leftPress)
    {
        if (m_position.m_x)
        {
            m_position.m_x -= 1;
            m_brdManager->sendLedColor(QColor(0,0,0));
            m_brdManager->sendLedSet(m_position.m_x+4, m_position.m_y);
            m_brdManager->sendLedColor(QColor(255,255,255));
            m_brdManager->sendLedSet(m_position.m_x, m_position.m_y);

        }
    }
}

bool BreakOut::updateBall()
{
    bool re = true;

    if (m_ball.updateBall(m_position, m_boxs))
        newGame();
    else
        re = false;

    return re;
}
