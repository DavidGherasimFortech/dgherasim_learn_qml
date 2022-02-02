import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    id: my_window
    width: 640
    height: 480
    visible: true
    title: "This is a layout example"

    ColumnLayout {
        id: grid
        height: my_window.height
        width: my_window.width
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: 3

        Rectangle {
            id: header
            Layout.preferredHeight: my_window.height * 0.15
            Layout.preferredWidth: my_window.width
            color: "red"
        }

        RowLayout {
            id: middle
            spacing: 1
            Layout.preferredHeight: my_window.height * 0.7
            Layout.preferredWidth: my_window.width

            Rectangle {
                id: left
                Layout.preferredHeight: middle.height
                Layout.preferredWidth: middle.width * 0.2
                color: "blue"
            }

            Rectangle {
                id: center
                Layout.preferredHeight: middle.height
                Layout.preferredWidth: middle.width * 0.6
                color: "aqua"
            }

            Rectangle {
                id: right
                Layout.preferredHeight: middle.height
                Layout.preferredWidth: middle.width * 0.2
                color: "cornflowerblue"
            }
        }

        Rectangle {
            id: footer
            Layout.preferredHeight: my_window.height * 0.15
            Layout.preferredWidth: my_window.width
            color: "purple"
        }
    }
}
