#include <GL/glut.h>
#include <glutFunctions.h>


int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutInitWindowSize(windowWidth, windowHeight);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Labyrinth");
   
   glutDisplayFunc(display);

   myInit();
   glutMainLoop();

   return 0;
}