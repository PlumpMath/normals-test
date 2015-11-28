#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    //light
    light.setPosition(500, 500, 500);
    light.enable();
    
    //camera
    cam.setPosition(0, -440, 300);
    cam.lookAt(ofVec3f(0, 0, 20));
    
    //plane
    plane.setPosition(100, 50, 0);
    plane.set(640, 480);
    plane.setResolution(20, 20);
    
    //mesh
    finalMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    finalMesh.enableColors();
    
    // root
    root.set(branchDimension, branchLenght, radiusSegments, heightSegments, capSegments, false, OF_PRIMITIVE_TRIANGLES);
    root.setPosition(0, 0, 0);
    
    // first a rotation and then a translation
    root.tilt(90);
    root.boom(branchLenght/2);

    ofMatrix4x4 normalMatrix = root.getGlobalTransformMatrix().getInverse();
    ofApp::debugMatrix(normalMatrix);
    for(auto i: root.getMesh().getIndices()){
        finalMesh.addIndex(i);
    }
    for(auto v: root.getMesh().getVertices()){
        finalMesh.addVertex(v * root.getGlobalTransformMatrix());
    }
    for(auto i: root.getMesh().getNormals()){
        ofVec3f normalVector = (normalMatrix * i);
        cout << normalVector.length() << endl;
        finalMesh.addNormal(normalVector);
    }
    
    //branch, first a translation and then a rotation
    branch.set(branchDimension, branchLenght, radiusSegments, heightSegments, capSegments, false, OF_PRIMITIVE_TRIANGLES);
    
    branch.setParent(root);
    branch.preTranslate(ofVec3f(50, 50, 50));
    branch.roll(90.00);

    ofMatrix4x4 branchNormalMatrix = branch.getGlobalTransformMatrix().getInverse();
    ofApp::debugMatrix(branchNormalMatrix);
    for(auto i: branch.getMesh().getIndices()){
        finalMesh.addIndex(i);
    }
    for(auto v: branch.getMesh().getVertices()){
        finalMesh.addVertex(v * branch.getGlobalTransformMatrix());
    }
    for(auto i: branch.getMesh().getNormals()){
        ofVec3f normalVector = (branchNormalMatrix * i);
        cout << normalVector.length() << endl;
        finalMesh.addNormal(normalVector);
    }
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
        plane.drawWireframe();
        //finalMesh.draw();
        drawNormals(10.00);
    cam.end();
}

void ofApp::drawNormals(float size){
    for (int i = 0; i < finalMesh.getNumVertices(); ++i){
        ofVec3f vertex = finalMesh.getVertex(i);
        ofVec3f normal = finalMesh.getNormal(i);
        ofPushStyle();
        ofSetColor(255, 0, 255);
        ofDrawLine(vertex, vertex + size * normal);
        ofPopStyle();
    }
}

void ofApp::debugMatrix(ofMatrix4x4 m){
    ofVec4f firstRow = m.getRowAsVec4f(0);
    ofVec4f secondRow = m.getRowAsVec4f(1);
    ofVec4f thirdRow = m.getRowAsVec4f(2);
    ofVec4f fourthRow = m.getRowAsVec4f(3);
    cout << "|:-:|:-:|:-:|:-:|" << endl;
    cout << firstRow.x << "|" << firstRow.y << "|" << firstRow.z << "|" << firstRow.w << "|" << endl;
    cout << secondRow.x << "|" << secondRow.y << "|" << secondRow.z << "|" << secondRow.w << "|" << endl;
    cout << thirdRow.x << "|" << thirdRow.y << "|" << thirdRow.z << "|" << thirdRow.w << "|" << endl;
    cout << fourthRow.x << "|" << fourthRow.y << "|" << fourthRow.z << "|" << fourthRow.w << "|" << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
