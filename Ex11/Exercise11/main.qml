import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400
    height: 300
    title: "QAbstractListModel Example"

    ListView {
        width: parent.width
        height: parent.height

        model: personModel

        delegate: Item {
            width: parent.width
            height: 50

            Rectangle {
                width: parent.width
                height: 50
                color: "lightblue"
                border.color: "blue"

                Text {
                    anchors.centerIn: parent
                    text: name
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Name:", name)
                    console.log("Email: ", email)
                }
            }
        }
    }
}
