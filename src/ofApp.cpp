#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.setup();
    // ofDisableArbTex();

}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    video.draw();
    ofDrawBitmapStringHighlight(ofToString(video.playhead), ofVec2f(0, 10), ofColor::red, ofColor::black);
    ofDrawBitmapStringHighlight(ofToString(video.playheadTarget), ofVec2f(0, 40), ofColor::red, ofColor::black);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
    case OF_KEY_LEFT:
        video.forwardBackward(1);
        break;
    case OF_KEY_RIGHT:
        video.forwardBackward(0);
        break;
    default:
        break;
    }
    // n ++;
    // n%= video.maxBuffers;


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
