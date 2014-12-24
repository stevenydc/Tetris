#include "Game.h"
#include "Tank.h"
#include "Piece.h"
#include "UserInterface.h"
#include <string>
#include "randPieceType.h"
#include <sstream>

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int TANK_X = 0;
const int TANK_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;

Game::Game(int width, int height) : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1), m_tank(width, height), m_rowsLeft(5*m_level), m_score(0),m_nextPiece(nullptr)

{
}

void Game::play()
{
    m_tank.display(m_screen, TANK_X, TANK_Y, m_level);
    displayStatus();  //  score, rows left, level
    displayPrompt("Press the Enter key to begin playing Imitris!");
    waitForEnter();  // [in UserInterface.h]

    for(;;)
    {

        if (m_nextPiece == nullptr)
        {
            switch (randPieceType())
            {
                case PIECE_I:m_nextPiece = new I();break;
                case PIECE_L:m_nextPiece = new L();break;
                case PIECE_J:m_nextPiece = new J();break;
                case PIECE_Z:m_nextPiece = new Z();break;
                case PIECE_CRAZY:m_nextPiece = new CRAZY();break;
                case PIECE_FOAM:m_nextPiece = new FOAM();break;
                case PIECE_VAPOR:m_nextPiece = new VAPOR();break;
                case PIECE_O:m_nextPiece = new O();break;
                case PIECE_S:m_nextPiece = new S();break;
                case PIECE_T:m_nextPiece = new T();break;
            }
        }

        
        m_tank.insert(m_nextPiece);
        
        delete m_nextPiece;
        
        switch (randPieceType())
        {
            case PIECE_I:m_nextPiece = new I();break;
            case PIECE_L:m_nextPiece = new L();break;
            case PIECE_J:m_nextPiece = new J();break;
            case PIECE_Z:m_nextPiece = new Z();break;
            case PIECE_CRAZY:m_nextPiece = new CRAZY();break;
            case PIECE_FOAM:m_nextPiece = new FOAM();break;
            case PIECE_VAPOR:m_nextPiece = new VAPOR();break;
            case PIECE_O:m_nextPiece = new O();break;
            case PIECE_S:m_nextPiece = new S();break;
            case PIECE_T:m_nextPiece = new T();break;
        }
        displayStatus();
        
        if (!m_tank.goodToGo((m_tank.showCurrent()->showShape()), TANK_X+4, TANK_Y))
        {
            m_tank.showCurrent()->display(m_screen, TANK_X+4, TANK_Y);
            break;
        }
        if (m_tank.display(m_screen, TANK_X, TANK_Y, m_level) == -1)
        {
            delete m_nextPiece;
            break;
        }
        switch (m_tank.clearRow())
        {
            case 0:
                break;
            case 1:
                m_score += 100;
                m_rowsLeft--;
                break;
            case 2:
                m_score += 200;
                m_rowsLeft -= 2;
                break;
            case 3:
                m_score += 400;
                m_rowsLeft -= 3;
                break;
            case 4:
                m_score += 800;
                m_rowsLeft -= 4;
                break;
            case 5:
                m_score += 1600;
                m_rowsLeft -= 5;
                break;
        }
        if (m_rowsLeft < 0)m_rowsLeft = 0;
        displayStatus();
        m_tank.displayTank(m_screen, TANK_X, TANK_Y);
        
        
        if (playOneLevel())
        {
            displayPrompt("Good job!  Press the Enter key to start next level!");
            waitForEnter();
            m_level++;
            displayStatus();
        }
        
        
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
    waitForEnter();
}

void Game::displayPrompt(std::string s)     
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
}
std::string Game::makeString(int a)
{
    std::stringstream ss;
    ss << a;
    std::string output;
    ss >> output;
    int b = output.size();
    for (int i = 0; i < 7-b; i++)
    {
        output = " "+ output;
    }
    return output;
}

void Game::displayStatus()
{
    m_screen.gotoXY(SCORE_X, SCORE_Y);
    
    m_screen.printString("Score:     " + makeString(m_score));
    
    
    m_screen.gotoXY(ROWS_LEFT_X, ROWS_LEFT_Y);
    m_screen.printString("Rows left: " + makeString(m_rowsLeft));
    
    m_screen.gotoXY(LEVEL_X, LEVEL_Y);
    m_screen.printString("Level:     " + makeString(m_level));
    
    if (m_nextPiece != nullptr)
    {
        m_screen.gotoXY(NEXT_PIECE_TITLE_X, NEXT_PIECE_TITLE_Y);
        m_screen.printString("Next piece:");
    

        for (int i = NEXT_PIECE_Y; i < NEXT_PIECE_Y+4; i++)
        {
            m_screen.gotoXY(NEXT_PIECE_X, i);
            std::string output = "";
            for (int j = 0; j < 4; j++)
            {
                output += m_nextPiece->showShape()[i-NEXT_PIECE_Y][j];
            }
            m_screen.printString(output);
        }
    }
    
    m_screen.refresh();
}

bool Game::playOneLevel()
{
    if (m_rowsLeft <= 0)
    {
        m_rowsLeft = 5*(m_level+1);
        m_tank.clearTank();
        return true;
    }
    return false;
}


int Game::level()
{
    return m_level;
}

Game::~Game()
{
    if (m_nextPiece!= nullptr)
        delete m_nextPiece;
}

