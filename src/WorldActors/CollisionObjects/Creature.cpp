#include "Creature.h"
#include "HealthBar.h"
#include <math.h>
//#include "mygame.h"

Creature::Creature()
{
    lastMove = 0;
    color = 0;
    setSight(450, 0);
    setName("Creature");
    initiateCollisionChecker();
    alive = true;
    bonusHP = 0;
    armor = 0;
    //animationAbeceda = loadTexture("textures/Abeceda.png");
    //ctor
}

Creature::~Creature()
{
    /*printf("removing HB1\n");
    printf("world maxX = %d\n", getWorld()->maxX);
    MyObject* healthBar = getWorld()->getActorAt(getWorld()->getIndexOf(this)+1);
    printf("removing HB2\n");
    if (dynamic_cast<HealthBar*>(healthBar)!=NULL)
    {
        printf("IF 1\n");
        getWorld()->removeActor(healthBar);
        printf("IF 2\n");
    }
    printf("removing HB3\n");*/
    //dtor
}

void Creature::act()
{
    bonusChecking();
    if (getHP()<=0)
        getWorld()->removeActor(this);

}

void Creature::turnAt(int fallowedX, int fallowedY)
{
    //DrawText(1150, 150, 4, intToStr(fallowedX), animationAbeceda);
    float prepona = sqrt((fallowedX - get_X()) * (fallowedX - get_X())
        + (fallowedY - get_Y()) * (fallowedY - get_Y()));
    if (prepona!=0)
    {
        if (get_X() - fallowedX < 0)
            setAngle(asin((get_Y() - fallowedY)/prepona));
        else if (get_X() - fallowedX > 0)
            setAngle(-asin((get_Y()-fallowedY)/prepona)-getPi());
        else if (fallowedY < get_Y())
            setAngle(getPi()/2);
        else
            setAngle(3*getPi()/2);
    }
}

Actor* Creature::moveForward(float distance)
{
    lastMove = movingForward;
    float tempX = get_X();
    float tempY = get_Y();
    bool isCol=false;
    for (float i=0; i<=distance; i++)
    {
        if (i+1>distance)
            i=distance;
        tempX = get_X();
        tempY = get_Y();
        //set_position(tempX, tempY);
        set_position(get_X()+(cos(getAngle())*i), get_Y()-(sin(getAngle())*i));
        Actor* tempActor = checkCollisionO();
        if (tempActor!=NULL)
        {
            set_position(tempX, tempY);
            return tempActor;
        }

    }
    return NULL;
    /*
    set_position(tempX, tempY);
    if (!isCol)
    {
        set_position(get_X()+(cos(getAngle())*distance), get_Y()-(sin(getAngle())*distance));
        if (checkCollision())
        {
            set_position(tempX, tempY);
        }
    }
    return !isCol;
    */
}

Actor* Creature::moveBackward(float distance)
{

    Actor* returnActor = NULL;
    setAngle(getAngle()-M_PI);
    returnActor = moveForward(distance);
    setAngle(getAngle()+M_PI);
    lastMove = movingBackward;
    return returnActor;


    /*float tempX = get_X();
    float tempY = get_Y();
    set_position(get_X()-(cos(getAngle())*distance), get_Y()+(sin(getAngle())*distance));
    if (checkCollision())
        set_position(tempX, tempY);*/
}

Actor* Creature::moveRight(float distance)
{
    Actor* returnActor = NULL;
    setAngle(getAngle()-M_PI/2);
    returnActor = moveForward(distance);
    setAngle(getAngle()+M_PI/2);
    lastMove = movingRight;
    return returnActor;



    /*float tempX = get_X();
    float tempY = get_Y();
    set_position(get_X()-(cos(getAngle()+getPi()/2)*distance), get_Y()+(sin(getAngle()+getPi()/2)*distance));
    if (checkCollision())
        set_position(tempX, tempY);
        */
}

