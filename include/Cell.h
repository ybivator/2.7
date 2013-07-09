#ifndef __CELL_H__
#define __CELL_H__

class Cell
{
public:
   Cell(int x = 0, int y = 0,
        unsigned int cellSize = 10);   

   void setTopLeft(int x, int y);
   void setCellSize(unsigned int size);
   void setWall(int wall, bool state);
   void drawCell() const;
   void showCell() const;
private:
   bool m_top, m_bottom;
   bool m_left, m_right;
   int m_topLeftX, m_topLeftY;
   int m_cellSize;
};

#endif /* end of include guard: __CELL_H__ */
