#include "World.h"
#include "Gun.h"
#include "Player.h"
#include "mygame.h"
#include "HealthBar.h"
#include "Creature.h"
#include "Dragon.h"
#include "Block1.h"
#include "Block2.h"
#include "Medipack.h"
#include "Helmet.h"
#include "WorldEditor.h"
#include <vector>

World::World()
{
    mapEditorOn = false;
    drawing = false;
    chosenActor = NULL;
    actorCount = 0;
    showVision = false;
    editor = false;
    SDL_ShowCursor(0);
    //maxX = 1920, maxY = 1080;
    maxX = 1366, maxY = 768;
    paused = false;
    sniperMode = false;
    exit = false;
    actor = new Object;
    actor->next = NULL;
    Actor* tempActor;

    WorldEditor* worldEditor = new WorldEditor(this);
    addActor(dynamic_cast<Actor*>(worldEditor), 0,0);
    setCamera(0.0, 0.0);

    //addActor("Player", -maxX/2+100, -maxY/2+100);
    /*tempActor = getLastActor();
    addActor("HealthBar", 0, 0);
    dynamic_cast<HealthBar*>(getLastActor())->setCreature(dynamic_cast<Creature*>(tempActor));*/

    //addActor("Dragon", -maxX/2+100, maxY/2-100);
    /*tempActor = getLastActor();
    addActor("HealthBar", 0, 0);
    dynamic_cast<HealthBar*>(getLastActor())->setCreature(dynamic_cast<Creature*>(tempActor));*/
    //addActor("Dragon", maxX/2-100, maxY/2-100);
    /*tempActor = getLastActor();
    addActor("HealthBar", 0, 0);
    dynamic_cast<HealthBar*>(getLastActor())->setCreature(dynamic_cast<Creature*>(tempActor));*/
    //addActor("Dragon", maxX/2-100, -maxY/2+100);
    /*tempActor = getLastActor();
    addActor("HealthBar", 0, 0);
    dynamic_cast<HealthBar*>(getLastActor())->setCreature(dynamic_cast<Creature*>(tempActor));*/
    /*actor->myObject = new Player();
    static_cast<Actor*>(actor->myObject)->setWorld(this);
    actor->next = new Object;
    actor->next->next = NULL;
    */
    /*addActor("Gun", -200, -350);
    addActor("Gun", -400, 190);
    addActor("Gun", 200, 100);
    addActor("Gun", 450, 300);
    addActor("Medipack", -100, -100);
    addActor("Medipack", 100, 100);
    addActor("Medipack", 250, 300);
    addActor("Medipack", -575, -125);
    addActor("Block1", -150, -150);
    addActor("Block2", -150, 150);
    addActor("Block1", -550, -250);
    addActor("Block2", -50, 80);
    addActor("Block1", 380, 250);
    addActor("Block2", 0, 200);
    addActor("Block1", 400, 0);
    addActor("Block2", 250, 100);
    addActor("Block1", -250, -100);
    addActor("Block2", -110, -250);
    addActor("Block1", 350, -300);
    addActor("Block2", -350, 300);
    addActor("Block1", -280, 200);
    addActor("Block2", -550, 150);*/
    addActor("Background", 0, 0);
    addActor("Scope", 0, 0);
    //clearWorld();
    //addActor("HealthBar", maxX-150-maxX/2, 10-maxY/2);

    /*actor->next->myObject = new Gun();
    static_cast<Actor*>(actor->next->myObject)->setWorld(this);
    actor->next->next = new Object;
    actor->next->next->next = NULL;*/

    //actor->next->myObject->set_position(200,200);
}

void World::clearWorld()
{
    Actor* temp = getFirstActor();
    temp = getNextActor();
    temp = getNextActor();
    //printf("first actor name = %s", temp->getName().c_str());
    removeActor(temp);
   /*while (temp!=NULL)
    {
        if (temp->getName().compare("Scope") == 0)
        {
            temp = getNextActor();
            if (temp==NULL)
                return;
        }
        removeActor(temp);
        temp = getFirstActor();
    }
    */
}

