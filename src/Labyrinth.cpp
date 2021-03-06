#include <iostream>
#include <cstdlib>
#include <Labyrinth.h>
#include <ctime>

using std::cout;
using std::endl;


Labyrinth::Labyrinth(int topLeftX, int topLeftY, size_t rows,
                     size_t cols, size_t cellSize)
{
   
   m_rows = rows;
   m_cols = cols;
   m_size = m_rows * m_cols;
   m_cellArray = new Cell [m_size];
   size_t i = 0;
   size_t j = 0;
   int x = topLeftX;
   int y = topLeftY;
   for(size_t index = 0; index < m_size; index++)
   {
      if(j == m_cols)
      {
	 x = topLeftX;
	 y -= cellSize;
	 j = 0;
	 i = 0;
      }
      m_cellArray[index].setCellSize(cellSize);
      m_cellArray[index].setTopLeft(x + (cellSize * i), y);
      j++;
      i++;
   }
}

Labyrinth::~Labyrinth()
{
   delete [] m_cellArray;
}


void Labyrinth::drawLabyrinth() const
{
   for(size_t i = 0; i < m_size; i++)
   {
      m_cellArray[i].drawCell();
   }
}

void Labyrinth::makeLabyrinth()
{
   srand(time(NULL));
   int index = 0;
   index = rand() % m_size;
   m_cellArray[index].setValue(1);

   while(true)
   {
      size_t wall = giveRandomWall(index);
      if(wall == 1)
      {
         m_cellArray[index].m_top = false;
	 index = index - m_cols;
	 m_cellArray[index].setValue(1);
	 m_cellArray[index].m_bottom = false;
      }
      else if(wall == 2)
      {
         m_cellArray[index].m_right = false;
	 index = index + 1;
	 m_cellArray[index].setValue(1);
	 m_cellArray[index].m_left = false;
      }
      else if(wall == 4)
      {
         m_cellArray[index].m_bottom = false;
	 index = index + m_cols;
	 m_cellArray[index].setValue(1);
	 m_cellArray[index].m_top = false;
      }
      else if(wall == 8)
      {
         m_cellArray[index].m_left = false;
	 index = index - 1;
	 m_cellArray[index].setValue(1);
	 m_cellArray[index].m_right = false;
      }
      else
      {
         if(m_randArray.size() == 0)
         {
            break;
         }
	 size_t j = rand() % m_randArray.size();
	 index = m_randArray[j];
	 m_randArray.erase(m_randArray.begin() + j);
      }
   }
   
}

void Labyrinth::cleanLabyrinth()
{
   for(size_t i = 0; i < m_size; i++)
   {
      m_cellArray[i].setValue(0);
      m_cellArray[i].m_bottom = true;
      m_cellArray[i].m_top = true;
      m_cellArray[i].m_left = true;
      m_cellArray[i].m_right = true;
   }
}

size_t Labyrinth::giveEmptyWalls(size_t i)
{
   size_t walls = 0;
   if(i % m_cols == 0)
   {
      if((i - m_cols) < m_size && 
          m_cellArray[i-m_cols].getValue() == 0)
      {
         walls += 1;
      }
      if((i + 1) < m_size && 
          m_cellArray[i+1].getValue() == 0)
      {
         walls += 2;
      }
      if((i + m_cols) < m_size &&
          m_cellArray[i+m_cols].getValue() == 0)
      {
         walls += 4;
      }
   }
   else if(i % m_cols == (m_cols - 1))
   {
      if((i - m_cols) < m_size &&
          m_cellArray[i-m_cols].getValue() == 0)
      {
         walls += 1;
      }
      if((i - 1) < m_size &&
          m_cellArray[i-1].getValue() == 0)
      {
         walls += 8;
      }
      if((i + m_cols) < m_size &&
          m_cellArray[i+m_cols].getValue() == 0)
      {
         walls += 4;
      }
   }
   else
   {
      if((i - m_cols) < m_size &&
          m_cellArray[i-m_cols].getValue() == 0)
      {
         walls += 1;
      }
      if((i + 1) < m_size &&
          m_cellArray[i+1].getValue() == 0)
      {
         walls += 2;
      }
      if((i + m_cols) < m_size &&
          m_cellArray[i+m_cols].getValue() == 0)
      {
         walls += 4;
      }
      if((i - 1) < m_size &&
          m_cellArray[i-1].getValue() == 0)
      {
         walls += 8;
      }
   }
   return walls;
}

size_t Labyrinth::giveRandomWall(size_t i)
{
   size_t randArray[4];
   size_t randIndex = 0;
   size_t emptyWall = giveEmptyWalls(i);

   if(emptyWall == 0)
   {
      return 0;
   }

   while(emptyWall != 0)
   {
      if(emptyWall < 2)
      {
         randArray[randIndex] = 1;
	 emptyWall -= 1;
      }
      else if(emptyWall < 4)
      {
         randArray[randIndex] = 2;
	 emptyWall -= 2;
	 m_randArray.push_back(i);
      }
      else if(emptyWall < 8)
      {
         randArray[randIndex] = 4;
	 emptyWall -= 4;
	 m_randArray.push_back(i);
      }
      else
      {
         randArray[randIndex] = 8;
	 emptyWall -= 8;
	 m_randArray.push_back(i);
      }
      randIndex++;
   }
   size_t ind = rand() % randIndex;
   return randArray[ind];
}
