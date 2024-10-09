#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H
#include "WorldActor.h"

class CollisionObject : public WorldActor
{
    public:
        unsigned int animationAbeceda;
        CollisionObject();
        virtual ~CollisionObject();
        bool isCollision(Actor *object);
        float getRadius();
        void setCollisionWidthHeight(int newWidth, int newHeight);
        int getCollisionWidth();
        int getCollisionHeight();
        bool checkCollisionWithObject(CollisionObject object2);
        bool checkCollisionWithObject(CollisionObject *object2);
        void setAnimation(char *animation, int myWidth, int myHeight, int ttime, int animX, int animY);
        void movePoint(float newMovedX, float newMovedY);
        int getObjectType();
        void setObjectType(int newType);
        float getColX();
        float getColY();
        bool checkCollision();
        Actor* checkCollisionO();

    protected:
    private:
        float movedX, movedY;
        float radius;
        int collisionWidth, collisionHeight;
        int objectType;
};

#endif // COLLISIONOBJECT_H