void World::act()
{
    if (paused)
    {
        if (chosenActor!=NULL)
        {
            paused = true;
            chosenActor->set_position(event->mouseX-maxX/2, event->mouseY-maxY/2);
            //printf("actorX = %f\nactorY = %f", pendingActor->get_X(), pendingActor->get_Y());

            if (event->isMouseButtonPressedOnce_Left)
            addActor(chosenActor->getName(), event->mouseX-maxX/2, event->mouseY-maxY/2);
        }
        if (event->isKeyPressedOnce_kb_1)
        {
            if (chosenActor!=NULL)
            {
                printf("actor not null\n");
                removeActor(chosenActor);
            }
            printf("adding dragon1\n");
            chosenActor = new Dragon();
            addActor(chosenActor, event->mouseX-maxX/2, event->mouseY-maxY/2);
            printf("adding dragon2\n");
        }

        if (event->isKeyPressedOnce_kb_2)
        {
            if (chosenActor!=NULL)
                removeActor(chosenActor);
            chosenActor = new Block1();
            addActor(chosenActor, event->mouseX-maxX/2, event->mouseY-maxY/2);
        }

        if (event->isKeyPressedOnce_kb_3)
        {
            if (chosenActor!=NULL)
                removeActor(chosenActor);
            chosenActor = new Block2();
            addActor(chosenActor, event->mouseX-maxX/2, event->mouseY-maxY/2);
        }

        if (event->isKeyPressedOnce_kb_4)
        {
            if (chosenActor!=NULL)
                removeActor(chosenActor);
            chosenActor = new Gun();
            addActor(chosenActor, event->mouseX-maxX/2, event->mouseY-maxY/2);
        }

        if (event->isKeyPressedOnce_kb_5)
        {
            if (chosenActor!=NULL)
                removeActor(chosenActor);
            chosenActor = new Medipack();
            addActor(chosenActor, event->mouseX-maxX/2, event->mouseY-maxY/2);
        }

        if (event->isKeyPressedOnce_kb_6)
        {
            if (chosenActor!=NULL)
                removeActor(chosenActor);
            chosenActor = new Helmet();
            addActor(chosenActor, event->mouseX-maxX/2, event->mouseY-maxY/2);
        }
    }

    if (event->isKeyPressedOnce_kb_P)
    {
        togglePause();
        toggleMapEditor();
        if (chosenActor!=NULL)
            removeActor(chosenActor);
        chosenActor = NULL;
    }

    if (event->isKeyPressedOnce_kb_Esc)
    {
        if (getPlayer() != NULL)
        {
            if (!dynamic_cast<Player*>(getPlayer())->getInventory()->isShown() && !isPaused())
                exit = true;
            else if (isPaused())
            {
                togglePause();
                mapEditorOn = false;
            }

        }
        else exit = true;
    }

    if (event->isKeyPressedOnce_kb_F1)
    {
        swapVision();
    }
    tempActor = actor;
    while (tempActor->next!=NULL)
    {
        tempActor->myObject->unMark();
        if (!isPaused())
        {
            //printf("beforeAct\nActorName = %s\n", tempActor->myObject->getName().c_str());
            tempActor->myObject->act();
            //printf("afterAct\n");
        }
        tempActor = tempActor->next;
    }


    if (getSniperMode())
        glOrtho(getCameraX()[0] -5*maxX/8, getCameraX()[0]+5*maxX/8, getCameraY()[0] + 5*maxY/8, getCameraY()[0] - 5*maxY/8, -1, 1);
    else glOrtho(getCameraX()[0] -maxX/2, getCameraX()[0]+maxX/2, getCameraY()[0] + maxY/2, getCameraY()[0] - maxY/2, -1, 1);

    glColor4ub(255,255,255,255); //White color


  //Enable textures when we are going to blend an texture


    for (int i = 0; i<5; i++)
    {
        tempActor = actor;
        while (tempActor->next!=NULL)
        {
            if (tempActor->myObject->priority == i)
                tempActor->myObject->drawImage();
            tempActor = tempActor->next;
        }
    }
    if (event->isKeyPressed_kb_Tab)
    {
        char temp[25];
        temp[0]='\0';
        sprintf(temp, "HP      ");
        strcat(temp, intToStr(dynamic_cast<Player*>(getPlayer())->getHP() ));
        strcat(temp, "/" );
        strcat(temp, intToStr(dynamic_cast<Player*>(getPlayer())->getFullHP() ));
        //sprintf(temp, intToStr(dynamic_cast<Player*>(getPlayer())->getFullHP() ));
        DrawText(cameraX[0] - maxX/2,  cameraY[0] +25 - maxY/2, 2,
                 temp);

        temp[0]='\0';
        sprintf(temp, "STATE ");
        strcat(temp, intToStr(dynamic_cast<Player*>(getPlayer())->getState() ));
        //sprintf(temp, "Stamina -");      sprintf(temp, intToStr(dynamic_cast<Player*>(getPlayer())->getFullStamina() ));
        DrawText(cameraX[0] - maxX/2,  cameraY[0] +40 - maxY/2, 2,
                 temp);

        temp[0]='\0';
        sprintf(temp, "ARMOR   ");
        strcat(temp, intToStr(dynamic_cast<Player*>(getPlayer())->getArmor() ));
        //sprintf(temp, "Armor   -");     sprintf(temp, intToStr(dynamic_cast<Player*>(getPlayer())->getArmor() ));
        DrawText(cameraX[0] - maxX/2,  cameraY[0] +55 - maxY/2, 2,
                 temp);

        if (dynamic_cast<Player*>(getPlayer())->getWeapon() != NULL)
            DrawText(cameraX[0] - maxX/2,  cameraY[0] +70 - maxY/2, 2, connect("DAMAGE  ",intToStr(dynamic_cast<Gun*>(dynamic_cast<Player*>(getPlayer())->getWeapon())->getDamage())));
            else DrawText(cameraX[0] - maxX/2,  cameraY[0] +70 - maxY/2, 2, "DAMAGE  0");

        //DrawText(cameraX[0] - maxX/2,  cameraY[0] +85 - maxY/2, 2, connect("angle =   ",intToStr((int)((dynamic_cast<Player*>(getPlayer())->getAngle() * 180 / pi )))));
        Actor* tempp = getFirstActor();
        tempp = getNextActor();
        tempp = getNextActor();
        DrawText(cameraX[0] - maxX/2,  cameraY[0] +85 - maxY/2, 2, connect("ANGLE =   ",intToStr((int)(getPlayer()->getAngleOf(tempp) * (180 / pi)))));

        DrawText(cameraX[0] - maxX/2,  cameraY[0] +700 - maxY/2, 2.5, connect("MOUSEX   ",intToStr(event->worldMouseX)));
        DrawText(cameraX[0] - maxX/2,  cameraY[0] +720 - maxY/2, 2.5, connect("MOUSEY   ",intToStr(event->worldMouseY)));
        DrawText(cameraX[0] - maxX/2,  cameraY[0] +745 - maxY/2, 2.5, connect("PLAYERX  ",intToStr(getPlayer()->get_X())));
        DrawText(cameraX[0] - maxX/2,  cameraY[0] +765 - maxY/2, 2.5, connect("PLAYERY  ",intToStr(getPlayer()->get_Y())));
    }


    Player* tempPlayer = dynamic_cast<Player*>(getPlayer());
    if (tempPlayer!=NULL)
        tempPlayer->getInventory()->drawInventory();
    tempActor = actor;
    while (tempActor->next!=NULL)
    {
        if (tempActor->myObject->priority == 5)
            tempActor->myObject->drawImage();
        tempActor = tempActor->next;
    }
    /*glVertex2f(get_X(), get_Y()); //Upper-left corner
    glVertex2f(get_X()+player->getFullHP(), get_Y()); //Upper-right corner
    glVertex2f(get_X()+player->getFullHP(), get_Y()+height); //Down-right corner
    glVertex2f(get_X(), get_Y()+height); //Down-left corner*/
    glEnd();

    /*
    unsigned int *red;
    red = new unsigned int;
    glReadPixels(event->mouseX, 768 - event->mouseY, 1, 1, GL_RED, GL_INT, red);
    DrawNumText(1000, 150, 4, red[0]);

    unsigned int *green;
    green = new unsigned int;
    glReadPixels(event->mouseX, 768 - event->mouseY, 1, 1, GL_GREEN, GL_INT, green);
    DrawNumText(1000, 200, 4, green[0]);

    unsigned int *blue;
    blue = new unsigned int;
    glReadPixels(event->mouseX, 768 - event->mouseY, 1, 1, GL_BLUE, GL_INT, blue);
    DrawNumText(1000, 250, 4, blue[0]);

    free(red);
    free(green);
    free(blue);
    */

    /*
    DrawText(1100, 200, 4, intToStr(iBlue), animationAbeceda);
    DrawText(1100, 250, 4, intToStr(iGreen), animationAbeceda);
    */
}

