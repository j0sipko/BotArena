#include "Actor.h"
#include <sstream>
#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>

AnimationGetter animationGetter;

Actor::Actor()
{
    setName("basic object");
    ispingpong=false;
    turn=true;
    angle = 0;
    angleDifference = 0;
    moveAngle = angle;
    isStopped=false;
    markCount = 0;
}

Actor::~Actor()
{
    //dtor
}

void Actor::drawImage()
{
    angle = angle + angleDifference;
    glEnable(GL_TEXTURE_2D);
    drawTextureOfUnit();
    glDisable(GL_TEXTURE_2D);
    angle = angle - angleDifference;
}

void Actor::justDrawImage()
{
    angle = angle + angleDifference;
    glEnable(GL_TEXTURE_2D);
    drawTextureOfUnit();
    glDisable(GL_TEXTURE_2D);
    angle = angle - angleDifference;
}

string Actor::getName()
{
    return name;
}

void Actor::setName(string newName)
{
    name = newName;
}

float Actor::setPomX(float x)
{
    pomX = x;
}

float Actor::setPomY(float y)
{
    pomY = y;
}

float* Actor::getX()
{
    return &x;
}

float* Actor::getY()
{
    return &y;
}

bool Actor::checkCollisionWO(Actor obj)
{
    if ( obj.get_Y() < y-height/2 ) return false; //if A is more to the left than B
    else if ( obj.get_Y() > y+height/2 ) return false; //if A is more to the right than B
    else if ( obj.get_X() < x-width/2 ) return false; //if A is higher than B
    else if ( obj.get_X() > x+width/2 ) return false; //if A is lower than B

    return true; //There is a collision because none of above returned false
}

bool Actor::checkCollisionRWP(Actor obj)
{
    if (sqrt( (obj.get_Y()-y)*(obj.get_Y()-y) + (obj.get_X()-x)*(obj.get_X()-x) ) < width/2+obj.getWidth()/3)
        return true; //There is a collision because none of above returned false
        else return false;
}

