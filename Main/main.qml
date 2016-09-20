import QtQuick 2.0
import QtQuick.Window 2.2

Window {
    id: mainWindow
    width: 1000
    height: 600

    maximumWidth: width
    maximumHeight: height

    minimumHeight: maximumHeight
    minimumWidth: maximumWidth

    visible: true

    Rectangle
    {
        id: background
        objectName: "backGround"
        anchors.fill: parent
        color: "#06A0D4"
    }

    Rectangle
    {
        id: rect
        objectName: "rect"

        color: "yellow"

        x: (mainWindow.width - width) / 2
        y: (mainWindow.height - height) / 2

        width: 80
        height: 80

        onXChanged:
        {
            x_text.text = "x=" + x
        }

        onYChanged:
        {
            y_text.text = "y=" + y
        }

        Text
        {
            id: x_text
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            height: parent.hight / 2

            horizontalAlignment: Text.AlignHCenter

            text: "x=" + parent.x
        }

        Text
        {
            id: y_text
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            height: parent.hight / 2

            horizontalAlignment: Text.AlignHCenter

            text: "y=" + parent.y
        }

        MouseArea
        {
            anchors.fill:parent

            drag.target: rect
            drag.axis: Drag.XAndYAxis
            drag.minimumX: 0
            drag.maximumX: mainWindow.width - rect.width
            drag.minimumY: 0
            drag.maximumY: ground.y - rect.width

            onClicked:
            {
                console.log("hello")
            }
        }
    }


    Rectangle
    {
        id: bar
        objectName: "bar"

        x: 400
        y: 400

        width: 300
        height: 40

        visible: true

        color: "red"
    }

    Rectangle
    {
        id: ground
        objectName: "ground"
        anchors.left: background.left
        anchors.right: background.right
        anchors.bottom: background.bottom

        color: "#D47006"
        opacity: 0.4

        height: 50;
    }
}
