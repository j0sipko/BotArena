#ifndef ANIMATIONGETTER_H
#define ANIMATIONGETTER_H
#include "mygame.h"

struct Animation
{
    char source[40];
    unsigned int animation;
    Animation *next;
};

class AnimationGetter
{
    private:
        Animation *animation;
        Animation *animationPom;
        bool isEmpty;
    public:
        AnimationGetter();
        unsigned int getAnimation(const char* animationSource);
    protected:
};

#endif // ANIMATIONGETTER_H
