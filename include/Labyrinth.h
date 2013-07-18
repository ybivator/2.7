#ifndef __LABYRINTH_H__
#define __LABYRINTH_H__
#include <Cell.h>
#include <vector>

class Labyrinth
{
public:
   Labyrinth(int topLeftX, int topLeftY,
             size_t rows, size_t cols,
             size_t cellSize = 10);
   ~Labyrinth();

   void drawLabyrinth() const;
   void makeLabyrinth();
   void cleanLabyrinth();

private:
   size_t m_rows;
   size_t m_cols;
   size_t m_size;

   Cell* m_cellArray;
   std::vector<size_t> m_randArray;

   size_t giveEmptyWalls(size_t i);
   size_t giveRandomWall(size_t i);

};

#endif /* end of include guard: __LABYRINTH_H__ */
