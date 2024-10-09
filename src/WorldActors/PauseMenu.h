#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "Actor.h"

class PauseMenu : public Actor
{
    public:
        PauseMenu();
        virtual ~PauseMenu();
        bool isShown();
        void setVisibility(bool visibility);
        void afterWorldSetter();
        void act();

    protected:

    private:
        bool shown;
};

#endif // PAUSEMENU_H
