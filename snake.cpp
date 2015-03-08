#include "snake.h"
#include <QDebug>

Snake::Snake(LedBoardManager*   brdManager)
    :m_brdManager(brdManager)
{
    m_head.m_x = 15;
    m_head.m_y = 14;
    m_dir = 1;
    m_prevDir = 1;

    Cordinate tail(17, 14);
    Cordinate body(16, 14);

    m_list.append(m_head);
    m_list.append(body);
    m_list.append(tail);

    bool goodPlacement = false;
    while (!goodPlacement)
    {
        m_pellet.m_x = m_rand.GetRandomNumber(32);
        m_pellet.m_y = m_rand.GetRandomNumber(32);

        goodPlacement = true;
        for (int i = 0; i < m_list.length() && !goodPlacement; ++i)
        {
            if (m_list.at(i).m_x == m_pellet.m_x && m_list.at(i).m_y == m_pellet.m_y )
                goodPlacement = false;
        }
    }
}

Snake::~Snake()
{}

int Snake::checkValidMove()
{
    Cordinate head;
    const Cordinate* ptr;
    bool conflict = false;
    m_prevDir = m_dir;

   // qDebug() << "entered";

    head.m_x = m_head.m_x + (m_dir%2 ? m_dir-2: 0);
    head.m_y = m_head.m_y + (m_dir%2 ? 0: m_dir-1);

    //qDebug() << head.m_x;
    //qDebug() << head.m_y;
    //qDebug() << m_list.length();

    for (int i = 0; i < m_list.length(); ++i)
    {
        ptr = &(m_list.at(i));
        if (ptr->m_x == head.m_x && ptr->m_y == head.m_y)
            conflict = true;
    }

    if (!conflict && ((head.m_x >= 0 && head.m_x <  32) && (head.m_y >= 0 && head.m_y < 32)))
    {
        if(m_pellet.m_x == head.m_x && m_pellet.m_y == head.m_y)
        {
            bool goodPlacement = false;
            m_list.prepend(head);
            m_head = head;

            m_brdManager->sendLedColor("Green");
            m_brdManager->sendLedSet(m_head.m_x,m_head.m_y);

            while (!goodPlacement)
            {
                m_pellet.m_x = m_rand.GetRandomNumber(32);
                m_pellet.m_y = m_rand.GetRandomNumber(32);

                goodPlacement = true;
                for (int i = 0; i < m_list.length(); ++i)
                {
                    ptr = &(m_list.at(i));
                    if ((ptr->m_x == m_pellet.m_x) && (ptr->m_y == m_pellet.m_y))
                        goodPlacement = false;
                }
            }
            m_brdManager->sendLedColor("Red");
            m_brdManager->sendLedSet(m_pellet.m_x,m_pellet.m_y);
        }
        else
        {
            m_head = head;
            m_list.prepend(head);
            Cordinate tail = m_list.back();
            m_list.pop_back();

            m_brdManager->sendLedColor("Green");
            m_brdManager->sendLedSet(m_head.m_x,m_head.m_y);
            m_brdManager->sendLedColor("black");
            m_brdManager->sendLedSet(tail.m_x,tail.m_y);
        }
    }
    else
        conflict = true;

    //qDebug() << conflict;

    return conflict;
}

void Snake::changeDir(int dir)
{
    if (m_prevDir+dir != 4 && m_prevDir+dir != 2)
        m_dir = dir;

    qDebug() << m_dir;
}

void Snake::newGame()
{
    m_list.clear();
    m_brdManager->sendClearBoard();

    m_head.m_x = 15;
    m_head.m_y = 14;
    m_dir = 1;
    m_prevDir = 1;

    Cordinate tail(17, 14);
    Cordinate body(16, 14);


    m_list.append(m_head);
    m_list.append(body);
    m_list.append(tail);

    m_brdManager->sendLedColor("Green");
    m_brdManager->sendLedSet(m_head.m_x, m_head.m_y);
    m_brdManager->sendLedSet(body.m_x, body.m_y);
    m_brdManager->sendLedSet(tail.m_x, tail.m_y);

    bool goodPlacement = false;
    while (!goodPlacement)
    {
        m_pellet.m_x = m_rand.GetRandomNumber(32);
        m_pellet.m_y = m_rand.GetRandomNumber(32);

        goodPlacement = true;
        for (int i = 0; i < m_list.length() && !goodPlacement; ++i)
        {
            if (m_list.at(i).m_x == m_pellet.m_x && m_list.at(i).m_y == m_pellet.m_y )
                goodPlacement = false;
        }
    }
    m_brdManager->sendLedColor("Red");
    m_brdManager->sendLedSet(m_pellet.m_x,m_pellet.m_y);
}


Random Snake::m_rand;
