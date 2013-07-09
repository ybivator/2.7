#ifndef __LABYRINTH_H__
#define __LABYRINTH_H__
#include <Cell.h>

class Labyrinth
{
public:
   Labyrinth(int topLeftX, int topLeftY,
             unsigned int cellSize = 10);
   
   void drawLabyrinth() const;

private:
   static const unsigned int m_rows = 5;
   static const unsigned int m_cols = 5;

   Cell m_cellArray[m_rows][m_cols];

};

#endif /* end of include guard: __LABYRINTH_H__ */
