#ifndef SNAKE_H
#define SNAKE_H
#include <QObject>
#include <QList>
#include "random.h"
#include "cordinate.h"
#include "ledboardmanager.h"

//enum direction {up=0, left, down, right};

class Snake : public QObject
{
    Q_OBJECT
    public:
        Snake(LedBoardManager*   brdManager);
        ~Snake();

    public slots:
        int checkValidMove();
        void changeDir(int dir);
        void newGame();


    private:
        Cordinate m_head;
        int m_dir;
        int m_prevDir;
        QList<Cordinate> m_list;
        Cordinate m_pellet;
        LedBoardManager*   m_brdManager;
        static Random m_rand;
};

#endif
