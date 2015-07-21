# ofxMacMouse

control mouse with program

## API

### Control Mouse

#### enum ofxMacMouseButton

	OFX_MAC_MOUSE_BUTTON_LEFT
	OFX_MAC_MOUSE_BUTTON_CENTER
	OFX_MAC_MOUSE_BUTTON_RIGHT

#### void ofxMacMousePress(ofxMacMouseButton button, int x, int y);
#### void ofxMacMouseMove(ofxMacMouseButton button, int x, int y);
#### void ofxMacMouseRelease(ofxMacMouseButton button, int x, int y);

post press/move/release event.

#### void ofxMacMouseClick(ofxMacMouseButton button, int x, int y, int num);

post press + release _num_ times.

#### void ofxMacSetCursorPosition(int x, int y);

set cursor position without event.

### Steal Mouse Event

#### enum ofxMacMouseEventType

	OFX_MAC_MOUSE_EVENT_LEFT_BUTTON_DOWN
	OFX_MAC_MOUSE_EVENT_LEFT_BUTTON_DRAGGED
	OFX_MAC_MOUSE_EVENT_LEFT_BUTTON_UP
	OFX_MAC_MOUSE_EVENT_RIGHT_BUTTON_DOWN
	OFX_MAC_MOUSE_EVENT_RIGHT_BUTTON_DRAGGED
	OFX_MAC_MOUSE_EVENT_RIGHT_BUTTON_UP
	OFX_MAC_MOUSE_EVENT_OTHER_BUTTON_DOWN
	OFX_MAC_MOUSE_EVENT_OTHER_BUTTON_DRAGGED
	OFX_MAC_MOUSE_EVENT_OTHER_BUTTON_UP
	OFX_MAC_MOUSE_EVENT_MOVED

#### void ofxMacMouseStartStealMouseEvent();
#### void ofxMacMouseStopStealMouseEvent();

start/stop listeing callback.

#### ofEvent<ofxMacMouseEventArg> ofxMacMouseEvent;

target ofEvent

#### struct ofxMacMouseEventArg;

	float x
	float y
	ofxMacMouseEventType eventType

## Update history

### 2015/07/22 Rename from ofxMacMouseControl to ofxMacMouse

### 2015/07/21 ver 0.02 release

* add ofxMacMouseEventStealer

### 2015/07/15 ver 0.01 release

## License

MIT License.

## Author

* ISHII 2bit [bufferRenaiss co., ltd.]
* ishii[at]buffer-renaiss.com

## At the last

Please create new issue, if there is a problem.
And please throw pull request, if you have a cool idea!!