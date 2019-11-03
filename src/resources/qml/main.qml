import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import ChessBoard 1.0

Window {
    id : window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TextEdit
    {
        id : moveArea
        width: 240
        anchors.left: chessBoard.right
        text: "<b>Hello</b> <i>World!</i>"
        font.family: "Helvetica"
        font.pointSize: 20
        color: "blue"
        focus: true
    }

    function mousePosToCoord(mouseX, mouseY)
    {
        return 'x' + ((mouseX / 32) | 0) + 'y'+ ((mouseY / 32) | 0)
    }

    ChessBoard
    {
        id : chessBoard
        width: 256
        height: 256
        name : "chess"


        Rectangle {
            id : selectRect
            color: "transparent"
            y: 0;
            x: 0;
            radius: 10
            width: 32;
            height: 32;
            border.color: "blue"
            border.width: 0
        }

        function select(x, y)
        {
            // надо найти позицию относительно шахматной доски
            selectRect.x = ((x / 32) | 0) * 32;
            selectRect.y = ((y / 32) | 0) * 32;
            selectRect.border.width = 3
        }
        function unselect()
        {
            selectRect.border.width = 0
        }


        MouseArea
        {
            property point oldPoint: Qt.point(-1,-1);
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked:
            {
                if (mouse.button === Qt.LeftButton)
                {
                    if(oldPoint === Qt.point(-1,-1))
                    {
                        oldPoint = Qt.point(mouseX, mouseY);
                        chessBoard.select(mouseX, mouseY);
                    }
                    else
                    {
                        var newPoint = Qt.point(mouseX, mouseY);
                        chessBoard.move(oldPoint, newPoint)
                        oldPoint = Qt.point(-1,-1)
                        chessBoard.unselect();
                    }
                }
                else
                {
                }
            }
        }
    }
}
