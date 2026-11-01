#include "InputManager.h"

void InputManager::updateOnInput()
{
    switch (key)
    {
    case 'w':
        sm->moveActiveSegment(0, -1);
        break;
    case 's':
        sm->moveActiveSegment(0, 1);
        break;
    case 'a':
        sm->moveActiveSegment(-1, 0);
        break;
    case 'd':
        sm->moveActiveSegment(1, 0);
        break;
    case 'q':
        sm->activePrevSegment();
        break;
    case 'e':
        sm->activenextSegment();
        break;
    case 'c':
        sm->addSegment();
        break;
    case 'x':
        sm->removeActiveSegment();
        break;
    default: ;
    }
}

bool InputManager::isExit()
{
    if (key == 27 || key == 'p') return true;
    
    return false;
}
