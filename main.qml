import QtQuick 2.4
import QtQuick.Controls 1.2
import "ConnectionMenu"

ApplicationWindow
{
    title: "Foton - Snake"
    visible: true
    id: mainWindow
    width: ScreenWidth
    height: ScreenHeight


    Snake{
    }

    FindDeviceMenu{
        anchors.fill: parent

    }






}
