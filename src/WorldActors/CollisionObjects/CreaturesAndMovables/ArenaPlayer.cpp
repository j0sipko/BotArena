#include <math.h>
#include "ArenaPlayer.h"

ArenaPlayer::ArenaPlayer()
{
    setName("ArenaPlayer");
    running = false;
    speed = 1;
    turningSpeed = getPi()/40;
    moved = false;
    isMoving = false;
    turning = false;

}

ArenaPlayer::~ArenaPlayer()
{
    //dtor
}

void ArenaPlayer::act()
{
    moved = false;
    turned = false;
    actFunction();
    act2();
    if (isMoving)
        startAnimation();
    else stopAnimation();
    isMoving = false;
}

void ArenaPlayer::moveForward()
{
    isMoving = true;
    if (!moved)
        Creature::moveForward(speed);
    moved = true;
}

void ArenaPlayer::moveBackward()
{
    isMoving = true;
    if (!moved)
        Creature::moveBackward(speed);
    moved = true;
}

void ArenaPlayer::moveLeft()
{
    isMoving = true;
    if (!moved)
        Creature::moveLeft(speed);
    moved = true;

}

void ArenaPlayer::moveRight()
{
    isMoving = true;
    if (!moved)
        Creature::moveRight(speed);
    moved = true;
}

void ArenaPlayer::turnLeft()
{
    if (!turned)
        setAngle(getAngle() + turningSpeed);
    turned = true;
}

void ArenaPlayer::turnRight()
{
    if (!turned)
        setAngle(getAngle() - turningSpeed);
    turned = true;
}

void ArenaPlayer::setRunning(bool newRunning)
{
    running = running;
    if (running)
        speed = 2;
    else speed = 1;
}

void ArenaPlayer::shoot()
{
    Player::shoot();
}

bool ArenaPlayer::isPathClear(float angle)
{
    angle = angle * getPi()/180;
    float tempX = get_X();
    float tempY = get_Y();
    float tempAngle = getAngle();
    setAngle(tempAngle + angle);
    set_position(get_X()+(cos(getAngle()+angle)*speed), get_Y()-(sin(getAngle()+angle)*speed));
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

void ArenaPlayer::actFunction()
{
    if (isPathClear(0))
        moveForward();
    else turnRight();
}

bool ArenaPlayer::isRunning()
{
    return running;
}

void ArenaPlayer::turnAtPoint(int x, int y)
{
    turning =true;
    float tempAngle = getAngle();
    turnAt(x, y);
    float turnAngle=getAngle();
    setAngle(tempAngle);
    if (turnAngle-tempAngle < turningSpeed && turnAngle-tempAngle > -turningSpeed)
    {
        turning = false;
        return;
    }
    if (tempAngle-turnAngle<getPi() && tempAngle-turnAngle>-getPi())
        turnLeft();
    else turnRight();
}


