#include "mygame.h"
#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <sstream>
#include <string.h>
using namespace std;

char* intToStr(int x)
{
    stringstream strs;
    strs << x;
    string temp_str = strs.str();
    char* char_type = (char*) temp_str.c_str();
    return char_type;
    /*
    int x2=x;
    int lenght=1;
    if (x<0)
        lenght=2;
    while (x2/10!=0)
    {
        lenght++;
        x2=x2/10;
    }
    char text[lenght];
    sprintf(text, "%d", x);
    return text;
    */
}

char* connect(char* text1, char* text2)
{
    //printf("text1 = %s  text2 = %s\n", text1, text2);
    string str1(text2);
    string str2(text1);
    //printf("str1 = %s  str2 = %s\n", str1.c_str(), str2.c_str());
    string returnString;
    if (text2!=NULL)
        returnString = str2 + str1;
        else returnString = str1;
    char* char_type = (char*) returnString.c_str();
    return char_type;

}

GLuint loadTexture( const std::string &fileName )
{
    SDL_Surface *image = IMG_Load( fileName.c_str() );

    SDL_DisplayFormatAlpha(image);

    unsigned object(0);

    glGenTextures(1, &object);

    glBindTexture(GL_TEXTURE_2D, object);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

  //Free surface
    SDL_FreeSurface(image);

    return object;
}

void drawRectangleRGB(int x1, int y1, int x2, int y2, int red, int green, int blue)
{
        glColor4ub(red,green,blue,255); //Black color
        glBegin(GL_LINES);

        glVertex2f(x1,y1); //Upper-left corner
        glVertex2f(x2,y1); //Upper-right corner

        glVertex2f(x2,y1); //Upper-right corner
        glVertex2f(x2,y2); //Down-right corner

        glVertex2f(x2,y2); //Down-right corner
        glVertex2f(x1,y2); //Down-right corner

        glVertex2f(x1,y2); //Down-right corner
        glVertex2f(x1,y1); //Upper-left corner
    glEnd();
}




void DrawNumText(const int x, const int y, const float sizeoftext, const int numb)
{
    char text[10];
    sprintf(text, "%d", numb);
    DrawText(x,y,sizeoftext,text);
    /*for (int i=0; i<strlen(text); i++)
    {
    if (text[i]=='1')
        glBindTexture(GL_TEXTURE_2D,N_texture[1]);
        else if (text[i]=='2')
            glBindTexture(GL_TEXTURE_2D,N_texture[2]);
        else if (text[i]=='3')
            glBindTexture(GL_TEXTURE_2D,N_texture[3]);
        else if (text[i]=='4')
            glBindTexture(GL_TEXTURE_2D,N_texture[4]);
        else if (text[i]=='5')
            glBindTexture(GL_TEXTURE_2D,N_texture[5]);
        else if (text[i]=='6')
            glBindTexture(GL_TEXTURE_2D,N_texture[6]);
        else if (text[i]=='7')
            glBindTexture(GL_TEXTURE_2D,N_texture[7]);
        else if (text[i]=='8')
            glBindTexture(GL_TEXTURE_2D,N_texture[8]);
        else if (text[i]=='9')
            glBindTexture(GL_TEXTURE_2D,N_texture[9]);
        else if (text[i]=='0')
            glBindTexture(GL_TEXTURE_2D,N_texture[0]);
//
        glBegin(GL_QUADS); //Start drawing character

      //We set the corners of the texture using glTexCoord2d

        glTexCoord2d(0,0); glVertex2f(x+i*5*sizeoftext, y-10*sizeoftext); //Upper-left corner
        glTexCoord2d(1,0); glVertex2f(x+10*sizeoftext+i*5*sizeoftext, y-10*sizeoftext); //Upper-right corner
        glTexCoord2d(1,1); glVertex2f(x+10*sizeoftext+i*5*sizeoftext, y);  //Down-right corner
        glTexCoord2d(0,1); glVertex2f(x+i*5*sizeoftext, y);  //Down-left corner

        glEnd();
    }*/
    //free(textt);
}

unsigned int abeceda;

void DrawTextFromRight(const int x, int y, const float sizeoftext, char* text)
{
    int tempX = x - strlen(text)*(6.5*sizeoftext);
    DrawText(tempX, y, sizeoftext, text);
}

