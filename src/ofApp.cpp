#include "ofApp.h"

int x = 1300;
int y = 600;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255); //背景を真っ白
    ofToggleFullscreen();
    video.setDesiredFrameRate(30);        //フレームレート
    video.initGrabber(x, y);          //取得映像のサイズ
    
    threshold = 60;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    video.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    pixels = video.getPixels();
    for (int y=0; y<pixels.getHeight(); y+=5) {
        for (int x=0; x<pixels.getWidth(); x+=5) {
            ofColor color = pixels.getColor(x, y);
            if (color.getLightness() < threshold) {
                int time = fmod(ofGetElapsedTimef()*30,256);
                
                int hue = ofMap(x, 0, video.getWidth(), time, time+30);
                int saturation = ofMap(y, 0, video.getHeight(), 255, 70);
                int brightness = 255;
                
                ofSetColor(ofColor::fromHsb(hue, saturation, brightness));
                ofDrawCircle(x, y, 3);
            }
        }
    }
    ofSetColor(255, 255, 255);
    video.draw(ofGetWidth()-470,ofGetHeight()-300,470,300);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'a' && threshold<255) threshold++;
    if (key == 'b' && threshold>0) threshold--;

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
