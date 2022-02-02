import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: "This is a windows with two lists"

    ColumnLayout {
        height: parent.height
        width: parent.width
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: 0

        RowLayout {
            height: parent.height
            width: parent.width
            spacing: 0
            Rectangle {
                id: leftSideRectangle
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width / 2
                border {
                    color: "blue"
                    width: 3
                }

                Component {
                    id: namesComponent
                    Rectangle {
                        color: listView.currentIndex === model.index ? "gray" : "transparent"
                        implicitHeight: componentText.height
                        anchors {
                            left: parent.left
                            right: parent.right
                            leftMargin: 3
                            rightMargin: 3
                        }
                        Text {
                            id: componentText
                            anchors {
                                left: parent.left
                                right: parent.right
                                leftMargin: 3
                                rightMargin: 3
                            }

                            font.pixelSize: 15
                            text: model.name
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: listView.currentIndex = model.index
                        }
                    }
                }

                ListView {
                    id: listView
                    anchors.fill: parent
                    model: MyNamesList {}
                    delegate: namesComponent
                    clip: true
                }
            }
            Rectangle {
                id: rightSideRectangle
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width / 2
                border {
                    color: "red"
                    width: 3
                }

                Component {
                    id: descriptionComponent
                    Text {
                        anchors {
                            left: parent.left
                            right: parent.right
                            leftMargin: 3
                            rightMargin: 3
                        }
                        visible: model.index === listView.currentIndex
                        font.pixelSize: 15
                        height: model.index === listView.currentIndex ? 15 : 0
                        wrapMode: Text.WordWrap
                        text: model.index === listView.currentIndex ? model.text : "default"
                    }
                }

                ListView {
                    id: descriptionListView
                    anchors {
                        left: parent.left
                        right: parent.right
                        top: parent.top
                        bottom: parent.bottom
                        leftMargin: 3
                        rightMargin: 3
                        topMargin: 3
                        bottomMargin: 3
                    }
                    model: MyDescriptionsList {}
                    delegate: descriptionComponent
                    clip: true
                }
            }
        }
    }
}
