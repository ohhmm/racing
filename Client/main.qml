import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs
import QtQuick.Window 2.15


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        id: btn;
        text: "Ok"
        onClicked: fileDialog.open()
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        //folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            //acceptDialog();
            btn.text = fileDialog.currentFile
        }
        onRejected: {
            console.log("rejected")
            //rejectDialog();
        }
        Component.onCompleted: visible = true
    }

    Button {
        text: "Send"
        onClicked: Send();
    }
}
