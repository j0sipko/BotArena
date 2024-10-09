#ifndef MYOBJECT_H
#define MYOBJECT_H
#include "mygame.h"
#include "AnimationGetter.h"
#include <stdio.h>
using namespace std;

extern AnimationGetter animationGetter;

class Actor
{
    private:
        float x,y, pomX, pomY;
        int width, height;
        unsigned int myAnimation;
        int animationX, animationY, myTime, curX, curY;
        int myTimer;
        bool ispingpong;
        bool pingpong;
        bool isStopped;
        float angle;
        float angleDifference;
        float moveAngle;
        float aX[4], aY[4];
        float pi=3.14159265358979323846;
        bool turn;
        unsigned int emptyAnimation;
        string name;
        int markCount;

    public:
        string getName();
        void setName(string newName);
        bool isPointInCollision(int pointX, int pointY);
        float *getX();
        float *getY();
        void printWithoutBG();
        void setMoveAngle();
        float getMoveAngle();
        Actor();
        virtual~Actor();
        virtual void afterWorldSetter();
        virtual void initiate();
        int priority;
        bool checkCollisionWO(Actor obj);
        bool checkCollisionRWP(Actor obj);
        void deleteOBJ();
        virtual void act();
        virtual void drawImage();
        void justDrawImage();
        void setPingPong(bool x);
        void drawTexture();
        void drawTextureOfUnit();
        bool isAnimationFinished();
        void setAngle(float thisAngle);
        float getAngle();
        void set_position (float myX,float myY);
        void turnOB();
        bool getTurn();
        float getPomX();
        float getPomY();
        float setPomX(float x);
        float setPomY(float y);
        bool getIsStopped();
        void stopAnimation();
        void startAnimation();
        void setSize(float widthN, float heightN);
        float get_X();
        float get_Y();
        float getWidth();
        float getHeight();
        void setAnimationSpeed(int ttime);
        virtual void setAnimation(char *animation, int myWidth, int myHeight, int ttime, int animX, int animY);
        void setMyAnimation(unsigned int x);
        bool isAnimationStarting();
        void finishAnimation();
        unsigned int getAnimation();
        float getPi();
        void setDrawAngleDifference(float newAngle);
        void markObject();
        void unMark();
        bool isMarked();
        float getRangeOf(Actor* object2);
        float getAngleOf(Actor* object2);
        void setMarkCount(int newNum);
        int getMarkCount();
        void setCurXY(int newCurX, int newCurY);

};

struct Object
{
    Actor *myObject;
    Object *next;
};

#endif // MYOBJECT_H
