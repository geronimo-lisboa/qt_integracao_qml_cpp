import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.0
//O backend que eu criei no main, aqui.
import don.geronimo.backend 1.0

ApplicationWindow{
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    //Um objeto Backend dentro do root
    Backend {
        id:backend
    }

    TextField {
        id: edtTexto
        text: backend.userName
        placeholderText:  qsTr("User name")
        anchors.centerIn: parent
        //Ao ocorrer o evento de onTextChanged passa o text pro userName
        onTextChanged: backend.userName = text
    }

    Text {
        id: element
        //property binding ao backend
        text: backend.userName
        anchors.right: parent.right
        anchors.rightMargin: 326
        anchors.left: parent.left
        anchors.leftMargin: 291
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 177
        anchors.top: edtTexto.verticalCenter
        anchors.topMargin: 49
        font.pixelSize: 12
    }

    Button {
        id: btnSomething
        text: qsTr("teste console")
        anchors.top: element.bottom
        anchors.left: element.left
        //Chama a função que eu defini como Q_INVOKABLE
        onClicked: {backend.printSomethingInConsole()}
    }
}

/*##^## Designer {
    D{i:3;anchors_x:291;anchors_y:289}
}
 ##^##*/
