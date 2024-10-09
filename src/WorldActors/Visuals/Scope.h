#ifndef SCOPE_H
#define SCOPE_H
#include "WorldActor.h"

class Scope : public WorldActor
{
    public:
        Scope();
        virtual ~Scope();
        void act();
        void drawImage();

    protected:

    private:
        bool paused;
};

#endif // SCOPE_H
