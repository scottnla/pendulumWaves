#include "pendulumWaves.h"

//--------------------------------------------------------------
void pendulumWaves::setup(){
  ofBackground(0,0,0);
  ofEnableSmoothing();
  ofSetFrameRate(30);
  ofFill();
  width = ofGetWidth();
  height = ofGetHeight();
  //configure all of our pendula
  for(int i = 0; i < numPendulums; i++) {
    float freq = (20.0 + i) / 60.0;
    pendulums[i].index = i;
    pendulums[i].freq = freq;
    pendulums[i].pos = 1;
    pendulums[i].vel = 0;
    pendulums[i].hit = 0;
  }
  startTime = ofGetElapsedTimeMillis();
  startTime *= 0.001;
}

//--------------------------------------------------------------
void pendulumWaves::update(){
  float sec = ofGetElapsedTimeMillis();
  sec *= 0.001;
  sec -= startTime;
  for(int i = 0; i < numPendulums; i++) {
    float oldPos = pendulums[i].pos;
    
    pendulums[i].pos = cos(pendulums[i].freq*sec*2*PI);
    pendulums[i].vel = pendulums[i].pos - oldPos;

    if(pendulums[i].pos > 0.98) {
      pendulums[i].hit = 1;
    }
    else {
      pendulums[i].hit *= 0.85;
    }
  }
}

//--------------------------------------------------------------
void pendulumWaves::draw(){
  ofPushMatrix();
  ofTranslate(width/2, height/2);
  for(int i = 0; i < numPendulums; i++) {
    ofSetColor(255*pendulums[i].hit);
    float rad = ofMap(pendulums[i].pos, -1, 1, 0, width/2);
    float theta = TWO_PI / numPendulums * i;
    ofCircle(rad*cos(theta), rad*sin(theta), 20);
  }
  ofPopMatrix();
}

//--------------------------------------------------------------
void pendulumWaves::keyPressed(int key){

}

//--------------------------------------------------------------
void pendulumWaves::keyReleased(int key){

}

//--------------------------------------------------------------
void pendulumWaves::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void pendulumWaves::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void pendulumWaves::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void pendulumWaves::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void pendulumWaves::windowResized(int w, int h){

}

//--------------------------------------------------------------
void pendulumWaves::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void pendulumWaves::dragEvent(ofDragInfo dragInfo){ 

}
