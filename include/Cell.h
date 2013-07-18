#ifndef __CELL_H__
#define __CELL_H__

class Cell
{
public:
   Cell(int x = 0, int y = 0,
        char value = 0,
        size_t cellSize = 10);   

   void setTopLeft(int x, int y);
   void setCellSize(size_t size);
   void setWall(int wall, bool state);
   void setValue(char value);
   char getValue() const;
   void drawCell() const;
   void showCell() const;

   bool m_top, m_bottom;
   bool m_left, m_right;
private:
   int m_topLeftX, m_topLeftY;
   char m_value;
   int m_cellSize;
};

#endif /* end of include guard: __CELL_H__ */
