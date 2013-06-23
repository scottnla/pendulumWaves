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
    float freq = (20.0 + i) / 480.0;
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
      pendulums[i].hit *= 0.95;
    }
  }
  
}

//--------------------------------------------------------------
void pendulumWaves::draw(){
  ofPushMatrix();
  ofTranslate(width/2, height/2);
  for(int i = 0; i < numPendulums; i++) {
    float radius = width/(2*numPendulums)*i;
    float theta = ofMap(pendulums[i].pos, -1, 1, 0, TWO_PI);
    ofCircle(radius*cos(theta), radius*sin(theta), 10);
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

//--------------------------------------------------------------
void pendulumWaves::audioOut(float* output, int bufferSize, int nChannels){
  float leftScale = 0.5;
  float rightScale = 0.5;

  // sin (n) seems to have trouble when n is very large, so we                                                                         
  // keep phase in the range of 0-TWO_PI like this:                                                                                    
  while (phase > TWO_PI){
    phase -= TWO_PI;
  }

  phaseAdder = 0.95f * phaseAdder + 0.05f * phaseAdderTarget;
  for (int i = 0; i < bufferSize; i++){
    phase += phaseAdder;
    float sample = sin(phase);
    lAudio[i] = output[i*nChannels    ] = sample * volume * leftScale;
    rAudio[i] = output[i*nChannels + 1] = sample * volume * rightScale;
  }
}