void DrawText(const int x, int y, const float sizeoftext, char* text)
{
    glEnable(GL_TEXTURE_2D);
    float pos=6.5;
    int xx;
    int yy;
    int j=0;
    //printf("%c\n***\n",text[0]);
    for (int i=0; i<strlen(text); i++)
    {
        xx=((int)(text[i])-'A')%5;
        yy=((int)(text[i])-'A')/5;
        if (text[i]==' ')
        {
            xx=4;
            yy=5;
        }
        else if (text[i]=='!')
        {
            xx=1;
            yy=5;
        }
        else if (text[i]=='.')
        {
            xx=2;
            yy=5;
        }
        else if (text[i]=='?')
        {
            xx=3;
            yy=5;
        }
        else if (text[i]=='-')
        {
            xx=0;
            yy=8;
        }
        else if (text[i]==',')
        {
            xx=1;
            yy=8;
        }
        else if (text[i]=='/')
        {
            xx=2;
            yy=8;
        }
        else if (text[i]=='(')
        {
            xx=3;
            yy=8;
        }
        else if (text[i]==')')
        {
            xx=4;
            yy=8;
        }
        if (text[i]>='0' && text[i]<='9')
        {
            xx=((int)(text[i])-'0')%5;
            yy=((int)(text[i])-'0')/5+6;
        }

        //printf("i= %d xx= %d yy= %d\n***\n", i, xx, yy);
        if (text[i]=='\n')
        {
            j=0;
            y-=sizeoftext*10;
        }
        else
        {
            glBindTexture(GL_TEXTURE_2D,abeceda);
    //
            glBegin(GL_QUADS); //Start drawing character

          //We set the corners of the texture using glTexCoord2d

            glTexCoord2d(1.0/5*xx,1.0/9*yy); glVertex2f(x+j*pos*sizeoftext, y-10*sizeoftext); //Upper-left corner
            glTexCoord2d(1.0/5*(xx+1),1.0/9*yy); glVertex2f(x+10*sizeoftext+j*pos*sizeoftext, y-10*sizeoftext); //Upper-right corner
            glTexCoord2d(1.0/5*(xx+1),1.0/9*(yy+1)); glVertex2f(x+10*sizeoftext+j*pos*sizeoftext, y);  //Down-right corner
            glTexCoord2d(1.0/5*xx,1.0/9*(yy+1)); glVertex2f(x+j*pos*sizeoftext, y);  //Down-left corner

            glEnd();

        j++;
        }
    }
    glDisable(GL_TEXTURE_2D);
}


//Function for loading an image into an texture

void drawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}

void drawEllipse(float cx, float cy, float r, float angle1, float angle2)
{
	//glBegin(GL_LINE_LOOP);
	while (angle1 < angle2)
	{
		float theta = 3.1415926f / 2 + angle1;//get the current angle

		float x = r * sinf(theta);//calculate the x component
		float y = r * cosf(theta);//calculate the y component
		float x2 = r * sinf(theta+0.02);//calculate the x component
		float y2 = r * cosf(theta+0.02);//calculate the y component

		drawLine(x+ cx, y+ cy, x2+ cx, y2+ cy);

		//glVertex2f(x + cx, y + cy);//output vertex
		angle1 +=0.02;

	}
	//glEnd();
}

void drawLine(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

bool checkCollision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh) //Funcfion for checking collision
{
    if ( Ay+Ah < By ) return false; //if A is more to the left than B
    else if ( Ay > By+Bh ) return false; //if A is more to the right than B
    else if ( Ax+Aw < Bx ) return false; //if A is higher than B
    else if ( Ax > Bx+Bw ) return false; //if A is lower than B

    return true; //There is a collision because none of above returned false
}

bool chechCollisionSC(float mX, float mY, float r, float x1, float y1, float x2, float y2)
{
    float k, q;
    bool ishigher;
    int maxX = 1366, maxY = 768;
    float xX, yY;
    float pi=3.14159265358979323846;
        //y=kx+q
        k=(x1-x2)/(y1-y2);
        q=y1-k*x1;
        if (maxY>k*x1+q)
            ishigher=true;
        else ishigher=false;
    for (int i=0; i<2*pi; i+=pi/8)
    {
        xX=mX+cos(i)*r;
        yY=mY+sin(i)*r;
        if ((xX>=x1) && (xX<=x2))
        {
            if (ishigher==true)
            {
                if (yY>=k*xX+q)
                    return true;
                    //else return false;
            }
            else if (ishigher==false)
            {
                if (yY<=k*xX+q)
                    return true;
                    //else return false;
            }
        }
    }
    return false;
}

void drawRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_LINES);

        glVertex2f(x1,y1); //Upper-left corner
        glVertex2f(x2,y2); //Upper-right corner

        glVertex2f(x2,y2); //Upper-right corner
        glVertex2f(x3,y3); //Down-right corner

        glVertex2f(x3,y3); //Down-right corner
        glVertex2f(x4,y4); //Down-right corner

        glVertex2f(x4,y4); //Down-right corner
        glVertex2f(x1,y1); //Upper-left corner
    glEnd();
}

float getAbsoluteValue(float value)
{
    if (value<0)
        return -value;
    else return value;
}








