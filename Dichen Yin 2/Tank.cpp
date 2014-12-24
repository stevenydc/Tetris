#include "Tank.h"
#include "Piece.h"
#include "UserInterface.h"
#include <stack>

Tank::Tank(int tankWidth, int tankHeight):current(nullptr)
{
    
    m_tankWidth = tankWidth;
    m_tankHeight = tankHeight;
    tank = std::vector<std::vector<char>> (tankHeight+1, std::vector<char>(tankWidth+2, ' '));
    for (int i = 0; i < tankHeight+1; i++)
    {
        if (i != tankHeight)
        {
            tank[i][0] = '@';
            tank[i][tankWidth+1] = '@';
        }
        else
        {
            for (int j = 0; j <= tankWidth+1; j++)
            {
                tank[i][j] = '@';
            }
        }
    }
    
}

bool Tank::insert(Piece* newPiece)
{
    std::string type  = newPiece->type();
    if (type == "O")
        current = new O();
    if (type == "T")
        current = new T();
    if (type == "J")
        current = new J();
    if (type == "S")
        current = new S();
    if (type == "Z")
        current = new Z();
    if (type == "L")
        current = new L();
    if (type == "I")
        current = new I();
    if (type == "CRAZY")
        current = new CRAZY();
    if (type == "VAPOR")
        current = new VAPOR();
    if (type == "FOAM")
        current = new FOAM();
    return true;
}


const Piece* Tank::showCurrent() const
{
    return current;
}

bool Tank::goodToGo(std::vector<std::vector<char>> shape, int x, int y) const
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i <4; i++)
        {
            if (x+i <= m_tankWidth+1 && y+j < m_tankHeight+1)
            {
                if (shape[j][i] != ' ' && tank[y+j][x+i] != ' ')
                {
                    return false;
                }
            }
        }
    }
    return true;
}


void Tank::preDisplay(Screen &screen, int x, int y)
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i <4; i++)
        {
            if (current->showShape()[j][i] != ' ' && tank[y+j][x+i] == ' ')
            {
                screen.gotoXY(x+i, j+y);
                screen.printChar(' ');
                screen.refresh();
            }
        }
    }
}


void Tank::displayTank(Screen& screen, int x, int y)
{
    for (int i = 0; i < (m_tankHeight+1); i++)
    {
        for (int j = 0; j <= (m_tankWidth+1); j++)
        {
            screen.gotoXY(x+j, y + i);
            screen.printChar(tank[i][j]);
        }
    }
}

void Tank::changeTank(int x, int y)
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i <4; i++)
        {
            if (current->showShape()[j][i] != ' ' /*&& tank[y+j][x+i] == ' '*/)
                tank[y+j][x+i] = '$';
        }
    }
}

int Tank::clearRow()
{
    int fullCount = 0;
    for (int j = 0; j < m_tankHeight; j++)
    {
        bool full = true;
        for (int i = 1; i <= m_tankWidth; i++)
        {
            if (tank[j][i] == ' ')
                full = false;
        }
        if (full)
        {
            for (int i = j; i >0; i --)
            {
                tank[i] = tank[i-1];
            }
            for (int k = 1; k <= m_tankWidth; k++)
            {
                tank[0][k] = ' ';
            }
            fullCount ++;
        }
    }
    return fullCount;
}



