#pragma once

#include "ofMain.h"

class pendulumWaves : public ofBaseApp{
 public:
  void setup();
  void update();
  void draw();
		
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  struct Pendulum {
    int index;
    float freq;
    float pos;
    float vel;
    float hit;
  };
  
  //visuals
  float width, height;
  static const int numPendulums = 75;
  Pendulum pendulums[numPendulums];
  float startTime;
  ofImage img;
  int counter;
};