Actor* Creature::moveLeft(float distance)
{
    Actor* returnActor = NULL;
    setAngle(getAngle()+M_PI/2);
    returnActor = moveForward(distance);
    setAngle(getAngle()-M_PI/2);
    lastMove = movingLeft;
    return returnActor;

    /*
    lastMove = movingLeft;
    float tempX = get_X();
    float tempY = get_Y();
    set_position(get_X()-(cos(getAngle()-getPi()/2)*distance), get_Y()+(sin(getAngle()-getPi()/2)*distance));
    if (checkCollision())
        set_position(tempX, tempY);
        */
}

bool Creature::isPathClear(float angle, float speed)
{
    angle = angle * getPi()/180;
    float tempX = get_X();
    float tempY = get_Y();
    float tempAngle = getAngle();
    setAngle(tempAngle + angle);
    set_position(get_X()+(cos(getAngle())*speed), get_Y()-(sin(getAngle())*speed));
    if (checkCollision())
    {
        set_position(tempX, tempY);
        setAngle(tempAngle);
        return false;
    }
    else
    {
        set_position(tempX, tempY);
        setAngle(tempAngle);
        return true;
    }
}

void Creature::setHP(int x)
{
    HP=x;
}

void Creature::heal(int amount)
{
    HP = HP + amount;
    if (HP > getFullHP())
        HP = getFullHP();
}

float Creature::getHP()
{
    return HP;
}

int Creature::getMaxHP()
{
    return maxHP;
}

void Creature::setMaxHP(int newMaxHP)
{
    maxHP = newMaxHP;
}

int Creature::getFullHP()
{
    return maxHP + bonusHP*maxHP/100;
}

bool Creature::isAlive()
{
    if (HP>0)
        return true;
    else return false;
}

void Creature::doDamage(int damage)
{
    if (armor>=100)
        printf("chyba armor >100 !!!\n\n");

    HP = HP - ((float)damage * (100-armor)/100);
    if (HP<=0)
    {
        HP = 0;
        alive = false;
    }
}

bool Creature::initiateCollisionChecker()
{
    collisionChecker.set_position(get_X(), get_Y());
    collisionChecker.setCollisionWidthHeight(getWidth(), getHeight());
    collisionChecker.setAngle(getAngle());
}

void Creature::setSight(int newSight, int newSightAnlge)
{
    sight = newSight;
    sightAngle = newSightAnlge;
}

int Creature::getSight()
{
    return sight;
}

int Creature::getSightAngle()
{
    return sightAngle;
}

void Creature::drawVision()
{
    /*printf("angle = %d\n", getSightAngle());
    float tempX = get_X()+(cos(getAngle()-getSightAngle()/2)*getSight());
    float tempY = get_Y()-(sin(getAngle()-getSightAngle()/2)*getSight());
    drawLine(get_X(), get_Y(), tempX, tempY);
    tempX = get_X()+(cos(getAngle()+getSightAngle()/2)*getSight());
    tempY = get_Y()-(sin(getAngle()+getSightAngle()/2)*getSight());
    drawLine(get_X(), get_Y(), tempX, tempY);*/

    //printf("angle = %d\n", getSightAngle());
    float angleT = getPi() + getAngle()-(getSightAngle()/2 *(getPi() / 180));
    while (angleT < 0)
        angleT +=2*getPi();
    float tempX = get_X()-(cos(angleT)*getSight());
    float tempY = get_Y()+(sin(angleT)*getSight());
    drawLine(get_X(), get_Y(), tempX, tempY);
    angleT = getPi() + getAngle()+(getSightAngle()/2 *(getPi() / 180));
    while (angleT >= 2*getPi())
        angleT -=2*getPi();
    tempX = get_X()-(cos(angleT)*getSight());
    tempY = get_Y()+(sin(angleT)*getSight());
    drawLine(get_X(), get_Y(), tempX, tempY);

    drawEllipse(get_X(), get_Y(), getSight(), getAngle() - (float)(getSightAngle()/2 * getPi()/180.0), getAngle() + (float)(getSightAngle()/2 * getPi()/180.0));
    //drawCircle(get_X(), get_Y(), getSight(), 300);

}

