#pragma once
#include <conio.h>

#include "SegmentManager.h"

class InputManager
{
    SegmentManager* sm;
    int key;
    
public:
    InputManager(SegmentManager* sm): sm(sm) {}
    
    void updateOnInput() const;
    bool isExit() const;
    
    int updateKey()
    {   
        key = _getch();
        return key;
    }
    
};
