//
//  ofxMacMouseControl.cpp
//
//  Created by ISHII 2bit on 2015/07/13.
//
//

#include "ofxMacMouseControl.h"

#include <ApplicationServices/ApplicationServices.h>

namespace ofxMacMouseControl {
    CGEventType mouseDownEvents[] = {kCGEventLeftMouseDown, kCGEventRightMouseDown, kCGEventOtherMouseDown};
    CGEventType mouseDraggedEvents[] = {kCGEventLeftMouseDragged, kCGEventRightMouseDragged, kCGEventOtherMouseDragged};
    CGEventType mouseUpEvents[] = {kCGEventLeftMouseUp, kCGEventRightMouseUp, kCGEventOtherMouseUp};
    CGMouseButton mouseButtons[] = {kCGMouseButtonLeft, kCGMouseButtonRight, kCGMouseButtonCenter};
    
    void ofxMacMouseMove(ofxMacMouseButton button, int x, int y) {
        CGEventSourceRef eventSource  = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
        CGEventRef move = CGEventCreateMouseEvent(eventSource, kCGEventMouseMoved, CGPointMake(x, y), mouseButtons[button]);
        CGEventPost(kCGHIDEventTap, move);
        CFRelease(move);
        CFRelease(eventSource);
    }
    
    void ofxMacMousePress(ofxMacMouseButton button, int x, int y) {
        CGEventSourceRef eventSource  = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
        CGEventRef event = CGEventCreateMouseEvent(eventSource, mouseDownEvents[button], CGPointMake(x, y), mouseButtons[button]);
        CGEventPost(kCGHIDEventTap, event);
        CFRelease(event);
        CFRelease(eventSource);
    }
    
    void ofxMacMouseDrag(ofxMacMouseButton button, int x, int y) {
        CGEventSourceRef eventSource  = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
        CGEventRef event = CGEventCreateMouseEvent(eventSource, mouseDraggedEvents[button], CGPointMake(x, y), mouseButtons[button]);
        CGEventPost(kCGHIDEventTap, event);
        CFRelease(event);
        CFRelease(eventSource);
    }

    void ofxMacMouseRelease(ofxMacMouseButton button, int x, int y) {
        CGEventSourceRef eventSource  = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
        CGEventRef event = CGEventCreateMouseEvent(eventSource, mouseUpEvents[button], CGPointMake(x, y), mouseButtons[button]);
        CGEventPost(kCGHIDEventTap, event);
        CFRelease(event);
        CFRelease(eventSource);
    }
    
    void mouseEvent(CGEventRef event, int eventType) {
        CGEventSetType(event, (CGEventType) eventType);
        CGEventPost(kCGHIDEventTap, event);
    }
    
    void ofxMacMouseClick(ofxMacMouseButton button, int x, int y, int num) {
        CGEventSourceRef eventSource  = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
        CGEventRef event = CGEventCreateMouseEvent(eventSource, mouseDownEvents[button], CGPointMake(x, y), mouseButtons[button]);
        for(int i = 1; i < num + 1; i++) {
            CGEventSetIntegerValueField(event, kCGMouseEventClickState, i);
            mouseEvent(event, mouseDownEvents[button]);
            mouseEvent(event, mouseUpEvents[button]);
        }
        
        CFRelease(event);
        CFRelease(eventSource);
    }
    
    void ofxMacSetCursorPosition(int x, int y) {
        CGWarpMouseCursorPosition(CGPointMake(x, y));
    }
    
    void ofxMacMouseMoveScrollWheelLine(std::int32_t dx, std::int32_t dy, std::int32_t dz) {
        CGEventSourceRef eventSource  = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
        CGWheelCount wheelCount = 3;
        CGEventRef event = CGEventCreateScrollWheelEvent(eventSource, kCGScrollEventUnitLine, wheelCount, dy, dx, dz);
        CGEventPost(kCGHIDEventTap, event);
        CFRelease(event);
        CFRelease(eventSource);
    }
    
    void ofxMacMouseMoveScrollWheelPixel(std::int32_t dx, std::int32_t dy, std::int32_t dz) {
        CGEventSourceRef eventSource  = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
        CGWheelCount wheelCount = 3;
        CGEventRef event = CGEventCreateScrollWheelEvent(eventSource, kCGScrollEventUnitPixel, wheelCount, dy, dx, dz);
        CGEventPost(kCGHIDEventTap, event);
        CFRelease(event);
        CFRelease(eventSource);
    }
}