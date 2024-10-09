#include "HealthBar.h"

HealthBar::HealthBar()
{
    height=5;
    setName("HealthBar");
    priority = 4;
}

HealthBar::~HealthBar()
{
    //dtor
}

void HealthBar::drawImage()
{
    if (creature->getHP()<= 0 || creature==NULL)
    {
        printf("healthBar removed!\n");
        getWorld()->removeActor(this);
    }
    /*printf("name is : %s\n", creature->getName().c_str());
    printf("creature name is : %s\n", creatureName.c_str());*/
    width=creature->getHP()/2;

    glColor4ub(255,0,0,255); //Black color
    glBegin(GL_QUADS);

    glVertex2f(creature->get_X() - creature->getFullHP()/4,                         creature->get_Y() - creature->getHeight()/2); //Upper-left corner
    glVertex2f(creature->get_X() - creature->getFullHP()/4+creature->getFullHP()/2,   creature->get_Y() - creature->getHeight()/2); //Upper-right corner
    glVertex2f(creature->get_X() - creature->getFullHP()/4+creature->getFullHP()/2,   creature->get_Y() - creature->getHeight()/2-height); //Down-right corner
    glVertex2f(creature->get_X() - creature->getFullHP()/4,                         creature->get_Y() - creature->getHeight()/2-height); //Down-left corner
    glEnd();

    glColor4ub(0,255,0,255); //Red color
    glBegin(GL_QUADS);

    glVertex2f(creature->get_X() - creature->getFullHP()/4,         creature->get_Y() - creature->getHeight()/2); //Upper-left corner
    glVertex2f(creature->get_X() - creature->getFullHP()/4+width,   creature->get_Y() - creature->getHeight()/2); //Upper-right corner
    glVertex2f(creature->get_X() - creature->getFullHP()/4+width,   creature->get_Y() - creature->getHeight()/2-height); //Down-right corner
    glVertex2f(creature->get_X() - creature->getFullHP()/4,         creature->get_Y() - creature->getHeight()/2-height); //Down-left corner
    glEnd();
    glColor4ub(255,255,255,255); //Black color
}

void HealthBar::setCreature(Creature* newCreature)
{
    creature = newCreature;
    creatureName = creature->getName();
}

void HealthBar::afterWorldSetter()
{
    /*maxX = getWorld()->maxX;
    maxY = getWorld()->maxY;
    printf("afterWorld HB 1\n");
    if (dynamic_cast<Player*>(getWorld()->getPlayer()) !=NULL)
        setPlayer(dynamic_cast<Player*>(getWorld()->getPlayer()));
    printf("afterWorld HB 2\n");*/
}

