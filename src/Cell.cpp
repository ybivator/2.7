#include <Cell.h>
#include <GL/gl.h>
#include <iostream>

using std::cout;
using std::endl;

Cell::Cell(int x, int y, unsigned int cellSize):m_top(true), m_bottom(true),
                                       m_left(true), m_right(true),
	                               m_topLeftX(x), m_topLeftY(y),
				       m_cellSize(cellSize)
{
}

void Cell::setTopLeft(int x, int y)
{
   m_topLeftX = x;
   m_topLeftY = y;
}

void Cell::setCellSize(unsigned int size)
{
   m_cellSize = size;
}

void Cell::setWall(int wall, bool state)
{
   if(wall == 1)
   {
      m_top = state;
   }
   else if(wall == 2)
   {
      m_bottom = state;
   }
   else if(wall == 3)
   {
      m_left = state;
   }
   else if(wall == 4)
   {
      m_right = state;
   }
}

void Cell::drawCell() const
{
   if(m_top)
   {
      glBegin(GL_LINES);
         glVertex2i(m_topLeftX, m_topLeftY);
	 glVertex2i(m_topLeftX + m_cellSize, m_topLeftY);
      glEnd();
   }
   if(m_bottom)
   {
      glBegin(GL_LINES);
         glVertex2i(m_topLeftX, m_topLeftY - m_cellSize);
	 glVertex2i(m_topLeftX + m_cellSize, m_topLeftY - m_cellSize);
      glEnd();
   }
   if(m_left)
   {
      glBegin(GL_LINES);
         glVertex2i(m_topLeftX, m_topLeftY);
	 glVertex2i(m_topLeftX, m_topLeftY - m_cellSize);
      glEnd();
   }
   if(m_right)
   {
      glBegin(GL_LINES);
         glVertex2i(m_topLeftX + m_cellSize, m_topLeftY);
	 glVertex2i(m_topLeftX + m_cellSize, m_topLeftY - m_cellSize);
      glEnd();
   }
}

void Cell::showCell() const
{
   cout << "==========" << endl;
   cout << "x = " << m_topLeftX << " y = " << m_topLeftY << endl;
}
