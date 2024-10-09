#ifndef BUTTON_H
#define BUTTON_H
#include "Actor.h"

class Button : public Actor
{
    public:
        Button();
        virtual ~Button();
        bool isButtonClicked();

    protected:

    private:
};

#endif // BUTTON_H
