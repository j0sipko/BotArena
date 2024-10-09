#ifndef MYGAME_H
#define MYGAME_H
#include <sstream>
#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"

class Point
{
    public:
        float x,y;
};

#define movingForward 0
#define movingBackward 1
#define movingLeft 2
#define movingRight 3
#define Walking 0
#define Running 1
#define Standing 2
#define Ground 0
#define Air 1
#define GroundAndAir 2

char* intToStr(int x);
/*
funkcia ktora konvertuje integer na string
*/

GLuint loadTexture( const std::string &fileName );
/*
funkcia, ktora nacita texturu/textury z obrazku <filename>
*/

void drawRectangleRGB(int x1, int y1, int x2, int y2, int red, int green, int blue);
/*
nakresli stvorec rovnobezny s osami x, y s farbou RGB
*/

void DrawText(const int x, int y, const float sizeoftext, char* text);
/*

*/

void DrawTextFromRight(const int x, int y, const float sizeoftext, char* text);
/*

*/

void DrawNumText(const int x, const int y, const float sizeoftext, const int numb);
/*
funkcia, ktora vypise cele cislo (<numb>) ako text, ktory zacina v bode [x,y] o velkosti <sizeoftext>
*/
//void DrawCircle(float cx, float cy, float r, int num_segments);
/*
    funkcia, ktora vykresli kruh so stredom [cx,cy], polomerom <r>, a presnostou (podla velkosti kruhu) <num_segments>
*/
bool checkCollision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh);
/*
    funkcia, ktora zistuje, ci su dva obdlzniky/stvorce, v kolizii, [Ax,Ay] [Bx,By] su lave horne rohy,
    Aw/Bw sirky a Ah,Bh vysky tychto obdlznikov
*/
bool chechCollisionSC(float mX, float mY, float r, float x1, float y1, float x2, float y2);
/*

*/

char* connect(char* text1, char* text2);
/*

*/

void drawLine(float x1, float y1, float x2, float y2);
/*

*/

void drawCircle(float cx, float cy, float r, int num_segments);
/*

*/

void drawEllipse(float cx, float cy, float r, float angle1, float angle2);
/*

*/

void drawRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
/*

*/

float getAbsoluteValue(float value);
/*

*/

extern unsigned int abeceda;

#endif
