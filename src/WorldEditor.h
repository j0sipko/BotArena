#ifndef WORLDEDITOR_H
#define WORLDEDITOR_H
#include "World.h"
#include "WorldActor.h"

class WorldEditor : public WorldActor
{
    public:
        WorldEditor(World* world);
        virtual ~WorldEditor();
        void act();
        void drawImage();
        void addActor(Actor *actor);

    protected:

    private:
        std::vector<Actor*> actors;
        Actor* pendingActor;
        ActorFactory factory;
};

#endif // WORLDEDITOR_H
