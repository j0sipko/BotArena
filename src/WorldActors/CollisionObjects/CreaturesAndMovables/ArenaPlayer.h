#ifndef ARENAPLAYER_H
#define ARENAPLAYER_H
#include "Player.h"

class ArenaPlayer : public Player
{
    public:
        ArenaPlayer();
        virtual ~ArenaPlayer();
        void act() final;
        void moveForward();
        void moveBackward();
        void moveLeft();
        void moveRight();
        void turnLeft();
        void turnRight();
        void setRunning(bool newRunning);
        void shoot();
        virtual void actFunction();
        bool isPathClear(float angle);
        bool isRunning();
        void turnAtPoint(int x, int y);

    protected:

    private:
        float speed, turningSpeed;
        bool running, moved, turned;
        bool isMoving, isTurning, turning;

};

#endif // ARENAPLAYER_H
