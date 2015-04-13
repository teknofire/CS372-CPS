//
//  Horizontal.cpp
//  CS372-CPS
//
//  Created by Jacob McKenna on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "Horizontal.h"
#include "Path.h"

double Horizontal::getBoundingBoxHeight(){
    
    double maxHeight = 0.0;
    
    for (auto shape : _shapes){
        
        if (shape->getBoundingBoxHeight() > maxHeight)
            maxHeight = shape->getBoundingBoxHeight();
        
    }
    
    return maxHeight;
}

double Horizontal::getBoundingBoxWidth(){
    
    double maxWidth = 0.0;
    
    for (auto shape : _shapes){
        
        maxWidth += shape->getBoundingBoxWidth();
        
    }
    
    return maxWidth;
    
}

double Horizontal::getCurrentPositionX(){
    
    return getBoundingBoxWidth() / 2;
    
}

double Horizontal::getCurrentPositionY(){
    
    return getBoundingBoxHeight() / 2;
    
}

const string Horizontal::buildPS(){
    
    std::stringstream buff;
    
    auto index = _shapes.begin();
    
    buff << Path(*index).buildPS();
    buff << (*index)->getCurrentPositionX() << " 0 translate\n";
    
    for (++index; index != _shapes.end(); ++index){
        
        buff << (*index)->getCurrentPositionX() << " 0 translate\n";
        Path newPath(*index);
        buff << newPath.buildPS();
        buff << (*index)->getCurrentPositionX() << " 0 translate\n";
        
    }
    
    return buff.str();
    
}
