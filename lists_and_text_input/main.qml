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
        id: columnLayout
        height: parent.height
        width: parent.width
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: 0
        Rectangle {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height * 0.2
            border {
                color: "blue"
                width: 3
            }
            Text {
                id: newNames
                text: "Here you can insert a new type:"
                font.pixelSize: 15
                anchors {
                    left: parent.left
                    top: parent.top
                    leftMargin: 6
                    topMargin: 6
                }
            }
            TextInput {
                id: newNamesInput
                font.pixelSize: 15
                z: 0
                maximumLength: 50
                anchors {
                    left: newNames.right
                    right: parent.right
                    top: parent.top
                    leftMargin: 3
                    topMargin: 6
                    rightMargin: 6
                }
                Rectangle {
                    anchors.fill: parent
                    z: -1
                    border {
                        width: 1
                        color: "black"
                    }
                }
            }
            Text {
                id: newDesc
                text: "Here you can insert description:"
                font.pixelSize: 15
                anchors {
                    left: parent.left
                    top: newNames.bottom
                    leftMargin: 6
                    topMargin: 10
                }
            }
            TextInput {
                id: newDescInput
                font.pixelSize: 15
                z: 0
                maximumLength: 200
                anchors {
                    left: newDesc.right
                    right: parent.right
                    top: newNames.bottom
                    leftMargin: 3
                    topMargin: 10
                    rightMargin: 6
                }
                Rectangle {
                    anchors.fill: parent
                    z: -1
                    border {
                        width: 1
                        color: "black"
                    }
                }
            }

            Button {
                id: submitButton
                text: "Submit"
                font.pixelSize: 15
                height: 25
                highlighted: true
                anchors {
                    left: parent.left
                    top: newDescInput.bottom
                    topMargin: 10
                    leftMargin: 6
                }
                onClicked: {
                    type_model.insertDataStructure(newNamesInput.getText(0, 50), newDescInput.getText(0, 200))
                }
            }
        }

        RowLayout {
            id: rowLayout
            height: parent.height * 0.8
            width: parent.width
            spacing: 0
            Rectangle {
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width / 2
                border {
                    color: "black"
                    width: 3
                }
                Component {
                    id: namesComponent
                    Rectangle {
                        color: namesListView.currentIndex === model.index ? "gray" : "transparent"
                        implicitHeight: namensComponentText.height
                        anchors {
                            left: parent.left
                            right: parent.right
                            leftMargin: 3
                            rightMargin: 3
                        }
                        Text {
                            id: namensComponentText
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
                            onClicked: namesListView.currentIndex = model.index
                        }
                    }
                }
                ListView {
                    id: namesListView
                    anchors.fill: parent
                    model: type_model.typeListModel
                    delegate: namesComponent
                    clip: true
                }
            }
            Rectangle {
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
                        visible: model.index === namesListView.currentIndex
                        font.pixelSize: 15
                        height: model.index === namesListView.currentIndex ? 15 : 0
                        wrapMode: Text.WordWrap
                        text: model.index === namesListView.currentIndex ? model.description : "This will never be seen on display"
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
//                    model: MyDescriptionsList {}
                    model: type_model.typeListModel
                    delegate: descriptionComponent
                    clip: true
                }
            }
        }
    }
}
