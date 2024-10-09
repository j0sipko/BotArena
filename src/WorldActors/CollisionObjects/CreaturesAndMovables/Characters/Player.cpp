#include "Player.h"
#include "Bullet.h"

Player::Player()
{
    setBonuses(0, 0, 0);
    setSight(500, 50);
    setHP(100);
    setMaxHP(100);
    //maxHP = 100;
    setName("Player");
    weapon = NULL;
    helmet = NULL;
    //printf("create inv\n");
    inventory = new Inventory();
    inventory->setOwner(this);
    inventory->setWorld(this->getWorld());
    //printf("create inv end\n");
    //animationAbeceda = loadTexture("textures/Abeceda.png");
    priority = 2;
    setPingPong(true);
    numberOfGuns=3;
    //ammunition= new int[numberOfGuns];
    damage=10;
    rateOfFire=5;
    timerRoF=rateOfFire;
    range=500;
    autoFire=true;
    //ammunition[0]=1000;
    maxStamina=1000;
    stamina=maxStamina;
    //HP=100;
    armor = 0;
    bonusStamina = 0;
    percentBonusHP = 0;
    percentBonusStamina = 0;
    shot=false;
    setAngle(getAngle()-getPi()/2);
    setAnimation("textures/Soldier2NG.png",35,35,100,5,1);
    //setAnimation("textures/enemySold1.png",35,35,100,5,1);
    stopAnimation();
    setGun(0);
    doDamage(50);
    setColor("BLUE");
    timerRoF = 0;
    //rateOfFire = 10;
    state = Standing;
    setTeam(1);
    //printf("player added\n");
}

Player::~Player()
{
    //dtor
    delete inventory;
}

Inventory* Player::getInventory()
{
    return inventory;
}

int Player::getTeam()
{
    return team;
}

void Player::setTeam(int newTeam)
{
    team = newTeam;
}

/*
void Player::setAmmunitionForGun(int GunNumber, int NewAmmo)
{
    ammunition[GunNumber-1]= NewAmmo;
}
*/

void Player::setGun(int gunNumber)
{
    if (gunNumber==0)
        setPlayerAnimationNG();
        else setPlayerAnimation();
    currentGun=gunNumber;
}

void Player::setPlayerAnimation()
{
    setAnimation("textures/Soldier2Gun1.png",35,35,100,5,1);
    //setAnimation("textures/enemySold1.png",getWidth(),getHeight(),100,5,1);
}

void Player::setPlayerAnimationNG()
{
    setAnimation("textures/Soldier2NG.png",35,35,100,5,1);
    //setAnimation("textures/enemySold1NG.png",getWidth(),getHeight(),100,5,1);
}

void Player::setPlayerAnimationSniper()
{
    setAnimation("textures/Soldier2Gun2.png",35,35,100,5,1);
}

int Player::getRange()
{
    return range;
}

void Player::AutoFire()
{
    autoFire=!autoFire;
}

bool Player::getAutoFire()
{
    return autoFire;
}

bool Player::getShotPermission()
{
    if (timerRoF<=0)
        return true;
        else return false;
}

void Player::giveShotPermission()
{
    timerRoF=0;
}

void Player::act()
{
    inventory->act();
    //printf("begin \n");
    Actor *tempActor;
    tempActor = getWorld()->getFirstActor();
    while (tempActor!=NULL)
    {
        //printf("wile1 \n");
        if(tempActor!=this)
        {
            //printf("tempactor not this \n");
            if (CollisionObject::isCollision(tempActor))
                DrawText(100, 250, 4, "IS COLLISION");
        }
        //else printf("tempactor is this \n");
        tempActor = getWorld()->getNextActor();
        //printf("wile2 \n");
    }
    //printf("wile End \n");
    if (getInventory()->isShown() && !getWorld()->isPaused())
        getWorld()->togglePause();
    else if (!getInventory()->isShown() && getWorld()->isPaused())
        getWorld()->togglePause();
    if (!getWorld()->isPaused() && isAlive())
    {
        turnAt(getWorld()->getCameraX()[0] -getWorld()->maxX/2 + getWorld()->getEvent()->mouseX,
               getWorld()->getCameraY()[0] -getWorld()->maxY/2 + getWorld()->getEvent()->mouseY);
        if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_W || WorldActor::getWorld()->getEvent()->isKeyPressed_kb_S
            || WorldActor::getWorld()->getEvent()->isKeyPressed_kb_A || WorldActor::getWorld()->getEvent()->isKeyPressed_kb_D)
        {
            if (state==Standing)
            {
                printf("starting animation\n");
                startAnimation();
            }

            if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_Lshift)
            {
                if (state!=Running)
                {
                    setAnimationSpeed(50);
                    state = Running;
                }

                if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_W)
                    moveForward(2);
                if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_S)
                    moveBackward(2);
                if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_A)
                    moveLeft(2);
                if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_D)
                    moveRight(2);
            }
            else
            {
                if (state!=Walking)
                {
                    setAnimationSpeed(100);
                    state = Walking;
                }

                if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_W)
                    moveForward(1);
                if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_S)
                    moveBackward(1);
                if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_A)
                    moveLeft(1);
                if (WorldActor::getWorld()->getEvent()->isKeyPressed_kb_D)
                    moveRight(1);
            }
        }
        else
        {
            if (state!=Standing)
            {
                state = Standing;
                stopAnimation();
            }

        }

        if (WorldActor::getWorld()->getEvent()->isMouseButtonPressed_Left)
        {
            WeaponInstance *tempWeapon = dynamic_cast<WeaponInstance*>(getWeapon());
            if (tempWeapon != NULL && tempWeapon->isAutomatic())
                shoot();
        }

        if (WorldActor::getWorld()->getEvent()->isMouseButtonPressedOnce_Left)
        {
            WeaponInstance *tempWeapon = dynamic_cast<WeaponInstance*>(getWeapon());
            if (tempWeapon != NULL && !tempWeapon->isAutomatic())
                shoot();
        }

        if (WorldActor::getWorld()->getEvent()->isKeyPressedOnce_kb_Q)
            getWorld()->toggleSniperMode();
    }
        else stopAnimation();

    /*if (getShot())
    {*/
        if (timerRoF>0)
            timerRoF--;
        //rateOfFire;
    /*}
    else timerRoF=0;*/
        Creature::act();
}

