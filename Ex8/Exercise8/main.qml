import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    //Define slots in QML
    function qmlSlot() {
        console.log("QML slot is called");
    }

    //Connect signal C++ with slot QML
    Connections {
        target: signalEmitter
        onMySignal: {
            qmlSlot();
        }
    }
}
