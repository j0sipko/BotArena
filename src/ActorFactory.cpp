#include "ActorFactory.h"
#include "Player.h"
#include "Gun.h"
#include "Dragon.h"
#include "Helmet.h"
#include "Block1.h"
#include "Block2.h"
#include "Tree.h"
#include "Background.h"
#include "Medipack.h"
#include "Scope.h"
#include "Bullet.h"
#include "HealthBar.h"
#include "Soldier.h"
#include "Fireball.h"
#include "SmallExplosion.h"
#include "IceExplosion.h"
#include "SniperRifle.h"
#include "Wizard.h"
#include "StaffBlue.h"
#include "StaffRed.h"
#include "IceBlast.h"
#include "FireBlast.h"


ActorFactory::ActorFactory()
{
    //ctor
}

ActorFactory::~ActorFactory()
{
    //dtor
}

Actor *ActorFactory::getActor(string name)
{
    if (name.compare("Player") == 0)
        return new Player();
    else if (name.compare("Gun") == 0)
        return new Gun();
    else if (name.compare("Dragon") == 0)
        return new Dragon();
    else if (name.compare("Helmet") == 0)
        return new Helmet();
    else if (name.compare("Block1") == 0)
        return new Block1();
    else if (name.compare("Block2") == 0)
        return new Block2();
    else if (name.compare("Background") == 0)
        return new Background();
    else if (name.compare("Medipack") == 0)
        return new Medipack();
    else if (name.compare("Scope") == 0)
        return new Scope();
    else if (name.compare("Bullet") == 0)
        return new Bullet();
    else if (name.compare("HealthBar") == 0)
        return new HealthBar();
    else if (name.compare("ArenaPlayer") == 0)
        return new Soldier();
    else if (name.compare("Fireball") == 0)
        return new Fireball();
    else if (name.compare("SmallExplosion") == 0)
        return new SmallExplosion();
    else if (name.compare("Tree") == 0)
        return new Tree();
    else if (name.compare("SniperRifle") == 0)
        return new SniperRifle();
    else if (name.compare("Wizard") == 0)
        return new Wizard();
    else if (name.compare("StaffBlue") == 0)
        return new StaffBlue();
    else if (name.compare("StaffRed") == 0)
        return new StaffRed();
    else if (name.compare("IceBlast") == 0)
        return new IceBlast();
    else if (name.compare("FireBlast") == 0)
        return new FireBlast();
    else if (name.compare("IceExplosion") == 0)
        return new IceExplosion();
}
