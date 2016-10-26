//
//  ofxMacMouseStealer.h
//
//  Created by ISHII 2bit on 2015/07/21.
//
//

#pragma once
#include "ofEvents.h"
#include "ofVectorMath.h"

namespace ofxMacMouseEventStealer {
    typedef enum {
        OFX_MAC_MOUSE_EVENT_LEFT_BUTTON_DOWN,
        OFX_MAC_MOUSE_EVENT_LEFT_BUTTON_DRAGGED,
        OFX_MAC_MOUSE_EVENT_LEFT_BUTTON_UP,
        OFX_MAC_MOUSE_EVENT_RIGHT_BUTTON_DOWN,
        OFX_MAC_MOUSE_EVENT_RIGHT_BUTTON_DRAGGED,
        OFX_MAC_MOUSE_EVENT_RIGHT_BUTTON_UP,
        OFX_MAC_MOUSE_EVENT_OTHER_BUTTON_DOWN,
        OFX_MAC_MOUSE_EVENT_OTHER_BUTTON_DRAGGED,
        OFX_MAC_MOUSE_EVENT_OTHER_BUTTON_UP,
        OFX_MAC_MOUSE_EVENT_MOVED
    } ofxMacMouseEventType;
    
    typedef struct {
        float x;
        float y;
        ofxMacMouseEventType eventType;
    } ofxMacMouseEventArg;
    
    typedef struct {
        bool isContinuous;
        ofVec3f delta;
        ofVec3f pointDelta;
        ofVec3f pixelDelta;
    } ofxMacMouseScrollWheelEventArg;
    
    void ofxMacMouseStartStealMouseEvent();
    void ofxMacMouseStopStealMouseEvent();
    extern ofEvent<ofxMacMouseEventArg> ofxMacMouseEvent;
    extern ofEvent<ofxMacMouseScrollWheelEventArg> ofxMacMouseScrollWheelEvent;
    
    ofxMacMouseEventArg ofxMacMouseGetCurrentMousePosition();
}

using namespace ofxMacMouseEventStealer;