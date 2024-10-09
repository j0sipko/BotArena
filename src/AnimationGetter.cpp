#include "AnimationGetter.h"
#include "mygame.h"
#include <iostream>
using namespace std;

AnimationGetter::AnimationGetter()
{
    isEmpty=true;
    animation = (struct Animation *) malloc( sizeof(struct Animation) );
    animationPom = animation;
}

unsigned int AnimationGetter::getAnimation(const char* animationSource)
{
    animationPom=animation;
    if (isEmpty)
    {
        isEmpty=false;
        //animationPom->source = (char*)malloc(strlen(animationSource));
        strcpy(animationPom->source, animationSource);
        //printf("nova animacia z: %s\n", animationSource);
        animationPom->animation=loadTexture(animationPom->source);
        animationPom->next=NULL;
        return animationPom->animation;
    }
    else
    {
        while (animationPom->next!=NULL)
        {
            //printf("1: %s\n2: %s\n\n", animationSource, animationPom->source);
            if (strcmp(animationSource, animationPom->source) == 0)
                return animationPom->animation;
            animationPom=animationPom->next;
        }
            //printf("1: %s\n2: %s\n\n", animationSource, animationPom->source);
            if (strcmp(animationSource, animationPom->source) == 0)
                return animationPom->animation;

        //printf("animacia nedeklarovana\n");
        animationPom->next = (struct Animation *) malloc( sizeof(struct Animation) );
        animationPom=animationPom->next;
        //animationPom->source = (char*)malloc(strlen(animationSource));
        strcpy(animationPom->source, animationSource);
        //printf("nova animacia z: %s\n", animationSource);
        animationPom->animation=loadTexture(animationPom->source);
        animationPom->next=NULL;
        return animationPom->animation;
    }
}

