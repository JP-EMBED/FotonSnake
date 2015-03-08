#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>
#include "snake.h"
#include "ledboardmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QScreen* pscreen(app.primaryScreen());

    int  screen_width;
    int  screen_height;
    bool show_expanded(true);
    QString display_mode("FullScreen");


    show_expanded = false; // Uncomment for FULLSCREEN

    if(!show_expanded)
    {
        screen_width = pscreen->size().width();
        screen_height = pscreen->size().height();
    }
    else
    {
        screen_width = pscreen->availableGeometry().width();
        screen_height = pscreen->availableGeometry().height();
        display_mode = "Maximized";
    }
    int temp_width(screen_width);
    if(screen_height > screen_width)
    {
        screen_width = screen_height;
        screen_height = temp_width;
    }

    LedBoardManager   brdManager(nullptr,&app);
    Snake snake(&brdManager);
    engine.rootContext()->setContextProperty("ScreenWidth",screen_width);
    engine.rootContext()->setContextProperty("ScreenHeight",screen_height);
    engine.rootContext()->setContextProperty("LedBoardManager", &brdManager);
    engine.rootContext()->setContextProperty("game", &snake);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));




    int ret_val = app.exec();
    return ret_val;
}
