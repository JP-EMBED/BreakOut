import QtQuick 2.4
import QtQuick.Controls 1.2

ApplicationWindow
{
    title: "Breakout"
    visible: true
    id: mainWindow
    width: ScreenWidth
    height: ScreenHeight

    BreakOut{
        id:breakOut
        anchors.fill: parent
    }

    FindDeviceMenu{
        id:connectView
        anchors.fill: parent
    }
}
