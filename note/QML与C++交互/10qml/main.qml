import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Union.Lotto.Gemini 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        id: element
        x: 182
        y: 138
        text: qsTr("Text")
        font.pixelSize: 12
    }
    Button{
        x: 144
        y: 74
        text: gemini.ballNumber

    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            gemini.begin()
            gemini.stop()
            gemini.ballNumber = 10
        }
    }

    Gemini{
        id:gemini
        onBegin:doSomething(Gemini.BALL_COLOR_RED)
        onBallNumberChanged: console.log("new ball number is", ballNumber) // 10
    }
}
