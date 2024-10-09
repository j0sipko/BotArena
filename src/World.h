#ifndef WORLD_H
#define WORLD_H
#include "Actor.h"
#include "Events.h"
#include "ActorFactory.h"
#include <vector>

class World
{
    public:
        Events* getEvent();
        void setEvent(Events *newEvent);
        bool exit;
        World();
        virtual ~World();
        Actor* getPlayer();
        void addActor(string name, float posX, float posY);
        void addActor(Actor* newActor, float posX, float posY);
        Actor* getFirstActor();
        Actor* getNextActor();
        Actor* getLastActor();
        void act();
        void removeActor(Actor* actorRemoved);
        int maxX;
        int maxY;
        float *getCameraX();
        float *getCameraY();
        void setCamera(float x, float y);
        void setCamera(float* x, float* y);
        void toggleSniperMode();
        bool getSniperMode();
        void removeItem(Actor* actorRemoved);
        bool isPaused();
        void togglePause();
        bool isVisionShown();
        void swapVision();
        int getActorCount();
        int getIndexOf(Actor *actor);
        Actor *getActorAt(int index);
        Actor *removeActorAt(int index);
        void clearWorld();
        Actor* getPendingActor();
        bool isDrawing();
        void setDrawing(bool newDrawing);
        void pause();
        void unPause();
        int getCurrentMouseX();
        int getCurrentMouseY();
        std::vector<Actor*> getActors();
        bool isMapEditorOn();
        void toggleMapEditor();

    private:
        int actorCount;
        bool paused;
        float *cameraX;
        float *cameraY;
        Events* event;
        Object* actor;
        Object* tempActor;
        Object* tempActor2;
        ActorFactory factory;
        bool sniperMode;
        bool editor;
        bool showVision;
        Actor* menu;
        Actor* chosenActor;
        bool drawing;
        bool mapEditorOn;

    protected:
        float pi=3.14159265358979323846;
};

#endif // WORLD_H
