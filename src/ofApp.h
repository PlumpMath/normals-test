#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void drawNormals(float size);
        void debugMatrix(ofMatrix4x4 m);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void recursiveBranching(ofCylinderPrimitive node, int limit);
    
    int branchLenght = 80;
    int branchDimension = 10;
    int radiusSegments = 10;
    int heightSegments = 10;
    int capSegments = 10;
    float theta = 45;
    
    ofCylinderPrimitive root;
    
    ofLight light;
    ofPlanePrimitive plane;
    ofEasyCam cam;
    
    ofVboMesh finalMesh;
};