void Creature::drawImage()
{
    if (getWorld()->isVisionShown())
    {
        if (color==0)
            glColor4ub(255,0,0,255);
        else if (color==1)
            glColor4ub(0,255,0,255);
        else if (color==2)
            glColor4ub(0,0,255,255);
        else if (color==3)
            glColor4ub(0,0,0,255);
        if (sightAngle > 0)
            drawVision();
        showObjectsOnSight();
    }
    glColor4ub(255,255,255,255);
    Actor::drawImage();
}

void Creature::setColor(string colorName)
{
    if (colorName.compare("RED") == 0)
        color = 0;
    else if (colorName.compare("GREEN") == 0)
        color = 1;
    else if (colorName.compare("BLUE") == 0)
        color = 2;
    else if (colorName.compare("BLACK") == 0)
        color = 3;

}

std::vector<Actor*> Creature::getActorsOnSight()
{
    std::vector<Actor*> actors;
    if (getSightAngle()<=0)
        return actors;
    Actor* temp = getWorld()->getFirstActor();
    while (temp != NULL)
    {
        if (dynamic_cast<CollisionObject*>(temp)!=NULL)
        {
            float tempX = getAngleOf(temp)+getPi() - getAngle();
            if (tempX>getPi())
                tempX -= getPi()*2;
            else if (tempX<-getPi())
                tempX += getPi()*2;
            tempX = getAbsoluteValue(tempX);
            if (tempX<getPi()/180*getSightAngle()/2)
            {
                if (getRangeOf(temp) <= getSight())
                {
                    actors.push_back(temp);
                    //temp->setMarkCount(getMarkCount()+1);
                }
            }

        }
        temp = getWorld()->getNextActor();
    }
    return actors;
}


void Creature::showObjectsOnSight()
{
    if (getSightAngle()<=0)
        return;
    Actor* temp = getWorld()->getFirstActor();
    while (temp != NULL)
    {
        if (dynamic_cast<CollisionObject*>(temp)!=NULL)
        {
            float tempX = getAngleOf(temp)+getPi() - getAngle();
            if (tempX>getPi())
                tempX -= getPi()*2;
            else if (tempX<-getPi())
                tempX += getPi()*2;
            tempX = getAbsoluteValue(tempX);
            if (tempX<getPi()/180*getSightAngle()/2)
            {
                if (getRangeOf(temp) <= getSight())
                {
                    temp->markObject();
                    //temp->setMarkCount(getMarkCount()+1);
                }
            }

        }
        temp = getWorld()->getNextActor();
    }

}

void Creature::afterWorldSetter()
{
    getWorld()->addActor("HealthBar", 0, 0);
    dynamic_cast<HealthBar*>(getWorld()->getLastActor())->setCreature(this);
}

bool Creature::isPathClear(Point point1, Point point2)
{
    float tempX = get_X();
    float tempY = get_Y();
    float tempAngle = getAngle();

    set_position(point1.x, point1.y);
    turnAt((int)point2.x, (int)point2.y);
    while ((int)get_X() != (int)point2.x && (int)get_Y() != (int)point2.y)
    {
        if (!moveForward(1))
        {
            set_position(tempX, tempY);
            setAngle(tempAngle);
            return false;
        }
    }
    set_position(tempX, tempY);
    setAngle(tempAngle);
    return true;
}

float Creature::getDistanceOf(Actor *object)
{
    return (float)sqrt((get_X()-object->get_X())*(get_X()-object->get_X()) + (get_Y()-object->get_Y())*(get_Y()-object->get_Y()));
}

void Creature::bonusChecking()
{

}



