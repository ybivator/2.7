#include <GL/gl.h>
#include <GL/glu.h>
#include <glutFunctions.h>

void myInit()
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glColor3f(1.f, 1.f, 1.f);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0, windowWidth, 0, windowHeight);
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glFlush();
}
