import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.15


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Karts")

    FileDialog {
        id: fileDialog
        title: "Please choose a file"

        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            btn.text = fileDialog.currentFile
        }
        onRejected: {
            console.log("rejected")
        }
        Component.onCompleted: visible = true
    }

    Button {
        id: btn;
        text: "Ok"
        onClicked: fileDialog.open()
    }

    Button {
        text: "Send"
        onClicked: send(fileDialog.currentFile);
    }
}
