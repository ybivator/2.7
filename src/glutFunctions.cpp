#include <GL/gl.h>
#include <GL/glu.h>
#include <glutFunctions.h>
#include <Cell.h>
#include <Labyrinth.h>

void myInit()
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glColor3f(0.f, 0.f, 0.f);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0, windowWidth, 0, windowHeight);
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   Labyrinth lab1(200, 700, 50);

   lab1.drawLabyrinth();

   glFlush();
}
