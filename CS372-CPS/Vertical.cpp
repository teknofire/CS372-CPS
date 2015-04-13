//
//  Vertical.cpp
//  CS372-CPS
//
//  Created by Jacob McKenna on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "Vertical.h"
#include "Path.h"

double Vertical::getBoundingBoxHeight(){
    
    double maxHeight = 0.0;
    
    for (auto shape : _shapes){
        
        maxHeight += shape->getBoundingBoxHeight();
        
    }
    
    return maxHeight;
}

double Vertical::getBoundingBoxWidth(){
    
    double maxWidth = 0.0;
    
    for (auto shape : _shapes){
        
        if (shape->getBoundingBoxWidth() > maxWidth)
            maxWidth = shape->getBoundingBoxWidth();
        
    }
    
    return maxWidth;
    
}

double Vertical::getCurrentPositionX(){
    
    return getBoundingBoxWidth() / 2;
    
}

double Vertical::getCurrentPositionY(){
    
    return getBoundingBoxHeight() / 2;
    
}

const string Vertical::buildPS(){
    
    std::stringstream buff;
    
    auto index = _shapes.begin();
    
    buff << Path(*index).buildPS();
    buff << "0 " << (*index)->getCurrentPositionY() << " translate\n";
    
    for (++index; index != _shapes.end(); ++index){
        
        buff << "0 " << (*index)->getCurrentPositionY() << " translate\n";
        Path newPath(*index);
        buff << newPath.buildPS();
        buff << "0 " << (*index)->getCurrentPositionY() << " translate\n";
       
    }
    
    return buff.str();
    
}
