#include <GL/gl.h>
#include <GL/glu.h>
#include <glutFunctions.h>
#include <Cell.h>
#include <Labyrinth.h>
#include <cstdlib>

void myInit()
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glColor3f(0.f, 0.f, 0.f);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0, windowWidth, 0, windowHeight);
}

size_t rows = 50;
size_t cols = 50;
size_t cell = 10;
Labyrinth lab1(0, windowHeight, rows, cols, cell);

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   lab1.makeLabyrinth();
   lab1.drawLabyrinth();

   glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
   switch(key)
   {
      case 'r':
	 lab1.cleanLabyrinth();
	 glClear(GL_COLOR_BUFFER_BIT);
         lab1.makeLabyrinth();
	 lab1.drawLabyrinth();
	 break;
      case 'q':
         exit(0);
	 break;
      default:
         break;
   }
   glFlush();
}
