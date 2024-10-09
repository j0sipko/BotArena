#include "CollisionObject.h"
#include "Item.h"
#include <math.h>

CollisionObject::CollisionObject()
{
    objectType = Ground;
    priority = 3;
    radius = sqrt(Actor::getWidth() * Actor::getWidth() + Actor::getHeight() * Actor::getHeight());
    setCollisionWidthHeight(getWidth(), getHeight());
    movedX = 0;
    movedY = 0;
}

CollisionObject::~CollisionObject()
{
    //dtor
}

bool CollisionObject::isCollision(Actor *object)
{
    if (dynamic_cast<CollisionObject*>(object)==NULL)
        return false;
    //float radius2 = sqrt(object->getWidth() * object->getWidth() + object->getHeight() * object->getHeight());

    if (Actor::get_X() - getWidth()/2 > object->get_X() + object->getWidth()/2)
        return false;
    else if (Actor::get_X() + getWidth()/2 < object->get_X() - object->getWidth()/2)
        return false;
    else if (Actor::get_Y() - getWidth()/2 > object->get_Y() + object->getHeight()/2)
        return false;
    else if (Actor::get_Y() + getWidth()/2 < object->get_Y() - object->getHeight()/2)
        return false;

    return true;
}

float CollisionObject:: getRadius()
{
    return radius;
}

int CollisionObject::getCollisionWidth()
{
    return collisionWidth;
}

int CollisionObject::getCollisionHeight()
{
    return collisionHeight;
}

bool CollisionObject::checkCollisionWithObject(CollisionObject object2)
{
    if ( object2.get_Y()+object2.getCollisionHeight()/2 < get_Y()-getCollisionHeight()/2 ) return false; //if A is more to the left than B
        else if ( object2.get_Y()-object2.getCollisionHeight()/2 > get_Y()+getCollisionHeight()/2 ) return false; //if A is more to the right than B
        else if ( object2.get_X()+object2.getCollisionWidth()/2 < get_X()-getCollisionWidth()/2 ) return false; //if A is higher than B
        else if ( object2.get_X()-object2.getCollisionWidth()/2 > get_X()+getCollisionWidth()/2 ) return false; //if A is lower than B

    return true; //There is a collision because none of above returned false
}

bool CollisionObject::checkCollisionWithObject(CollisionObject *object2)
{
    if ( object2->getColY()+object2->getCollisionHeight()/2 < getColY()-getCollisionHeight()/2 ) return false; //if A is more to the left than B
        else if ( object2->getColY()-object2->getCollisionHeight()/2 > getColY()+getCollisionHeight()/2 ) return false; //if A is more to the right than B
        else if ( object2->getColX()+object2->getCollisionWidth()/2 < getColX()-getCollisionWidth()/2 ) return false; //if A is higher than B
        else if ( object2->getColX()-object2->getCollisionWidth()/2 > getColX()+getCollisionWidth()/2 ) return false; //if A is lower than B

    return true; //There is a collision because none of above returned false
}

void CollisionObject::setCollisionWidthHeight(int newWidth, int newHeight)
{
    collisionWidth = newWidth;
    collisionHeight = newHeight;
}

void CollisionObject::setAnimation(char *animation, int myWidth, int myHeight, int ttime, int animX, int animY)
{
    Actor::setAnimation(animation, myWidth, myHeight, ttime, animX, animY);
    setCollisionWidthHeight(getWidth(), getHeight());

}

void CollisionObject::movePoint(float newMovedX, float newMovedY)
{
    movedX = newMovedX;
    movedY = newMovedY;
}

float CollisionObject::getColX()
{
    return get_X() + movedX;
}

float CollisionObject::getColY()
{
    return get_Y() + movedY;
}

int CollisionObject::getObjectType()
{
    return objectType;
}

void CollisionObject::setObjectType(int newType)
{
    objectType = newType;
}

bool CollisionObject::checkCollision()
{
    Actor *actor = getWorld()->getFirstActor();
    while (actor!=NULL)
    {
        if (dynamic_cast<CollisionObject*>(actor)!=NULL && dynamic_cast<Item*>(actor)==NULL && actor!=this)
        {
            CollisionObject* tempObject = static_cast<CollisionObject*>(actor);
            if (dynamic_cast<CollisionObject*>(actor)->checkCollisionWithObject(this))
            {
                if (tempObject->getObjectType()==getObjectType() || tempObject->getObjectType()==GroundAndAir || getObjectType()==GroundAndAir)
                    return true;
            }

        }
        actor = getWorld()->getNextActor();
    }
    if (get_X()-getWidth()/2<-getWorld()->maxX/2 || get_X()+getWidth()/2>getWorld()->maxX/2
        || get_Y()-getHeight()/2<-getWorld()->maxY/2 || get_Y()+getHeight()/2>getWorld()->maxY/2)
        return true;
    return false;
}

Actor* CollisionObject::checkCollisionO()
{
    Actor *actor = getWorld()->getFirstActor();
    while (actor!=NULL)
    {

        if (dynamic_cast<CollisionObject*>(actor)!=NULL && dynamic_cast<Item*>(actor)==NULL && actor!=this)
        {
            CollisionObject* tempObject = static_cast<CollisionObject*>(actor);
            if (dynamic_cast<CollisionObject*>(actor)->checkCollisionWithObject(this))
            {
                if (tempObject->getObjectType()==getObjectType() || tempObject->getObjectType()==GroundAndAir || getObjectType()==GroundAndAir)
                    return actor;
            }

        }
        actor = getWorld()->getNextActor();
    }
    Actor returnActor;
    if (get_X()-getWidth()/2<-getWorld()->maxX/2 || get_X()+getWidth()/2>getWorld()->maxX/2
        || get_Y()-getHeight()/2<-getWorld()->maxY/2 || get_Y()+getHeight()/2>getWorld()->maxY/2)
        return &returnActor;
    return NULL;
}



