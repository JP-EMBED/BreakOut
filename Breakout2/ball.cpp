#include "ball.h"
#include <QDebug>

Ball::Ball(LedBoardManager *brdManager)
    :m_position(15,28), m_xVel(1), m_yVel(-1), m_brdManager(brdManager)
{
}

Ball::~Ball()
{
}

void Ball::setOrigin()
{
    m_position.m_x = 15;
    m_position.m_y = 28;
    m_xVel = 1;
    m_yVel = -1;

    m_brdManager->sendLedColor(QColor(255,0,0));
    m_brdManager->sendLedSet(m_position.m_x, m_position.m_y);
}


bool Ball::updateBall(Cordinate pos, bool boxs [])
{
    bool re = false;

    if (m_position.m_y+1 == pos.m_y && m_yVel == 1)
    {
        if (m_position.m_x+m_xVel == pos.m_x || m_position.m_x+m_xVel == pos.m_x+1 || m_position.m_x+m_xVel == pos.m_x+2 || m_position.m_x+m_xVel == pos.m_x+3)
           m_yVel *= -1;
    }

    if (m_position.m_y < 0)
        m_yVel *= -1;
    if (m_position.m_x == 0 || m_position.m_x == 31)
        m_xVel *= -1;

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if(boxs[((5*i)+j)] == true)
            {

                if(( m_position.m_x+m_xVel == (i*3)+1 || m_position.m_x+m_xVel == (i*3)+2 ||  m_position.m_x+m_xVel == (i*3)+3)
                     && (m_position.m_y+m_yVel == (j*2)+2 || m_position.m_y+m_yVel == (j*2)+1))
                {
                    qDebug() << ((5*i)+j);
                    boxs[((5*i)+j)] = false;
                    m_yVel *= -1;

                    m_brdManager->sendLedColor(QColor(0,0,0));

                    m_brdManager->sendLedSet((i*3)+1,(j*2)+1);
                    m_brdManager->sendLedSet((i*3)+2,(j*2)+1);
                    m_brdManager->sendLedSet((i*3)+3,(j*2)+1);
                    m_brdManager->sendLedSet((i*3)+1,(j*2)+2);
                    m_brdManager->sendLedSet((i*3)+2,(j*2)+2);
                    m_brdManager->sendLedSet((i*3)+3,(j*2)+2);
                }
            }
        }
    }


    if (m_position.m_y == 31)
        re = true;
    else
    {
        m_brdManager->sendLedColor(QColor(0,0,0));
        m_brdManager->sendLedSet(m_position.m_x, m_position.m_y);

        m_position.m_y += m_yVel;
        m_position.m_x += m_xVel;

        m_brdManager->sendLedColor(QColor(255,0,0));
        m_brdManager->sendLedSet(m_position.m_x,m_position.m_y);
    }

    return re;
}
