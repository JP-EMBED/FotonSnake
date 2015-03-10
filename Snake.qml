import QtQuick 2.4

Rectangle
{
    anchors.fill:parent
    color: "black"


    Timer
    {
        id: gameTimer
        interval: 150
        running: false
        repeat: true
        onTriggered:
        {
            if(game.checkValidMove())
            {
                gameTimer.stop();
                startGame.visible = true;
                textAnimation.resume();
            }
        }
    }

    Rectangle
    {
        id: upButton
        x: parent.width/3
        height: parent.height/3
        width: parent.width/3
        radius: width
        color: "red"
        MouseArea
        {
            anchors.fill:parent

            onPressed:{
                game.changeDir(0);
            }
        }
    }

    Rectangle
    {
        id: rightButton
        y: parent.height/3
        x: parent.width*2/3
        height: parent.height/3
        width: parent.width/3
        radius: width
        color: "red"
        MouseArea
        {
            anchors.fill:parent

            onPressed:{
                game.changeDir(3);
            }
        }
    }

    Rectangle
    {
        id: downButton
        y: parent.height*2/3
        x: parent.width/3
        height: parent.height/3
        width: parent.width/3
        radius: width
        color: "red"
        MouseArea
        {
            anchors.fill:parent

            onPressed:{
                game.changeDir(2);
            }
        }
    }

    Rectangle
    {
        id: leftButton
        y: parent.height/3
        height: parent.height/3
        width: parent.width/3
        radius: width
        color: "red"
        MouseArea
        {
            anchors.fill:parent

            onPressed:{
                game.changeDir(1);
            }
        }
    }
    Rectangle
    {
        id:startGame
        anchors.fill: parent

        Image
        {
            anchors.fill: parent
            source: "images/snake.png"
        }
        Text
        {
            id: pressAny
            text:"Press Any Key"
            color: "blue"
            font.pixelSize: startGame.height/20
            anchors.horizontalCenter: parent.horizontalCenter
            y: parent.height - (height*1.3)
            SequentialAnimation on color
            {
                id:textAnimation
                running: true
                loops: Animation.Infinite
                ColorAnimation{
                    to: "red"
                    duration: 1000
                }

                ColorAnimation{
                    to: "blue"
                    duration: 1000
                }
            }
        }
        MouseArea
        {
            id:startButton
            anchors.fill: parent

            onPressed:
            {
                startGame.visible = false;
                game.newGame();
                gameTimer.start();
                textAnimation.pause();
            }
        }
    }
    Item{
        anchors.fill: parent
        focus: true
        enabled:true
        Keys.onLeftPressed: {
            if(startGame.visible)
            {
                startGame.visible = false;
                game.newGame();
                gameTimer.start();
                textAnimation.pause();
            }
            else
                game.changeDir(1);
        }

        Keys.onRightPressed: {
            if(startGame.visible)
            {
                startGame.visible = false;
                game.newGame();
                gameTimer.start();
                textAnimation.pause();
            }
            else
                game.changeDir(3);
        }
        Keys.onUpPressed: {
            if(startGame.visible)
            {
                startGame.visible = false;
                game.newGame();
                gameTimer.start();
                textAnimation.pause();
            }
            else
                game.changeDir(0);
        }
        Keys.onDownPressed: {
            if(startGame.visible)
            {
                startGame.visible = false;
                game.newGame();
                gameTimer.start();
                textAnimation.pause();
            }
            else
                game.changeDir(2);
        }
    }
}