void Player::act2()
{
    if (inventory->getWorld()==NULL)
    {
        printf("world is null\n");
        inventory->setWorld(this->getWorld());
    }
    inventory->act();
    if (getInventory()->isShown() && !getWorld()->isPaused())
        getWorld()->togglePause();
    else if (!getInventory()->isShown() && getWorld()->isPaused())
        getWorld()->togglePause();
    if (timerRoF>0)
        timerRoF--;
    Creature::act();
}

int Player::getGun()
{
    return currentGun;
}

int Player::getStamina()
{
    return stamina;
}

void Player::setStamina(int newStamina)
{
    stamina=newStamina;
}

/*int Player::getAmmo()
{
    if (currentGun>0)
        return ammunition[currentGun-1];
        else return 0;
}

void Player::setAmmo(int newAmmo)
{
    ammunition[currentGun-1]=newAmmo;
}*/

bool Player::getShot()
{
    return shot;
}

void Player::setShot(bool isShot)
{
    if (currentGun!=0)
        shot = isShot;
}

float Player::getDamage()
{
    return damage;
}

void Player::setDamage(float newDamage)
{
    damage= newDamage;
}

void Player::setRateOfFire(float newRateOfFire)
{
    rateOfFire= newRateOfFire;
}

void Player::setArmor(int newArmor)
{
    armor = newArmor;
}

int Player::getArmor()
{
    return armor;
}

void Player::setBonusHP(int newHP)
{
    bonusHP = newHP;
}

int Player::getBonusHP()
{
    return bonusHP;
}

void Player::setBonusStamina(int newStamina)
{
    bonusStamina = newStamina;
}

int Player::getBonusStamina()
{
    return bonusStamina;
}

int Player::getMaxHP()
{
    return maxHP;
}

int Player::getMaxStamina()
{
    return maxStamina;
}

void Player::setMaxHP(int newHP)
{
    maxHP = newHP;
}

void Player::setMaxStamina(int newStamina)
{
    maxStamina = newStamina;
}

int Player::getFullStamina()
{
    return maxStamina + bonusStamina*maxStamina/100;
}

void Player::setHelmet(Equipable *newHelmet)
{
    helmet = newHelmet;
}

Equipable* Player::getHelmet()
{
    return helmet;
}

void Player::setWeapon(Equipable *newWeapon)
{
    weapon = newWeapon;
}

Equipable* Player::getWeapon()
{
    if (weapon != NULL && weapon->isEquipped())
        return weapon;
    else return NULL;
}

void Player::shoot()
{
    if (weapon!=NULL && weapon->isEquipped() && (timerRoF==0))
    {
        getWorld()->addActor("Bullet", get_X(), get_Y());
        getWorld()->removeActorAt(getWorld()->getActorCount()-1);
        Bullet* temp = dynamic_cast<Bullet*>(getWorld()->getActorAt(getWorld()->getActorCount()-1));
        /*printf("actorCount = %d\n", getWorld()->getActorCount());
        printf("lastActorIndex = %d\n", getWorld()->getIndexOf(getWorld()->getActorAt(getWorld()->getActorCount()-1)));*/
        temp->setPlayer(this);
        temp->initiate();
        WeaponInstance *tempWeapon = dynamic_cast<WeaponInstance*>(weapon);
        timerRoF+= tempWeapon->getFireRate();
    }
}

int Player::getState()
{
    return state;
}

Actor* Player::moveForward(float distance)
{
    return Creature::moveForward(distance + (getSpeedBonus()/100.0)*distance);
}

void Player::setBonuses(int newSpeedBonus, int newDPS, double seconds)
{
    speedBonus = newSpeedBonus;
    if (speedBonus>100)
        speedBonus = 100;
    else if (speedBonus < -100)
        speedBonus = -100;
    dps = newDPS;
    bonusTime = seconds;
    startTime = time(0);
    lastSecond=0;
}

int Player::getDPS()
{
    return dps;
}

int Player::getSpeedBonus()
{
    return speedBonus;
}

void Player::bonusChecking()
{
    //printf("!!!checking bonuses\n");
    //printf("!!!bonus time is %lf\n", bonusTime);
    if (bonusTime>0)
    {
        time_t tempTime = time(0);
        if (difftime(tempTime, startTime)>=bonusTime)
        {
            setBonuses(0,0,0);
        }
        else if (difftime(tempTime, startTime)>=lastSecond)
        {
            doDamage(getDPS());
            lastSecond++;
        }
    }
}


