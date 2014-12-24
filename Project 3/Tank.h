#ifndef TANK_INCLUDED
#define TANK_INCLUDED

#include <vector>
class Screen;
class Piece;


class Tank
{
  public:
    int display(Screen& screen, int x, int y, int level);
    void preDisplay(Screen& screen, int x, int y);
    void changeTank(int x, int y);
    void displayTank(Screen& screen, int x, int y);
    Tank (int tankWidth, int tankHeight);
    bool insert(Piece* newPiece);
    bool goodToGo(std::vector<std::vector<char>> shape, int x, int y) const;
    const Piece* showCurrent() const;
    int clearRow();
    void clearTank();
    void fillFoam(int x, int y, int left, int right, int top, int bottom);
    ~Tank();
private:
    int m_tankWidth;
    int m_tankHeight;
    std::vector<std::vector<char>> tank;
    Piece* current;
};



#endif // TANK_INCLUDED