void World::removeActor(Actor* actorRemoved)
{
    tempActor = actor;
    while (tempActor->next->myObject != actorRemoved && tempActor->next->next!=NULL)
    {
        tempActor = tempActor->next;;
    }
    if (tempActor->next->myObject == actorRemoved)
    {
        delete tempActor->next->myObject;
        tempActor->next = tempActor->next->next;
    }
    actorCount--;
}

void World::removeItem(Actor* actorRemoved)
{
    tempActor = actor;
    while (tempActor->next->myObject != actorRemoved && tempActor->next->next!=NULL)
    {
        tempActor = tempActor->next;;
    }
    if (tempActor->next->myObject == actorRemoved)
    {
        tempActor->next = tempActor->next->next;
    }
    actorCount--;
}

World::~World()
{
    //dtor
}

void World::addActor(string name, float posX, float posY)
{
    if (name.compare("") == 0)
        return;
    tempActor = actor;
    while (tempActor->next!=NULL)
        tempActor = tempActor->next;
    tempActor->myObject = factory.getActor(name);
    tempActor->myObject->set_position(posX,posY);
    static_cast<WorldActor*>(tempActor->myObject)->setWorld(this);
    if ( name.compare("Player") == 0)
        static_cast<Player*>(tempActor->myObject)->getInventory()->setWorld(this);
    tempActor->myObject->setSize(tempActor->myObject->getWidth() * maxX/1366,tempActor->myObject->getHeight() * maxY/768);
    tempActor->next = new Object;
    tempActor->next->next = NULL;
    tempActor->myObject->afterWorldSetter();
    actorCount++;
}

