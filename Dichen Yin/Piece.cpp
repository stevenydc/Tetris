//
//  Piece.cpp
//  Project 3
//
//  Created by Dichen Yin on 7/23/14.
//  Copyright (c) 2014 Dichen Yin. All rights reserved.
//

#include "Piece.h"
#include "Game.h"
#include "UserInterface.h"



void Piece::display(Screen& screen, int x, int y) const
{

        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i <4; i++)
            {
                if (shape[j][i] != ' ')
                {
                    screen.gotoXY(x+i, j+y);
                    screen.printChar(shape[j][i]);
                }
            }
        }
        screen.refresh();

}



const std::vector<std::vector<char>> Piece::showShape() const
{
    return shape;
}

int Piece::showStatus() const
{
    return status;
}

Piece* Piece::rotate()
{
    return nullptr;
}



O::O(): m_type("O")
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i < 2 && j < 2)
                shape[i][j] = '#';
            else
                shape[i][j] = ' ';
        }
    }
}
T::T(int stat):m_type("T")
{
    switch (stat){
        case 0:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 0  && j == 1)
                        shape[i][j] = '#';
                    else if (i == 1 && j < 3)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 0;
            break;
        }
        case 1:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 1  && j == 2)
                        shape[i][j] = '#';
                    else if (i < 3 && j == 1)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 1;
            break;
        }
        case 2:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 2  && j == 1)
                        shape[i][j] = '#';
                    else if (i == 1 && j < 3)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 2;
            break;
        }
        case 3:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 1  && j == 0)
                        shape[i][j] = '#';
                    else if (i < 3 && j == 1)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 3;
            break;
        }
            
    }
}


Piece* T::rotate()
{
    Piece* test = nullptr;
    if (status == 3)
    {
        test = new T(0);
    }
    else
    {
        test = new T(status+1);
    }
    return test;
}




J::J(int stat):m_type("J")
{
    switch (stat){
        case 0:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 1  && j >0 )
                        shape[i][j] = '#';
                    else if (i == 2 && j == 3)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 0;
            break;
        }
        case 1:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i > 0  && j == 2)
                        shape[i][j] = '#';
                    else if (i == 3 && j == 1)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 1;
            break;
        }
        case 2:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 2  && j > 0)
                        shape[i][j] = '#';
                    else if (i == 1 && j == 1)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 2;
            break;
        }
        case 3:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i < 3  && j == 1)
                        shape[i][j] = '#';
                    else if (i == 0 && j == 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 3;
            break;
        }
            
    }
}


Piece* J::rotate()
{
    Piece* test = nullptr;
    if (status == 3)
    {
        test = new J(0);
    }
    else
    {
        test = new J(status+1);
    }
    return test;
}



L::L(int stat):m_type("L")
{
    switch (stat){
        case 0:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 1  && j < 3 )
                        shape[i][j] = '#';
                    else if (i == 2 && j == 0)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 0;
            break;
        }
        case 1:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i < 3  && j == 2)
                        shape[i][j] = '#';
                    else if (i == 0 && j == 1)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 1;
            break;
        }
        case 2:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 2  && j < 3)
                        shape[i][j] = '#';
                    else if (i == 1 && j == 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 2;
            break;
        }
        case 3:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i > 0 && j == 1)
                        shape[i][j] = '#';
                    else if (i == 3 && j == 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 3;
            break;
        }
            
    }
}


Piece* L::rotate()
{
    Piece* test = nullptr;
    if (status == 3)
    {
        test = new L(0);
    }
    else
    {
        test = new L(status+1);
    }
    return test;
}



S::S(int stat):m_type("S")
{
    switch (stat){
        case 0:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 1  && j > 0 && j <3 )
                        shape[i][j] = '#';
                    else if (i == 2 && j < 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 0;
            break;
        }
        case 1:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i < 2  && j == 1)
                        shape[i][j] = '#';
                    else if (i > 0 && i < 3 && j == 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 1;
            break;
        }
        case 2:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 1  && j > 0 && j <3)
                        shape[i][j] = '#';
                    else if (i == 2 && j < 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 2;
            break;
        }
        case 3:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i < 2  && j == 1)
                        shape[i][j] = '#';
                    else if (i > 0 && i < 3 && j == 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 3;
            break;
        }
            
    }
}


Piece* S::rotate()
{
    Piece* test = nullptr;
    if (status == 3)
    {
        test = new S(0);
    }
    else
    {
        test = new S(status+1);
    }
    return test;
}



Z::Z(int stat):m_type("Z")
{
    switch (stat){
        case 0:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 2  && j > 0 && j <3 )
                        shape[i][j] = '#';
                    else if (i == 1 && j < 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 0;
            break;
        }
        case 1:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i < 2  && j == 2)
                        shape[i][j] = '#';
                    else if (i > 0 && i < 3 && j == 1)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 1;
            break;
        }
        case 2:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 2  && j > 0 && j <3)
                        shape[i][j] = '#';
                    else if (i == 1 && j < 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 2;
            break;
        }
        case 3:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i < 2  && j == 2)
                        shape[i][j] = '#';
                    else if (i > 0 && i < 3 && j == 1)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 3;
            break;
        }
            
    }
}


Piece* Z::rotate()
{
    Piece* test = nullptr;
    if (status == 3)
    {
        test = new Z(0);
    }
    else
    {
        test = new Z(status+1);
    }
    return test;
}



I::I(int stat):m_type("I")
{
    switch (stat){
        case 0:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 1 )
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 0;
            break;
        }
        case 1:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (j == 1)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 1;
            break;
        }
            
    }
}


Piece* I::rotate()
{
    Piece* test = nullptr;
    if (status == 1)
    {
        test = new I(0);
    }
    else
    {
        test = new I(1);
    }
    return test;
}


CRAZY::CRAZY(int stat):m_type("CRAZY")
{
    switch (stat){
        case 0:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == 0 && j == 0) ||(i == 0 && j == 3) )
                        shape[i][j] = '#';
                    else if( i == 1 && j > 0 && j < 3)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 0;
            break;
        }
        case 1:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == 0  && j == 3) || (i == 3 && j == 3))
                        shape[i][j] = '#';
                    else if (i > 0 && i < 3 && j == 2)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 1;
            break;
        }
        case 2:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == 3  && j  == 0) || (i == 3 && j == 3))
                        shape[i][j] = '#';
                    else if (i == 2 && j < 3 && j > 0)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 2;
            break;
        }
        case 3:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == 0  && j == 0) || (i == 3 && j == 0))
                        shape[i][j] = '#';
                    else if (i > 0 && i < 3 && j == 1)
                        shape[i][j] = '#';
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 3;
            break;
        }
            
    }
}


Piece* CRAZY::rotate()
{
    Piece* test = nullptr;
    if (status == 3)
    {
        test = new CRAZY(0);
    }
    else
    {
        test = new CRAZY(status+1);
    }
    return test;
}


VAPOR::VAPOR(int stat):m_type("VAPOR")
{
    switch (stat){
        case 0:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == 0 && j > 0 && j < 3) )
                        shape[i][j] = '#';

                    else
                        shape[i][j] = ' ';
                }
            }
            status = 0;
            break;
        }

            
    }
}



FOAM::FOAM(int stat):m_type("FOAM")
{
    switch (stat){
        case 0:
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == 1 && j == 1) )
                        shape[i][j] = '#';
                    
                    else
                        shape[i][j] = ' ';
                }
            }
            status = 0;
            break;
        }
            
            
    }
}














