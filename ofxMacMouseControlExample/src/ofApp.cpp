#include "ofMain.h"
#include "ofxMacMouseControl.h"

class ofApp : public ofBaseApp {
private:
    bool bMouseMoving;
public:
    void setup() {
        ofSetCircleResolution(40);
        ofEnableAlphaBlending();
        ofEnableAntiAliasing();
        ofEnableSmoothing();
        bMouseMoving = false;
    }
    
    void update() {
        if(bMouseMoving) {
            int x = ofGetWindowPositionX() + ofGetWidth() * (0.5f + 0.4f * cos(ofGetElapsedTimef()));
            int y = ofGetWindowPositionY() + ofGetHeight()  * (0.5f + 0.4f * sin(ofGetElapsedTimef()));
            ofxMacMouseMove(OFX_MAC_MOUSE_BUTTON_LEFT, x, y);
        }
    }
    
    void draw() {
        ofBackground(ofColor::black);
        ofSetColor(ofColor::white);
        ofDrawBitmapString("space : triple click at cursor position.", 20, 20);
        ofDrawBitmapString("'p'   : press left button at cursor position.", 20, 50);
        ofDrawBitmapString("'r'   : release left button at cursor position.", 20, 80);
        ofDrawBitmapString("'m'   : start automatic mouse move.", 20, 110);
        
        ofSetColor(ofColor::red);
        ofCircle(ofGetMouseX(), ofGetMouseY(), ofGetMousePressed() ? 100 : 10);
    }

    void keyPressed(int key){
        if(key == ' ') {
            int x = ofGetWindowPositionX() + ofGetMouseX();
            int y = ofGetWindowPositionY() + ofGetMouseY();
            ofxMacMouseClick(OFX_MAC_MOUSE_BUTTON_LEFT, x, y, 3);
        }
        if(key == 'p') {
            int x = ofGetWindowPositionX() + ofGetMouseX();
            int y = ofGetWindowPositionY() + ofGetMouseY();
            ofxMacMousePress(OFX_MAC_MOUSE_BUTTON_LEFT, x, y);
        }
        if(key == 'r') {
            int x = ofGetWindowPositionX() + ofGetMouseX();
            int y = ofGetWindowPositionY() + ofGetMouseY();
            ofxMacMouseRelease(OFX_MAC_MOUSE_BUTTON_LEFT, x, y);
        }
        if(key == 'm') {
            bMouseMoving ^= true;
        }
    }
    
    void keyReleased(int key) {}
    
    void mouseMoved(int x, int y ) {
        ofLogNotice() << "move: " << x << ", " << y;
    }
    
    void mouseDragged(int x, int y, int button) {
        ofLogNotice() << "dragged " << x << ", " << y;
    }
    
    void mousePressed(int x, int y, int button) {
        ofLogNotice() << "press: " << x << ", " << y;
    }
    
    void mouseReleased(int x, int y, int button) {}
    void windowResized(int w, int h) {}
    void dragEvent(ofDragInfo dragInfo) {}
    void gotMessage(ofMessage msg) {}
};

int main() {
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp(new ofApp());
}