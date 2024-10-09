/*
Compile command:
g++ -o test main.cpp -lSDLmain -lSDL -lGL -lSDL_image
 */

// specific headers
#include <vector>
#include <sstream>
#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
//#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "mygame.h"
#include "AnimationGetter.h"
#include "Actor.h"
#include "Dragon.h"
#include "Player.h"
#include "Gun.h"
#include "World.h"
#include "Events.h"
/*#include "include/Reactor.h"
#include "include/Gun.h"*/
using namespace std;


/*
class Reactor : public MyObject
{
    public:
        Reactor()
        {
            setAngle(getPi()/2);
            //setAnimation("textures/reactor_on.png",50,50,100,4,1);
            setAnimation("textures/reactor_hot.png",100,100,100,4,1);
            //stopAnimation();
        }
};

class Reactor3 : public MyObject
{
    public:
        Reactor3()
        {
            setAngle(getPi()/2);
            //setAnimation("textures/reactor_on.png",50,50,100,4,1);
            setAnimation("textures/reactor_broken.png",100,100,100,4,2);
            //stopAnimation();
        }
};
*/

//start of the program
int main( int argc, char* args[] )
{
    //int maxX = 1920, maxY = 1080;
    int maxX = 1366, maxY = 768;
    /*World *world;
    world = new World();*/
    //maxX = 1366;  maxY = 768;

  //initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

  //Set OpenGL memory usage
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

  //Caption of the window
    SDL_WM_SetCaption( "Aliens", NULL );

  //Size of the window
    SDL_SetVideoMode(maxX, maxY, 32, SDL_OPENGL | SDL_FULLSCREEN);

  //Specific the clear color
    glClearColor(1,1,1,1); //RED,GREEN,BLUE,ALPHA

  //What portion of the screen we will display
    glViewport(0,0, maxX, maxY);

  //Shader model - Use this
    glShadeModel(GL_SMOOTH);

  //2D rendering
    glMatrixMode(GL_PROJECTION);

  //"Save" it
    glLoadIdentity();

  //Disable depth checking
    glDisable(GL_DEPTH_TEST);

  //We enable blending of textures and set how we are going to blend it
    glEnable( GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    std::cout << "OpenGL is running\n";
    std::cout << "Main loop has started\n";

  //Handles the main loop

  //For handling with event
    SDL_Event event;
    //SDL_ShowCursor(0);

    float pi=3.14159265358979323846;

    bool left = false,right = false, up = false, down = false; //we save in which state the button is
    bool left2 = false, right2= false;
    float mouseX, mouseY, pomMouseX, pomMouseY;
    bool mouseClick=false;
    bool mouseClick2=false;
    bool mouseClick3=false;
    bool play=false;
    bool mouseHidden=false;
    float currentX=maxX/2;
    float currentY=maxY/2;
    float prepona;
    int textureNum=0;
    int prevTextureNum=0;
    World *world;
    world = new World();
    Events events;
    world->setEvent(&events);
    world->maxX = maxX;
    world->maxY = maxY;

    //world.player.setGun(1);
    abeceda = loadTexture("textures/Abeceda.png");

    unsigned int animationAbeceda = loadTexture("textures/Abeceda.png");

    /*Player objects[objectNum];
    MYobject pom[objectNum];*/


   /* player.set_position(maxX/2, maxY/2);
    player.setPingPong(true);

    //player.setMyAnimation(animationPlayer);
    player.setGun(0);

    player.stopAnimation();

    */
    float pomX, pomY, pomX2, pomY2;

    Object *objects;
    objects = new Object;
    objects->next = NULL;
    Object *objectsPom;
    objectsPom = objects;

    Actor *reactors;
    Actor *reactorsPom;
    int objectNum=0;

    /*Player* objects = new Player[ objectNum ];
    loadMYobject( objects, objectNum );*/
    //Player *pom[objectNum];

    //unsigned int my_texture = loadTexture("bullet.png");

    /*MYobject objects[0];
    Player player[0];
    objects[0]=player;
    //Enemy enemy[0];
    objects[0]=player;
    objects[1]=enemy;*/
    //player.setAnimation(loadTexture("bullet.png"));

  //Main game loop
    while ( !world->exit )
    {
      //EVENTS
        while ( SDL_PollEvent(&event) )
        {
          //if the window was closed
            if ( event.type == SDL_QUIT )
            {
                world->exit = true;
            }

          //If a button was released and the button is escape
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE )
            {
                events.isKeyPressed_kb_Esc = true;
                events.isKeyPressedOnce_kb_Esc = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE )
            {
                events.isKeyPressed_kb_Esc = false;
            }
            // next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DELETE )
            {
                events.isKeyPressed_kb_Del = true;
                events.isKeyPressedOnce_kb_Del = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_DELETE )
            {
                events.isKeyPressed_kb_Del = false;
            }
            // next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q )
            {
                events.isKeyPressed_kb_Q = true;
                events.isKeyPressedOnce_kb_Q = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_q )
            {
                events.isKeyPressed_kb_Q = false;
            }
            // next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w )
            {
                events.isKeyPressed_kb_W = true;
                events.isKeyPressedOnce_kb_W = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_w )
            {
                events.isKeyPressed_kb_W = false;
            }
            // next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_e )
            {
                events.isKeyPressed_kb_E = true;
                events.isKeyPressedOnce_kb_E = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_e )
            {
                events.isKeyPressed_kb_E = false;
            }
            // next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r )
            {
                events.isKeyPressed_kb_R = true;
                events.isKeyPressedOnce_kb_R = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r )
            {
                events.isKeyPressed_kb_R = false;
            }
            // next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_t )
            {
                events.isKeyPressed_kb_T = true;
                events.isKeyPressedOnce_kb_T = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_t )
            {
                events.isKeyPressed_kb_T = false;
            }
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_y )
            {
                events.isKeyPressed_kb_Y = true;
                events.isKeyPressedOnce_kb_Y = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_y )
            {
                events.isKeyPressed_kb_Y = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_u )
            {
                events.isKeyPressed_kb_U = true;
                events.isKeyPressedOnce_kb_U = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_u )
            {
                events.isKeyPressed_kb_U = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_i )
            {
                events.isKeyPressed_kb_I = true;
                events.isKeyPressedOnce_kb_I = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_i )
            {
                events.isKeyPressed_kb_I = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_o )
            {
                events.isKeyPressed_kb_O = true;
                events.isKeyPressedOnce_kb_O = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_o )
            {
                events.isKeyPressed_kb_O = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p )
            {
                events.isKeyPressed_kb_P = true;
                events.isKeyPressedOnce_kb_P = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_p )
            {
                events.isKeyPressed_kb_P = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a )
            {
                events.isKeyPressed_kb_A = true;
                events.isKeyPressedOnce_kb_A = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_a )
            {
                events.isKeyPressed_kb_A = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s )
            {
                events.isKeyPressed_kb_S = true;
                events.isKeyPressedOnce_kb_S = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_s )
            {
                events.isKeyPressed_kb_S = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d )
            {
                events.isKeyPressed_kb_D = true;
                events.isKeyPressedOnce_kb_D = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_d )
            {
                events.isKeyPressed_kb_D = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_f )
            {
                events.isKeyPressed_kb_F = true;
                events.isKeyPressedOnce_kb_F = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_f )
            {
                events.isKeyPressed_kb_F = false;
            }
            //nextv
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_g )
            {
                events.isKeyPressed_kb_G = true;
                events.isKeyPressedOnce_kb_G = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_g )
            {
                events.isKeyPressed_kb_G = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_h )
            {
                events.isKeyPressed_kb_H = true;
                events.isKeyPressedOnce_kb_H = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_h )
            {
                events.isKeyPressed_kb_H = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_j )
            {
                events.isKeyPressed_kb_J = true;
                events.isKeyPressedOnce_kb_J = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_j )
            {
                events.isKeyPressed_kb_J = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_k )
            {
                events.isKeyPressed_kb_K = true;
                events.isKeyPressedOnce_kb_K = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_k )
            {
                events.isKeyPressed_kb_K = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_l )
            {
                events.isKeyPressed_kb_L = true;
                events.isKeyPressedOnce_kb_L = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_l )
            {
                events.isKeyPressed_kb_L = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_z )
            {
                events.isKeyPressed_kb_Z = true;
                events.isKeyPressedOnce_kb_Z = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_z )
            {
                events.isKeyPressed_kb_Z = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_x )
            {
                events.isKeyPressed_kb_X = true;
                events.isKeyPressedOnce_kb_X = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_x )
            {
                events.isKeyPressed_kb_X = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_c )
            {
                events.isKeyPressed_kb_C = true;
                events.isKeyPressedOnce_kb_C = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_c )
            {
                events.isKeyPressed_kb_C = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_v )
            {
                events.isKeyPressed_kb_V = true;
                events.isKeyPressedOnce_kb_V = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_v )
            {
                events.isKeyPressed_kb_V = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_b )
            {
                events.isKeyPressed_kb_B = true;
                events.isKeyPressedOnce_kb_B = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_b )
            {
                events.isKeyPressed_kb_B = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_n )
            {
                events.isKeyPressed_kb_N = true;
                events.isKeyPressedOnce_kb_N = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_n )
            {
                events.isKeyPressed_kb_N = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m )
            {
                events.isKeyPressed_kb_M = true;
                events.isKeyPressedOnce_kb_M = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_m )
            {
                events.isKeyPressed_kb_M = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_TAB )
            {
                events.isKeyPressed_kb_Tab = true;
                events.isKeyPressedOnce_kb_Tab = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_TAB )
            {
                events.isKeyPressed_kb_Tab = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LSHIFT )
            {
                events.isKeyPressed_kb_Lshift = true;
                events.isKeyPressedOnce_kb_Lshift = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_LSHIFT )
            {
                events.isKeyPressed_kb_Lshift = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RSHIFT )
            {
                events.isKeyPressed_kb_Rshift = true;
                events.isKeyPressedOnce_kb_Rshift = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_RSHIFT )
            {
                events.isKeyPressed_kb_Rshift = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LCTRL )
            {
                events.isKeyPressed_kb_Lctrl = true;
                events.isKeyPressedOnce_kb_Lctrl = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_LCTRL )
            {
                events.isKeyPressed_kb_Lctrl = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RCTRL )
            {
                events.isKeyPressed_kb_Rctrl = true;
                events.isKeyPressedOnce_kb_Rctrl = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_RCTRL )
            {
                events.isKeyPressed_kb_Rctrl = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LALT )
            {
                events.isKeyPressed_kb_Lalt = true;
                events.isKeyPressedOnce_kb_Lalt = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_LALT)
            {
                events.isKeyPressed_kb_Lalt = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RALT )
            {
                events.isKeyPressed_kb_Ralt = true;
                events.isKeyPressedOnce_kb_Ralt = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_RALT)
            {
                events.isKeyPressed_kb_Ralt = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE )
            {
                events.isKeyPressed_kb_Space = true;
                events.isKeyPressedOnce_kb_Space = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
            {
                events.isKeyPressed_kb_Space = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_KP_ENTER) )
            {
                events.isKeyPressed_kb_Enter = true;
                events.isKeyPressedOnce_kb_Enter = true;
                mouseClick2=true;
            }
            if ( event.type == SDL_KEYUP && (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_KP_ENTER) )
            {
                events.isKeyPressed_kb_Enter = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F1 )
            {
                events.isKeyPressed_kb_F1 = true;
                events.isKeyPressedOnce_kb_F1 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_F1 )
            {
                events.isKeyPressed_kb_F1 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F2 )
            {
                events.isKeyPressed_kb_F2 = true;
                events.isKeyPressedOnce_kb_F2 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_F2 )
            {
                events.isKeyPressed_kb_F2 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F3 )
            {
                events.isKeyPressed_kb_F3 = true;
                events.isKeyPressedOnce_kb_F3 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_F3 )
            {
                events.isKeyPressed_kb_F3 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_1 )
            {
                events.isKeyPressed_kb_1 = true;
                events.isKeyPressedOnce_kb_1 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_1 )
            {
                events.isKeyPressed_kb_1 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_2 )
            {
                events.isKeyPressed_kb_2 = true;
                events.isKeyPressedOnce_kb_2 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_2 )
            {
                events.isKeyPressed_kb_2 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_3 )
            {
                events.isKeyPressed_kb_3 = true;
                events.isKeyPressedOnce_kb_3 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_3 )
            {
                events.isKeyPressed_kb_3 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_4 )
            {
                events.isKeyPressed_kb_4 = true;
                events.isKeyPressedOnce_kb_4 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_4 )
            {
                events.isKeyPressed_kb_4 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_5 )
            {
                events.isKeyPressed_kb_5 = true;
                events.isKeyPressedOnce_kb_5 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_5 )
            {
                events.isKeyPressed_kb_5 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_6 )
            {
                events.isKeyPressed_kb_6 = true;
                events.isKeyPressedOnce_kb_6 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_6 )
            {
                events.isKeyPressed_kb_6 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_7 )
            {
                events.isKeyPressed_kb_7 = true;
                events.isKeyPressedOnce_kb_7 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_7 )
            {
                events.isKeyPressed_kb_7 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_8 )
            {
                events.isKeyPressed_kb_8 = true;
                events.isKeyPressedOnce_kb_8 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_8 )
            {
                events.isKeyPressed_kb_8 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_9 )
            {
                events.isKeyPressed_kb_9 = true;
                events.isKeyPressedOnce_kb_9 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_9 )
            {
                events.isKeyPressed_kb_9 = false;
            }
            //next
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_0 )
            {
                events.isKeyPressed_kb_0 = true;
                events.isKeyPressedOnce_kb_0 = true;
            }
            if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_0 )
            {
                events.isKeyPressed_kb_0 = false;
            }
            //next



            if ( event.type == SDL_MOUSEMOTION )
            {
                events.mouseX = event.motion.x;
                events.mouseY = event.motion.y;
            }

            if( event.type == SDL_MOUSEBUTTONDOWN )
            {
                if( event.button.button == SDL_BUTTON_LEFT )
                {
                    events.isMouseButtonPressedOnce_Left = true;
                    events.isMouseButtonPressed_Left = true;
                }
                if( event.button.button == SDL_BUTTON_RIGHT )
                {
                    events.isMouseButtonPressedOnce_Right = true;
                    events.isMouseButtonPressed_Right = true;
                }
                if( event.button.button == SDL_BUTTON_MIDDLE )
                {
                    events.isMouseButtonPressedOnce_Middle = true;
                    events.isMouseButtonPressed_Middle = true;
                }

            }
            if( event.type == SDL_MOUSEBUTTONUP )
            {
                if( event.button.button == SDL_BUTTON_LEFT )
                {
                    events.isMouseButtonPressed_Left = false;
                    /*if (play)
                        player.setShot(false);*/
                }
                if( event.button.button == SDL_BUTTON_RIGHT )
                {
                    events.isMouseButtonPressed_Right = false;
                }
                if( event.button.button == SDL_BUTTON_MIDDLE )
                {
                    events.isMouseButtonPressed_Middle = false;
                }
            }

            if( event.type == SDL_MOUSEBUTTONDOWN )
            {
                if( event.button.button == SDL_BUTTON_WHEELUP )
                {
                    events.isMouseWheel_Up = true;
                }
                if( event.button.button == SDL_BUTTON_WHEELDOWN )
                {
                    events.isMouseWheel_Down = true;
                }
            }
        }

    //LOGIC

    events.worldMouseX = world->getCameraX()[0] - world->maxX/2 + events.mouseX;
    events.worldMouseY = world->getCameraY()[0] - world->maxY/2 + events.mouseY;
    /*
    if (!dynamic_cast<Player*>(world->getPlayer())->getInventory()->isShown())
    {
        if (events.isMouseButtonPressedOnce_Left)
        {
            world->addActor("Dragon", world->getCameraX()[0] - world->maxX/2 + events.mouseX,
                            world->getCameraY()[0] - world->maxY/2 + events.mouseY);
        }
        else if (events.isMouseButtonPressedOnce_Right)
        {
            world->addActor("Player", world->getCameraX()[0] - world->maxX/2 + events.mouseX,
                            world->getCameraY()[0] - world->maxY/2 + events.mouseY);
        }
        else if (events.isMouseButtonPressedOnce_Middle)
        {
            world->addActor("Gun", world->getCameraX()[0] - world->maxX/2 + events.mouseX,
                            world->getCameraY()[0] - world->maxY/2 + events.mouseY);
        }
    }
    */


  //RENDERING to the screen
    glClear(GL_COLOR_BUFFER_BIT);

    glColor4ub(255,255,255,255); //White color

    glPushMatrix(); //Start rendering phase

    //glOrtho(0,maxX,maxY,0,-1,1); //Set the matrix
    /*
    if (world->getSniperMode())
        glOrtho(world->getCameraX()[0] -5*maxX/8, world->getCameraX()[0]+5*maxX/8, world->getCameraY()[0] + 5*maxY/8, world->getCameraY()[0] - 5*maxY/8, -1, 1);
    else glOrtho(world->getCameraX()[0] -maxX/2, world->getCameraX()[0]+maxX/2, world->getCameraY()[0] + maxY/2, world->getCameraY()[0] - maxY/2, -1, 1);

    glColor4ub(255,255,255,255); //White color

  //Enable textures when we are going to blend an texture
    glEnable(GL_TEXTURE_2D);
    */

      //What texture we are going to use

    /*objectsPom = objects;
    while (objectsPom->next!=NULL)
    {
        if ( dynamic_cast<Gun*>(objectsPom->myObject) != NULL)
        {
            static_cast<Gun*>(objectsPom->myObject)->setWorld(world);
        }
        objectsPom->myObject->act();
        if ( dynamic_cast<Gun*>(objectsPom->myObject) != NULL)
        {
            world = static_cast<Gun*>(objectsPom->myObject)->getWorld();
        }
        objectsPom = objectsPom->next;
    }*/
    /*if (world->getSniperMode())
        glOrtho(world->getCameraX()[0] -5*maxX/8, world->getCameraX()[0]+5*maxX/8, world->getCameraY()[0] + 5*maxY/8, world->getCameraY()[0] - 5*maxY/8, -1, 1);
    else glOrtho(world->getCameraX()[0] -maxX/2, world->getCameraX()[0]+maxX/2, world->getCameraY()[0] + maxY/2, world->getCameraY()[0] - maxY/2, -1, 1);*/

    world[0].act();
    //world[0].getPlayer()->act();

    /*for (int i=0; i<objectNum; i++)
        {
            reactors[i].act();
        }*/
    //object.act();


    /*
    glColor4ub(0,0,0,255); //Black color
    glBegin(GL_QUADS);

    glVertex2f(maxX/2+0,0); //Upper-left corner
    glVertex2f(maxX/2+maxX/2,0); //Upper-right corner
    glVertex2f(maxX/2+maxX/2,maxY); //Down-right corner
    glVertex2f(maxX/2+0,maxY); //Down-left corner
    glEnd();
    */


    glEnd(); //End drawing

    glPopMatrix(); //End rendering phase

    SDL_GL_SwapBuffers();

    mouseClick = false;
    mouseClick2 = false;
    mouseClick3 = false;

    events.isKeyPressedOnce_kb_0 = false;
    events.isKeyPressedOnce_kb_1 = false;
    events.isKeyPressedOnce_kb_2 = false;
    events.isKeyPressedOnce_kb_3 = false;
    events.isKeyPressedOnce_kb_4 = false;
    events.isKeyPressedOnce_kb_5 = false;
    events.isKeyPressedOnce_kb_6 = false;
    events.isKeyPressedOnce_kb_7 = false;
    events.isKeyPressedOnce_kb_8 = false;
    events.isKeyPressedOnce_kb_9 = false;
    events.isKeyPressedOnce_kb_A = false;
    events.isKeyPressedOnce_kb_B = false;
    events.isKeyPressedOnce_kb_C = false;
    events.isKeyPressedOnce_kb_D = false;
    events.isKeyPressedOnce_kb_E = false;
    events.isKeyPressedOnce_kb_F = false;
    events.isKeyPressedOnce_kb_G = false;
    events.isKeyPressedOnce_kb_H = false;
    events.isKeyPressedOnce_kb_I = false;
    events.isKeyPressedOnce_kb_J = false;
    events.isKeyPressedOnce_kb_K = false;
    events.isKeyPressedOnce_kb_L = false;
    events.isKeyPressedOnce_kb_M = false;
    events.isKeyPressedOnce_kb_N = false;
    events.isKeyPressedOnce_kb_O = false;
    events.isKeyPressedOnce_kb_P = false;
    events.isKeyPressedOnce_kb_Q = false;
    events.isKeyPressedOnce_kb_R = false;
    events.isKeyPressedOnce_kb_S = false;
    events.isKeyPressedOnce_kb_T = false;
    events.isKeyPressedOnce_kb_U = false;
    events.isKeyPressedOnce_kb_V = false;
    events.isKeyPressedOnce_kb_W = false;
    events.isKeyPressedOnce_kb_X = false;
    events.isKeyPressedOnce_kb_Y = false;
    events.isKeyPressedOnce_kb_Z = false;
    events.isKeyPressedOnce_kb_Lalt = false;
    events.isKeyPressedOnce_kb_Lctrl = false;
    events.isKeyPressedOnce_kb_Lshift = false;
    events.isKeyPressedOnce_kb_Ralt = false;
    events.isKeyPressedOnce_kb_Rctrl = false;
    events.isKeyPressedOnce_kb_Rshift = false;
    events.isKeyPressedOnce_kb_Tab = false;
    events.isKeyPressedOnce_kb_Space = false;
    events.isKeyPressedOnce_kb_Esc = false;
    events.isKeyPressedOnce_kb_Del = false;
    events.isKeyPressedOnce_kb_F1 = false;
    events.isKeyPressedOnce_kb_F2 = false;
    events.isKeyPressedOnce_kb_F3 = false;
    events.isMouseButtonPressedOnce_Left = false;
    events.isMouseButtonPressedOnce_Right = false;
    events.isMouseButtonPressedOnce_Middle = false;
    events.isMouseWheel_Up = false;
    events.isMouseWheel_Down = false;

/*    if (!player.getAutoFire())
        player.setShot(false);
        */

    SDL_Delay(1000/100); //Delay / pause
    }

    SDL_Quit();

    /*myObject Objectt;
    Objectt.set_position (3,4);
    cout << "area: " << Objectt.get_X();
    */

    return 0;
}
