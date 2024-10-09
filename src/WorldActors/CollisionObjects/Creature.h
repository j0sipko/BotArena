#ifndef CREATURE_H
#define CREATURE_H
#include "CollisionObject.h"
#include <vector>

class Creature : public CollisionObject
{
    public:
        Creature();
        virtual ~Creature();
        void act();
        void turnAt(int fallowedX, int fallowedY);
        virtual Actor* moveForward(float distance);
        virtual Actor* moveBackward(float distance);
        virtual Actor* moveRight(float distance);
        virtual Actor* moveLeft(float distance);
        void setHP(int x);
        float getHP();
        void heal(int amount);
        void doDamage(int damage);
        int getMaxHP();
        void setMaxHP(int newMaxHP);
        int getFullHP();
        bool isAlive();
        bool initiateCollisionChecker();
        void setSight(int newSight, int newSightAnlge);
        int getSight();
        int getSightAngle();
        void drawVision();
        virtual void drawImage();
        void setColor(string colorName);
        void showObjectsOnSight();
        void afterWorldSetter();
        std::vector<Actor*> getActorsOnSight();
        bool isPathClear(float angle, float speed);
        int lastMove;
        bool isPathClear(Point point1, Point point2);
        float getDistanceOf(Actor *object);
        virtual void bonusChecking();

    protected:
        bool alive;
        float HP;
        int maxHP, bonusHP;
        int sight, sightAngle;
        int armor;
        CollisionObject collisionChecker;
        int color;


    private:

};

#endif // CREATURE_H
