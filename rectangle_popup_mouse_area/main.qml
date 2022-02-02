import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: my_window
    width: 640
    height: 480
    visible: true
    title: "This is a wonderfull window"

    Button{
        text: "Please click here!"
        onClicked: my_popup.open()
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Popup{
        id: my_popup
        width: 500
        height: 100
        // Popups can only be centered within their immediate parent or the window overlay; trying to center in other items will produce a warning.
        anchors.centerIn: parent
        // The default is to close when click outside of the window. In this case the only way to close it is to click on the "OK" button.
        closePolicy: Popup.NoAutoClose

        Text{
            id: popup_text
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            // To specify a margin for an object first needs to be anchor to a specific margin that object.
            anchors.topMargin: 20
            text: "This is a popup window to inform you that the prewious click just worked! :)"
            font.bold: true
            z: 1
        }

        Button{
            id: btn_ok
            width: 60
            height: 30
            text: "OK"
            font.bold: true
            font.italic: true
            // Close the "my_popup" window qhen click on this button.
            onClicked: my_popup.close()
            // Here i can not use the id insted of parent
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            // This one is only to make the OK button
            Rectangle{
                width: btn_ok.width
                height: btn_ok.height
                color: "blue"
                radius: 10
                border.color: "black"
                border.width: 3
            }
        }

        // This one is only to make the background red for the popup window
        Rectangle{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "red"
            // Here if i put parent instead of the id of the obect i get a smaller rectangle than the
            width: my_popup.width
            height: my_popup.height
            border.color: "black"
            border.width: 4
            z: -1
        }
    }
}
