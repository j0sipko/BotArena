#ifndef WIZARD_H
#define WIZARD_H
#include "Player.h"

class Wizard : public Player
{
    public:
        Wizard();
        virtual ~Wizard();
        void act();
        void attack(int fireRate);
        void setWizardAnimationNG();
        void setWizardAnimationBlueStaff();
        void setWizardAnimationRedStaff();
        Actor* getDestinationObject();
    protected:
    private:
        int timerRoF;

};

#endif // WIZARD_H
