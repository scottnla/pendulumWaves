#include "pendulumWaves.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main(){
  ofAppGlutWindow window; // create a window
  // set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
  ofSetupOpenGL(&window, 1024, 1024, OF_WINDOW);
  ofRunApp(new pendulumWaves()); // start the app
}
