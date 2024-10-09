#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
    shown = false;
    setName("PauseMenu");
    priority = 5;
    setAngle(getPi()/2);
    setAnimation("textures/object2.png",512,512,100,1,1);
}

PauseMenu::~PauseMenu()
{
    //dtor
}

void PauseMenu::act()
{
    if (shown)
    {
        drawImage();
    }
}

bool PauseMenu::isShown()
{
    return shown;
}

void PauseMenu::setVisibility(bool visibility)
{
    shown = visibility;
}

void PauseMenu::afterWorldSetter()
{
    set_position(getWorld()->getCameraX()[0], getWorld()->getCameraY()[0]);
}
