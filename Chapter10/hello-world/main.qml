import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
	width: 640
	height: 480
	visible: true
	title: qsTr("TSL2591 Reading")

	property double lightIntensity: 0
	property bool isStarted: false

	Backend {
		id: backend
	}

	Label {
		id: itmIntensityLbl
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: parent.top
		anchors.topMargin: 100
		font.pixelSize: 24
		text: "Light Intensity"
	}

	Item {
		id: itmIntensityValue
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: itmIntensityLbl.bottom
		anchors.topMargin: 10
		width: itmIntensityLbl.width
		height: (itmIntensityLbl.height * 2) + 20

		Rectangle {
			id: rectLabelVal
			color: "transparent"
			border.color: "black"
			border.width: 2
			width: itmIntensityValue.width
			height: itmIntensityValue.height
			anchors.horizontalCenter: parent.horizontalCenter

			Text {
				id: txtLightIntensity
				anchors.horizontalCenter: parent.horizontalCenter
				font.pointSize: 48
				text: backend.q_lightIntensity
			}
		}
	}

	Timer {
		id: tmrSensor
		interval: 1000
     		running: false
     		repeat: true
     		onTriggered: {
         		txtLightIntensity.text = backend.q_lightIntensity
     		}
    	}

	Button {
		id: btnPeriodic
		anchors.right: itmIntensityValue.horizontalCenter
		anchors.top: itmIntensityValue.bottom
		anchors.rightMargin: 50
		anchors.topMargin: 20
		font.pointSize: 24
		text: "Start"

		onClicked: {
			if (isStarted === false) {
				btnPeriodic.text = "Stop";
				isStarted = true;
				btnNow.visible = false;
				tmrSensor.running = true;
			} else {
				btnPeriodic.text = "Start";
				isStarted = false;
				btnNow.visible = true;
				tmrSensor.running = false;
			}
		}
	}

	Button {
		id: btnNow
		anchors.left: itmIntensityValue.horizontalCenter
		anchors.top: itmIntensityValue.bottom
		anchors.leftMargin: 50
		anchors.topMargin: 20
		font.pointSize: 24
		text: "Now"

		onClicked: {
			txtLightIntensity.text = backend.q_lightIntensity
		}
	}
}
