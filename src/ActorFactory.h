#ifndef ACTORFACTORY_H
#define ACTORFACTORY_H
#include "Actor.h"

class ActorFactory
{
    public:
        Actor *getActor(string name);
        ActorFactory();
        virtual ~ActorFactory();
    protected:
    private:
};

#endif // ACTORFACTORY_H
