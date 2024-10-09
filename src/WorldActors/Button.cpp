#include "Button.h"

Button::Button()
{
    //ctor
}

Button::~Button()
{
    //dtor
}

bool Button::isButtonClicked()
{
    if (isMouseOn() && getWorld()->getEvent()->isMouseButtonPressedOnce_Left)
        return true;
    else return false;
}
