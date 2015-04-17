//
//  Layered.cpp
//  CS372-CPS
//
//  Created by Jacob McKenna on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "Layered.h"
#include "Path.h"

double Layered::getBoundingBoxHeight(){
    
    double maxHeight = 0.0;
    
    for (auto shape : _shapes){
        
        if (shape->getBoundingBoxHeight() > maxHeight)
            maxHeight = shape->getBoundingBoxHeight();
    
    }
    
    return maxHeight;
}

double Layered::getBoundingBoxWidth(){
    
    double maxWidth = 0.0;
    
    for (auto shape : _shapes){
        
        if (shape->getBoundingBoxWidth() > maxWidth)
            maxWidth = shape->getBoundingBoxWidth();
        
    }
    
    return maxWidth;
    
}

double Layered::getCurrentPositionX(){
    
    return getBoundingBoxWidth() / 2;
    
}

double Layered::getCurrentPositionY(){
    
    return getBoundingBoxHeight() / 2;
    
}

const string Layered::buildPS(){
    
    std::stringstream buff;
    
    
    for (auto shape : _shapes){
        
        Path newPath(shape);
        
        buff << newPath.buildPS();
    
    }
    
    return "gsave\n" + buff.str() + "grestore\n";
    
}