bool Actor::isPointInCollision(int pointX, int pointY)
{
    /*
    printf("pointCol1\n");
    printf("x = %f\n", get_X());
    printf("y = %f\n", get_Y());
    printf("point X = %d\n", pointX);
    printf("point Y = %d\n", pointY);
    printf("width = %f\n", getWidth());
    printf("height = %f\n", getHeight());
    */
    if (pointX < x+width/2 && pointX > x-width/2 && pointY < y+height/2 && pointY > y-height/2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Actor::deleteOBJ()
{
    delete this;
}

void Actor::act()
{
    ;
    //setAngle(getAngle()+getPi()/40);
}

void Actor::setPingPong(bool x)
{
    ispingpong=x;
}

void Actor::drawTexture()
{
    if (!isStopped)
    {
        if (myTimer==myTime)
        {
            myTimer=0;

            if (pingpong)
            {
                if (curX<animationX)
                    curX++;
                    else if (curY<animationY)
                        {
                            curY++;
                            curX=1;
                        }
                        else
                            {
                                if (ispingpong)
                                    {

                                        pingpong=!pingpong;
                                        curX--;
                                    }
                                    else
                                    {
                                        curX=1;
                                        curY=1;
                                    }
                            }
            }
                else
                {
                    if (curX>1)
                        curX--;
                        else if (curY>1)
                            {
                                curY--;
                                curX=animationX;
                            }
                            else
                                {
                                    pingpong=!pingpong;
                                    curX++;
                                }
                }
        }
        myTimer++;
    }
    glBindTexture(GL_TEXTURE_2D, myAnimation);

    glBegin(GL_QUADS); //Start drawing the pad

  //We set the corners of the texture using glTexCoord2d
    if (turn==false)
    {
        glTexCoord2d(1.0/animationX*(curX-1),1.0/animationY*(curY-1)); glVertex2f(x-width/2, y-height/2); //Upper-left corner
        glTexCoord2d(1.0/animationX*(curX),1.0/animationY*(curY-1)); glVertex2f(x+width/2, y-height/2); //Upper-right corner
        glTexCoord2d(1.0/animationX*(curX),1.0/animationY*(curY)); glVertex2f(x+width/2, y+height/2); //Down-right corner
        glTexCoord2d(1.0/animationX*(curX-1),1.0/animationY*(curY)); glVertex2f(x-width/2, y+height/2); //Down-left corner
    }
    else
    {
        glTexCoord2d(1.0/animationX*(curX),1.0/animationY*(curY-1)); glVertex2f(x-width/2, y-height/2); //Upper-left corner
        glTexCoord2d(1.0/animationX*(curX-1),1.0/animationY*(curY-1)); glVertex2f(x+width/2, y-height/2); //Upper-right corner
        glTexCoord2d(1.0/animationX*(curX-1),1.0/animationY*(curY)); glVertex2f(x+width/2, y+height/2); //Down-right corner
        glTexCoord2d(1.0/animationX*(curX),1.0/animationY*(curY)); glVertex2f(x-width/2, y+height/2); //Down-left corner
    }

    glEnd(); //End drawing
}

void Actor::drawTextureOfUnit()
{
    float r=sqrt((width*width+height*height)*1/4);
    float a=asin(width/2/r);

    aX[0]=x+(cos(angle-a)*r);
    aY[0]=y-(sin(angle-a)*r);
    aX[1]=x+(cos(angle+a)*r);
    aY[1]=y-(sin(angle+a)*r);
    aX[2]=x+(cos(angle+a+2*(pi/2-a))*r);
    aY[2]=y-(sin(angle+a+2*(pi/2-a))*r);
    aX[3]=x+(cos(angle+3*a+2*(pi/2-a))*r);
    aY[3]=y-(sin(angle+3*a+2*(pi/2-a))*r);
    if (!isStopped)
    {
        if (myTimer==myTime)
        {
            myTimer=0;

            if (pingpong)
            {
                if (curX<animationX)
                    curX++;
                    else if (curY<animationY)
                        {
                            curY++;
                            curX=1;
                        }
                        else
                            {
                                if (ispingpong)
                                    {
                                        pingpong=!pingpong;
                                        if (animationX>1)
                                            curX--;
                                        else if (animationY>1)
                                            curY--;
                                    }
                                    else
                                    {
                                        curX=1;
                                        curY=1;
                                    }
                            }
            }
                else
                {
                    if (curX>1)
                        curX--;
                        else if (curY>1)
                            {
                                curY--;
                                curX=animationX;
                            }
                            else
                                {
                                    pingpong=!pingpong;
                                    if (animationX>1)
                                        curX++;
                                        else if (animationY>1)
                                            curY++;
                                }
                }
        }
        myTimer++;
    }
    glBindTexture(GL_TEXTURE_2D, myAnimation);

    glBegin(GL_QUADS); //Start drawing the pad

  //We set the corners of the texture using glTexCoord2d
  if (turn==false)
    {
        glTexCoord2d(1.0/animationX*(curX-1),1.0/animationY*(curY-1)); glVertex2f(aX[0], aY[0]); //Upper-left corner
        glTexCoord2d(1.0/animationX*(curX),1.0/animationY*(curY-1)); glVertex2f(aX[1], aY[1]); //Upper-right corner
        glTexCoord2d(1.0/animationX*(curX),1.0/animationY*(curY)); glVertex2f(aX[2], aY[2]); //Down-right corner
        glTexCoord2d(1.0/animationX*(curX-1),1.0/animationY*(curY)); glVertex2f(aX[3], aY[3]); //Down-left corner
    }
    else
    {
        glTexCoord2d(1.0/animationX*(curX),1.0/animationY*(curY-1)); glVertex2f(aX[0], aY[0]); //Upper-left corner
        glTexCoord2d(1.0/animationX*(curX-1),1.0/animationY*(curY-1)); glVertex2f(aX[1], aY[1]); //Upper-right corner
        glTexCoord2d(1.0/animationX*(curX-1),1.0/animationY*(curY)); glVertex2f(aX[2], aY[2]); //Down-right corner
        glTexCoord2d(1.0/animationX*(curX),1.0/animationY*(curY)); glVertex2f(aX[3], aY[3]); //Down-left corner
    }

    glEnd(); //End drawing
}

bool Actor::isAnimationFinished()
{
    /*printf("animationX = %d\n", animationX);
    printf("animationY = %d\n", animationY);
    printf("curX = %d\n", curX);
    printf("curY = %d\n", curY);*/
    if (animationX==curX && animationY==curY)
        return true;
    else return false;
}

void Actor::setAngle(float thisAngle)
{
    angle=thisAngle;
    if (angle>2*pi)
        angle-=2*pi;
    else if (angle<0)
        angle+=2*pi;
}

float Actor::getAngle()
{
    return angle;
}

void Actor::set_position (float myX,float myY)
{
    x = myX;
    y = myY;
}

void Actor::turnOB()
{
    turn=!turn;
}

bool Actor::getTurn()
{
    return turn;
}

float Actor::getPomX()
{
    return pomX;
}

float Actor::getPomY()
{
    return pomY;
}

bool Actor::getIsStopped()
{
    return isStopped;
}

void Actor::stopAnimation()
{
    isStopped=true;
}

void Actor::startAnimation()
{
    isStopped=false;
}

void Actor::setSize(float widthN, float heightN)
{
    width = widthN;
    height = heightN;
}

float Actor::get_X()
{
    return x;
}

float Actor::get_Y()
{
    return y;
}

float Actor::getWidth()
{
    return width;
}

float Actor::getHeight()
{
    return height;
}

void Actor::setAnimationSpeed(int ttime)
{
    myTime= 1+ttime*80/1000;
    if (myTimer>myTime)
        myTimer=0;

}

void Actor::setAnimation(char *animation, int myWidth, int myHeight, int ttime, int animX, int animY)
{
    /*if (animX==1 && animY==1)
        stopAnimation();
        else startAnimation();*/
    /*if (animX==1 && animY==1)
        stopAnimation();
        else startAnimation();*/
    if (width==myWidth && height==myHeight && myTime==1+ttime*80/1000 && animationX==animX && animationY==animY)
        ;
    else if (width==myWidth && height==myHeight && animationX==animX && animationY==animY)
    {
        if (myTimer>myTime)
            myTimer=0;
        myTime==1+ttime*80/1000;
    }
    else
        {
            myTimer=0;
            pingpong=true;
            curX=1;
            curY=1;

            width= myWidth;
            height= myHeight;
            myTime= 1+ttime*80/1000;
            animationX= animX;
            animationY= animY;
        }
        myAnimation = animationGetter.getAnimation(animation);
}

void Actor::setMyAnimation(unsigned int x)
{
    myAnimation=x;
}

bool Actor::isAnimationStarting()
{
    if (curX==1 && curY==1)
        return true;
    else return false;
}

void Actor::finishAnimation()
{
    pingpong=true;
    curX=1;
    curY=1;
}


unsigned int Actor::getAnimation()
{
    return myAnimation;
}

float Actor::getPi()
{
    return pi;
}

void Actor::afterWorldSetter()
{

}

void Actor::initiate()
{

}

void Actor::setDrawAngleDifference(float newAngle)
{
    angleDifference = newAngle;
}

void Actor::markObject()
{
    markCount++;
    float ax[4], aY[4];
    float r=sqrt((width*width+height*height)*1/4);
    float a=asin(width/2/r);
    r = r+markCount;
    aX[0]=x+(cos(angle-a)*r);
    aY[0]=y-(sin(angle-a)*r);
    aX[1]=x+(cos(angle+a)*r);
    aY[1]=y-(sin(angle+a)*r);
    aX[2]=x+(cos(angle+a+2*(pi/2-a))*r);
    aY[2]=y-(sin(angle+a+2*(pi/2-a))*r);
    aX[3]=x+(cos(angle+3*a+2*(pi/2-a))*r);
    aY[3]=y-(sin(angle+3*a+2*(pi/2-a))*r);

    drawRectangle(aX[0], aY[0], aX[1], aY[1], aX[2], aY[2], aX[3], aY[3]);
}

void Actor::unMark()
{
    markCount = 0;
}

bool Actor::isMarked()
{
    if (markCount >0)
        return true;
    return false;
}

float Actor::getRangeOf(Actor* object2)
{
    return sqrt((x-object2->get_X())*(x-object2->get_X()) + (y-object2->get_Y())*(y-object2->get_Y()));
}

float Actor::getAngleOf(Actor* object2)
{
    /*if (get_X() - fallowedX < 0)
            setAngle(asin((get_Y() - fallowedY)/prepona));
        else if (get_X() - fallowedX > 0)
            setAngle(-asin((get_Y()-fallowedY)/prepona)-getPi());*/
    float temp = asin((x-object2->get_X())/getRangeOf(object2)) - getPi()/2;
    if (temp<0)
        temp+= getPi()*2;
    if (get_Y() - object2->get_Y() < 0)
        return 2*getPi()-temp;
    else return temp;
}

void Actor::setMarkCount(int newNum)
{
    markCount = newNum;
}

int Actor::getMarkCount()
{
    return markCount;
}

void Actor::setCurXY(int newCurX, int newCurY)
{
    curX = newCurX;
    curY = newCurY;
}




