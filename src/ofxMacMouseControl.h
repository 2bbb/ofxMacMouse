//
//  ofxMacMouseControl.h
//
//  Created by ISHII 2bit on 2015/07/13.
//
//

#pragma once

#include <cstdint>

// ref: https://github.com/BlueM/cliclick
namespace ofxMacMouseControl {
    typedef enum {
        OFX_MAC_MOUSE_BUTTON_LEFT,
        OFX_MAC_MOUSE_BUTTON_CENTER,
        OFX_MAC_MOUSE_BUTTON_RIGHT
    } ofxMacMouseButton;

    void ofxMacMousePress(ofxMacMouseButton button, int x, int y);
    void ofxMacMouseMove(ofxMacMouseButton button, int x, int y);
    void ofxMacMouseRelease(ofxMacMouseButton button, int x, int y);

    void ofxMacMouseClick(ofxMacMouseButton button, int x, int y, int num);

    void ofxMacSetCursorPosition(int x, int y);
    
    void ofxMacMouseMoveScrollWheelLine(std::int32_t dx, std::int32_t dy, std::int32_t dz = 0);
    void ofxMacMouseMoveScrollWheelPixel(std::int32_t dx, std::int32_t dy, std::int32_t dz = 0);
}

using namespace ofxMacMouseControl;