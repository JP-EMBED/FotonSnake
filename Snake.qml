import QtQuick 2.4

Rectangle
{
    anchors.fill:parent
    color: "black"


    Timer
    {
        id: gameTimer
        interval: 400
        running: false
        repeat: true
        onTriggered:
        {
            if(game.checkValidMove())
            {
                gameTimer.stop();
                startGame.visible = true;
            }
        }
    }

    Rectangle
    {
        id: upButton
        x: parent.width/3
        height: parent.height/3
        width: parent.width/3
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
        Text
        {
            anchors.fill: parent
            text: "Start"
            font.pixelSize: parent.height/12
            horizontalAlignment: Text.AlignHCenter
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
            }
        }
    }
    Item{
        anchors.fill: parent
        focus: true
        enabled:true
        Keys.onLeftPressed: {
            game.changeDir(1);
        }

        Keys.onRightPressed: {
            game.changeDir(3);
        }
        Keys.onUpPressed: {
            game.changeDir(0);
        }
        Keys.onDownPressed: {
            game.changeDir(2);
        }
    }
}

