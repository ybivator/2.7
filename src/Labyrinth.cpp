#include <Labyrinth.h>


Labyrinth::Labyrinth(int topLeftX, int topLeftY, unsigned int cellSize)
{
   
   for(unsigned int i = 0; i < m_rows; i++)
   {
      for(unsigned int j = 0; j < m_cols; j++)
      {
	 m_cellArray[i][j].setCellSize(cellSize);
	 m_cellArray[i][j].setTopLeft(topLeftX + (cellSize * i),
	                              topLeftY - (cellSize * j));
      }   
   }
}

void Labyrinth::drawLabyrinth() const
{
   for(unsigned int i = 0; i < m_rows; i++)
   {
      for(unsigned int j = 0; j < m_cols; j++)
      {
	 m_cellArray[i][j].drawCell();
      }
   }
}
