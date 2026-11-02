#include "InputManager.h"

void InputManager::updateOnInput()
{
    switch (key)
    {
    case 'w':
        if (sm->getIsCurveActiveSegment())
        {
            sm->moveCurveWeightPosition(0, -1);
        }else
        {
            sm->moveActiveSegment(0, -1);
        }
        break;
    case 's':
        if (sm->getIsCurveActiveSegment())
        {
            sm->moveCurveWeightPosition(0, 1);
        }else
        {
            sm->moveActiveSegment(0, 1);
        }
        break;
    case 'a':
        if (sm->getIsCurveActiveSegment())
        {
            sm->moveCurveWeightPosition(-1, 0);
        }else
        {
            sm->moveActiveSegment(-1, 0);
        }
        break;
    case 'd':
        if (sm->getIsCurveActiveSegment())
        {
            sm->moveCurveWeightPosition(1, 0);
        }else
        {
            sm->moveActiveSegment(1, 0);
        }
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
    case 'f':
        sm->curveActiveSegment();
        break;
    default: ;
    }
}

bool InputManager::isExit()
{
    if (key == 27 || key == 'p') return true;
    
    return false;
}
