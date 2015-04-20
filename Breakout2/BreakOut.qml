import QtQuick 2.4

Rectangle
{
    id: breakOut
    anchors.fill:parent
    color: "black"
    property int leftPress: 0;
    property int rightPress: 0;

    Timer{
        id: moveTimer
        interval: 60
        running: false
        repeat: false
        onTriggered: {
            if (rightPress || leftPress)
            {
                game.movePaddle(breakOut.leftPress, breakOut.rightPress)
                moveTimer.start();
            }
        }
    }

    Timer{
        id: gameTimer
        interval: 70
        running: false
        repeat: true
        onTriggered: {
            game.updateBall()
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
                if (!moveTimer.running)
                    game.movePaddle(breakOut.leftPress, breakOut.rightPress);
                breakOut.rightPress = 1;
                moveTimer.start();
            }
            onReleased:{
                    breakOut.rightPress = 0;
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
                if (!moveTimer.running)
                    game.movePaddle(breakOut.leftPress, breakOut.rightPress);
                breakOut.leftPress = 1;
                moveTimer.start();
            }
            onReleased:{
                    breakOut.leftPress = 0;
            }
        }
    }
    Rectangle
    {
        id:startGame
        anchors.fill: parent

      /*Image
        {
            anchors.fill: parent
            source: "images/snake.png"
        }*/
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

        Keys.onSpacePressed: {
            if(startGame.visible)
            {
                startGame.visible = false;
                game.newGame();
                gameTimer.start();
                textAnimation.pause();
            }
            else
            {
                game.newGame()
                gameTimer.start()
            }
        }

        Keys.onLeftPressed: {
            if(startGame.visible)
            {
                startGame.visible = false;
                game.newGame();
                gameTimer.start();
                textAnimation.pause();
            }
            else if (!breakOut.leftPress)
            {
                if (!moveTimer.running)
                    game.movePaddle(breakOut.leftPress, breakOut.rightPress);
                breakOut.leftPress = 1;
                moveTimer.start();
            }

        }

        Keys.onRightPressed: {
            if(startGame.visible)
            {
                startGame.visible = false;
                game.newGame();
                gameTimer.start();
                textAnimation.pause();
            }
            else if (!breakOut.rightPress)
            {
                if (!moveTimer.running)
                    game.movePaddle(breakOut.leftPress, breakOut.rightPress);
                breakOut.rightPress = 1;
                moveTimer.start();
            }
        }
        Keys.onReleased: {
            if (event.key == Qt.Key_Right)
                breakOut.rightPress = 0;
            else if (event.key == Qt.Key_Left)
                breakOut.leftPress = 0;
        }
    }
}


