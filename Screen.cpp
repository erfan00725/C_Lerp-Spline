#include "Screen.h"



#include <iostream>
#include <vector>
#include <string>

#include "structs.h"

using namespace std;

    Screen::Screen(int x, int y) : playgroundSizeX(x), playgroundSizeY(y) {
        screen = vector(playgroundSizeY, vector(playgroundSizeX, '.'));
    }
    Screen::Screen()
    {
        screen = vector(playgroundSizeY, vector(playgroundSizeX, '.'));
    }
        
    vector<vector<char>> Screen::getScreen() { return screen; }
        
    void Screen::setPoint(int x, int y, char c)
    {
        screen[y][x] = c;
    }
    void Screen::setPoint(Point2D p, char c)
    {
        screen[p.yPos][p.xPos] = c;
    }
        
    void Screen::resetPoints ()
    {
        screen = vector(playgroundSizeY, vector(playgroundSizeX, '.'));
    }
        
    void Screen::clearScreen ()
    {
        system("cls");
    }
        
    int Screen::getScreenSizeX() const { return playgroundSizeX; }
    int Screen::getScreenSizeY() const { return playgroundSizeY; }
        
    bool Screen::isInScreen(int x, int y) const { return x >= 0 && x < playgroundSizeX && y >= 0 && y < playgroundSizeY; }
        
    void Screen::setBottomDescription(const string& description) { bottomDescription = description; }

void Screen::setTopDescription(const string& description)
{
        topDescription = description;
}

void Screen::printScreen () const
    {
        cout << '\n' << topDescription << '\n' ;
        for (int i = 0; i < screen.size(); i++) {
            for (int j = 0; j < screen[i].size(); j++) {
                cout << screen[i][j];
            }
            cout << '\n';
        }
        cout << bottomDescription << '\n';
    };
