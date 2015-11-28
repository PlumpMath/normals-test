#pragma once
#include "ofMain.h"
class Branch: public ofCylinderPrimitive{
    ofNode translation;
    
public:
    Branch(){
        ofNode::setParent(translation); // this calls the ofNode version of setParent
        // avoiding a recursive call when calling our own version
    }
    
    void preTranslate(ofVec3f t){
        translation.move(t);
    }
    
    void setParent(ofNode & node){
        translation.setParent(node);
    }
};