int Tank::display(Screen& screen, int x, int y, int level)
{
    displayTank(screen, x, y);
    if (current != nullptr)
    {
        int piece_x = x+4;
        int piece_y = y;
        bool firstTime = true;
        while (1)
        {
              // clean up the screen
            {
                preDisplay(screen, piece_x, piece_y);
            }
            if (!firstTime)
                piece_y++;
            firstTime = false;
            current->display(screen, piece_x, piece_y);
            
            int endTime = getMsecSinceStart() + std::max(1000-(100*(level-1)), 100);
        
            // Repeat as long as current time has not yet reached the end time
            while (getMsecSinceStart() < endTime)
            {
                char ch;
                if (getCharIfAny(ch))
                {
                    if (current->type() == "CRAZY")
                    {
                        if (ch == ARROW_LEFT)
                            ch = ARROW_RIGHT;
                        else if (ch == ARROW_RIGHT)
                            ch = ARROW_LEFT;
                    }
                    // There was a character typed; it's now in ch
                    switch (ch)
                    {
                        case ' ':
                        {
                            int testY = piece_y;
                            while (goodToGo(current->showShape(), piece_x, testY+1))
                                testY++;
                            preDisplay(screen, piece_x, piece_y);
                            piece_y = testY;
                            changeTank(piece_x, piece_y);
                            displayTank(screen, x, y);
                        }
                            break;
                            
                        case ARROW_LEFT:
                        {
                            if (goodToGo(current->showShape(), piece_x-1, piece_y))
                            {
                                preDisplay(screen, piece_x, piece_y);
                                piece_x--;
                                current->display(screen, piece_x, piece_y);
                                
                            }
                            break;
                        }
                            
                        case ARROW_RIGHT:
                        {
                            if (goodToGo(current->showShape(), piece_x+1, piece_y))
                            {
                                preDisplay(screen, piece_x, piece_y);
                                piece_x++;
                                current->display(screen, piece_x, piece_y);
                                
                            }
                            break;
                        }
                        case ARROW_UP:
                        {
                            if (current->type() != "O" && current->type() != "VAPOR" && current->type() != "FOAM")
                            {
                                Piece* potential = current->rotate();
                                if (goodToGo(potential->showShape(), piece_x, piece_y))
                                {
                                    preDisplay(screen, piece_x, piece_y);
                                    delete current;
                                    current = potential;
                                    current->display(screen, piece_x, piece_y);
                                    break;
                                }
                                //delete potential;
                            }
                            break;
                        }
                        case ARROW_DOWN:
                        {
                            if (goodToGo(current->showShape(), piece_x, piece_y+1))
                            {
                                endTime = getMsecSinceStart() + std::max(1000-(100*(level-1)), 100);
                                preDisplay(screen, piece_x, piece_y);
                                piece_y++;
                                current->display(screen, piece_x, piece_y);
                            }
                            else
                                ch = ' ';
                            break;
                        }
                        case 'q':
                        {
                            return -1;
                        }
                            
                    }
                    if (ch == ' ')
                        break;
                }
            }
            
            if (!goodToGo(current->showShape(), piece_x, piece_y+1))
            {
                if (current->type() == "VAPOR")
                {
                    for (int i = piece_x+1; i <= piece_x+2; i++)
                    {
                        for (int j = piece_y-2; j <= piece_y+2; j++)
                        {
                            if (j >= 0 && j <= m_tankHeight)
                            {
                                if (tank[j][i] != '@')
                                    tank[j][i] = ' ';
                            }
                        }
                    }
                }
                else if(current->type() == "FOAM")
                {
                    fillFoam(piece_x+1, piece_y+1, piece_x-2, piece_x+4, piece_y+4, piece_y-2);
                }
                else{
                    changeTank(piece_x, piece_y);
                }
                displayTank(screen, x, y);
                break;
            }
        }
    }
    screen.refresh();
    return 0;
}



void Tank::clearTank()
{
    for (int i = 0; i < m_tankHeight; i++)
    {
        for (int j = 1; j <= m_tankWidth; j++)
        {
            tank[i][j] = ' ';
        }
    }
}

void Tank::fillFoam(int x, int y, int left, int right, int top, int bottom)
{
    if (x > left && x < right && y > bottom && y < top)
    {
            tank[y][x] = '*';

        if (tank[y+1][x] == ' ')
            fillFoam(x, y+1, left, right, top, bottom);
        if (tank[y][x+1] == ' ')
            fillFoam(x+1, y, left, right, top, bottom);
        if ((y > 0) && tank[y-1][x] == ' ')
            fillFoam(x, y-1, left, right, top, bottom);
        if (tank[y][x-1] == ' ')
            fillFoam(x-1, y, left, right, top, bottom);
    }
}


Tank::~Tank()
{
    delete current;
}