void World::addActor(Actor* newActor, float posX, float posY)
{
    if (newActor == NULL)
        return;
    tempActor = actor;
    while (tempActor->next!=NULL)
    {
        tempActor = tempActor->next;
    }
    //tempActor->myObject = factory.getActor(newActor->getName());
    tempActor->myObject = newActor;
    static_cast<WorldActor*>(tempActor->myObject)->setWorld(this);
    tempActor->myObject->set_position(posX,posY);
    tempActor->next = new Object;
    tempActor->next->next = NULL;
    actorCount++;
}

Actor* World::getFirstActor()
{
    tempActor2 = actor;
    return tempActor2->myObject;
}

Actor* World::getNextActor()
{
    if (tempActor2->next->next!=NULL)
    {
        tempActor2 = tempActor2->next;
        return tempActor2->myObject;
    }
    else return NULL;
}

Actor* World::getLastActor()
{
    tempActor2 = actor;
    if (tempActor->myObject==NULL)
        return NULL;
    while (tempActor2->next->next!=NULL)
    {
        tempActor2 = tempActor2->next;
    }
    return tempActor2->myObject;
}

Actor* World::getPlayer()
{
    Actor* tempActor = getFirstActor();
    while (tempActor!=NULL)
    {
        if (tempActor->getName().compare("Player")==0)
            return tempActor;
        tempActor = getNextActor();
    }
    return NULL;
    //return actor->myObject;
}

Events* World::getEvent()
{
    return event;
}

void World::setEvent(Events *newEvent)
{
    event = newEvent;
}

float* World::getCameraX()
{
    return cameraX;
}

float* World::getCameraY()
{
    return cameraY;
}

void World::setCamera(float x, float y)
{
    free(cameraX);
    free(cameraY);
    cameraX = new float;
    cameraY = new float;
    cameraX[0] = x;
    cameraY[0] = y;
}
void World::setCamera(float* x, float* y)
{
    free(cameraX);
    free(cameraY);
    cameraX = x;
    cameraY = y;
}

void World::toggleSniperMode()
{
    sniperMode = !sniperMode;
}

bool World::getSniperMode()
{
    return sniperMode;
}

bool World::isPaused()
{
    return paused;
}

void World::togglePause()
{
    paused = !paused;
    if (!isPaused())
        setDrawing(false);
}

void World::unPause()
{
    paused = false;
}

void World::pause()
{
    paused = true;
}

bool World::isVisionShown()
{
    return showVision;
}

void World::swapVision()
{
    showVision = !showVision;
}

int World::getActorCount()
{
    return actorCount;
}

Actor* World::getActorAt(int index)
{
    if (index<0)
        return NULL;
    Actor *temp = getFirstActor();
    for (int i=0; i<index; i++)
    {
        if (temp==NULL)
            return NULL;
        temp = getNextActor();
    }
    return temp;
}

Actor* World::removeActorAt(int index)
{
    removeActor(getActorAt(index));
}

int World::getIndexOf(Actor *actor)
{
    int index =0;
    Actor *temp = getFirstActor();
    while (temp!=NULL)
    {
        if (temp==actor)
            return index;
        temp = getNextActor();
        index++;
    }
    return NULL;
}

int World::getCurrentMouseX()
{
    return (getEvent()->mouseX - getCameraX()[0] - maxX/2);
}

int World::getCurrentMouseY()
{
    return (getEvent()->mouseY - getCameraY()[0] - maxY/2);
}

Actor* World::getPendingActor()
{
    return chosenActor;
}

bool World::isDrawing()
{
    return drawing;
}

void World::setDrawing(bool newDrawing)
{
    drawing = newDrawing;
}

std::vector<Actor*> World::getActors()
{
    std::vector<Actor*> actors;
    Actor* temp = getFirstActor();
    while (temp != NULL)
    {
        actors.push_back(temp);
        temp = getNextActor();
    }
    return actors;
}

bool World::isMapEditorOn()
{
    return mapEditorOn;
}

void World::toggleMapEditor()
{
    mapEditorOn = !mapEditorOn;
}



