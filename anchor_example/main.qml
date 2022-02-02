import QtQuick 2.12
import QtQuick.Window 2.12

//Here is some interesting thing about margins on anchors
//when a margin is applied this extends the actual object
//and it makes him larger

Window {
    id: my_window
    width: 640
    height: 480
    visible: true
    title: "This is an anchors example"
    // These are some variables to save the margins values
    property int horizontalMargins: 3
    property int verticalMargins: 1

    Rectangle {
        id: header
         width: my_window.width
         height: my_window.height * 0.15
         color: "red"
         anchors.top: parent.top
    }

    Rectangle {
        id: left
        width: my_window.width * 0.2
        height: my_window.height * 0.7 - horizontalMargins * 2
        color: "blue"
        anchors.top: header.bottom
        anchors.topMargin: horizontalMargins
    }

    Rectangle {
        id: center
        width: my_window.width * 0.6 - verticalMargins * 2
        height: my_window.height * 0.7 - horizontalMargins * 2
        color: "aqua"
        anchors.top: header.bottom
        anchors.left: left.right
        anchors.topMargin: horizontalMargins
        anchors.leftMargin: verticalMargins
    }

    Rectangle {
        id: right
        width: my_window.width * 0.2
        height: my_window.height * 0.7 - horizontalMargins * 2
        color: "cornflowerblue"
        anchors.top: header.bottom
        anchors.left: center.right
        anchors.topMargin: horizontalMargins
        anchors.leftMargin: verticalMargins
    }

    Rectangle {
        id: footer
        width: my_window.width
        height: my_window.height * 0.15
        color: "purple"
        anchors.top: left.bottom
        anchors.topMargin: horizontalMargins
    }
}
