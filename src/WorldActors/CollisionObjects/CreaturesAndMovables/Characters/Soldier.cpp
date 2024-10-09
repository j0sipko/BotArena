#include "Soldier.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

Soldier::Soldier()
{
    //ctor
}

Soldier::~Soldier()
{
    //dtor
}

void Soldier::actFunction()
{
    int temp = std::rand() % 3;
    if (temp==0)
        turnLeft();
    else if(temp==1)
    {
        turnRight();
        shoot();
    }

    moveForward();

}
