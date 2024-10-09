#include "WorldEditor.h"
#include "Player.h"
#include "Dragon.h"
#include "Medipack.h"
#include "Gun.h"
#include "Helmet.h"
#include "Block1.h"
#include "Block2.h"
#include "SniperRifle.h"
#include "ActorFactory.h"
#include "Tree.h"
#include "Wizard.h"
#include "StaffBlue.h"
#include "StaffRed.h"
#include "Soldier.h"

WorldEditor::WorldEditor(World* world)
{
    setWorld(world);
    setName("WorldEditor");
    priority = 5;
    pendingActor = NULL;
    addActor(new Player());
    addActor(new Dragon());
    addActor(new Medipack());
    addActor(new Gun());
    addActor(new SniperRifle());
    addActor(new StaffBlue());
    addActor(new StaffRed());
    addActor(new Wizard());
    addActor(new Helmet());
    addActor(new Block1());
    addActor(new Block2());
    addActor(new Tree());
    //addActor(new Soldier());


    //ctor
}

WorldEditor::~WorldEditor()
{
    //dtor
}

void WorldEditor::act()
{
    for (int i=0; i<actors.size(); i++)
    {
        if (actors.at(i)->isPointInCollision(getWorld()->getCurrentMouseX(), getWorld()->getCurrentMouseY()))
        {
            glColor4ub(0,50,255,255);
            if (!actors.at(i)->isMarked())
                actors.at(i)->markObject();
            glColor4ub(255,255,255,255);
        }
        actors.at(i)->unMark();
    }
    if (getWorld()->isPaused() && getWorld()->isMapEditorOn())
    {
        if (pendingActor!=NULL)
        {
            pendingActor->set_position(getWorld()->getCurrentMouseX(), getWorld()->getCurrentMouseY());
        }
        if (getWorld()->getEvent()->isMouseButtonPressedOnce_Right)
        {
            delete pendingActor;
            pendingActor = NULL;
            getWorld()->setDrawing(false);
        }
        if (getWorld()->getEvent()->isMouseButtonPressedOnce_Left)
        {

            for (int i=0; i<actors.size(); i++)
            {
                if (actors.at(i)->isPointInCollision(getWorld()->getCurrentMouseX(), getWorld()->getCurrentMouseY()))
                {
                    getWorld()->setDrawing(true);
                    if (pendingActor!=NULL)
                    {
                        printf("deleting PA\n");
                        printf("PA name = %s\n", pendingActor->getName().c_str());
                        delete pendingActor;
                        printf("deleted PA\n");
                    }
                    pendingActor = factory.getActor(actors.at(i)->getName());
                    dynamic_cast<WorldActor*>(pendingActor)->setWorld(getWorld());
                    pendingActor->set_position(getWorld()->getCurrentMouseX(), getWorld()->getCurrentMouseY());
                    return;
                }
            }

            if (pendingActor!=NULL)
            {
                CollisionObject* temp= dynamic_cast<CollisionObject*>(pendingActor);
                if (temp!=NULL && !temp->checkCollision())
                    getWorld()->addActor(pendingActor->getName(), getWorld()->getCurrentMouseX(), getWorld()->getCurrentMouseY());
            }
        }
    }
    else getWorld()->setDrawing(false);
}

void WorldEditor::drawImage()
{
    if (getWorld()->isPaused() && getWorld()->isMapEditorOn())
    {
        act();
        for (int i=0; i<actors.size(); i++)
        {
            actors.at(i)->justDrawImage();
        }
        if (pendingActor!=NULL)
            pendingActor->justDrawImage();
    }
}

void WorldEditor::addActor(Actor *actor)
{
    actor->setSize(50,50);
    if (actors.size()==0)
    {
        actor->set_position(26 - getWorld()->maxX/2, 26 - getWorld()->maxY/2);
    }

    else actor->set_position(actors.at(actors.size()-1)->get_X(), actors.at(actors.size()-1)->get_Y()+50);

    actors.push_back(actor);
}
