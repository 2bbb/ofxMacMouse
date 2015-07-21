//
//  ofxMacMouseControl.cpp
//
//  Created by ISHII 2bit on 2015/07/13.
//
//

#include "ofxMacMouseControl.h"

#include <ApplicationServices/ApplicationServices.h>

namespace ofxMacMouseControl {
    int mouseDownEvents[] = {kCGEventLeftMouseDown, kCGEventRightMouseDown, kCGEventOtherMouseDown};
    int mouseUpEvents[] = {kCGEventLeftMouseUp, kCGEventRightMouseUp, kCGEventOtherMouseUp};
    int mouseButtons[] = {kCGMouseButtonLeft, kCGMouseButtonRight, kCGMouseButtonCenter};
    
    void ofxMacMousePress(ofxMacMouseButton button, int x, int y) {
        CGEventRef event = CGEventCreateMouseEvent(NULL, mouseDownEvents[button], CGPointMake(x, y), mouseButtons[button]);
        CGEventPost(kCGHIDEventTap, event);
        CFRelease(event);
    }
    
    void ofxMacMouseMove(ofxMacMouseButton button, int x, int y) {
        CGEventRef move = CGEventCreateMouseEvent(NULL, kCGEventMouseMoved, CGPointMake(x, y), mouseButtons[button]);
        CGEventPost(kCGHIDEventTap, move);
        CFRelease(move);
    }
    
    
    void ofxMacMouseRelease(ofxMacMouseButton button, int x, int y) {
        CGEventRef event = CGEventCreateMouseEvent(NULL, mouseUpEvents[button], CGPointMake(x, y), mouseButtons[button]);
        CGEventPost(kCGHIDEventTap, event);
        CFRelease(event);
    }
    
    void mouseEvent(CGEventRef event, int eventType) {
        CGEventSetType(event, eventType);
        CGEventPost(kCGHIDEventTap, event);
    }
    
    void ofxMacMouseClick(ofxMacMouseButton button, int x, int y, int num) {
        CGEventRef event = CGEventCreateMouseEvent(NULL, mouseDownEvents[button], CGPointMake(x, y), mouseButtons[button]);
        for(int i = 1; i < num + 1; i++) {
            CGEventSetIntegerValueField(event, kCGMouseEventClickState, i);
            mouseEvent(event, mouseDownEvents[button]);
            mouseEvent(event, mouseUpEvents[button]);
        }
        
        CFRelease(event);
    }
    
    void ofxMacSetCursorPosition(int x, int y) {
        CGWarpMouseCursorPosition(CGPointMake(x, y));
    }
}