import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: "QObject List Example"

    ListView {
        width: parent.width
        height: parent.height

        model: myObjectList

        delegate: Item {
            width: parent.width
            height: 50

            Rectangle {
                width: parent.width
                height: parent.height
                color: "lightblue"
                border.color: "blue"

                Text {
                    anchors.centerIn: parent
                    text: model.name
                }
            }
        }
    }
}
