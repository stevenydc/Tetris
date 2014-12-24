#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Tank.h"
#include "Piece.h"
#include "UserInterface.h"
#include <string>
// [Add other #include directives as necessary.]

class Game
{
  public:
    Game(int width, int height);
    void play();
    bool playOneLevel();
    void displayPrompt(std::string s);
    void displayStatus();
    int level();
    ~Game();
    // [Add other members as necessary.]

  private:
    Tank    m_tank;
    Screen  m_screen;
    int     m_level;
    int     m_score;
    int     m_rowsLeft;
    Piece*   m_nextPiece;
    std::string makeString(int a);
    
    // [Add other members as necessary.]
};

#endif // GAME_INCLUDED
