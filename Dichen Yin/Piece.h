//
//  Piece.h
//  Project 3
//
//  Created by Dichen Yin on 7/23/14.
//  Copyright (c) 2014 Dichen Yin. All rights reserved.
//

#ifndef __Project_3__Piece__
#define __Project_3__Piece__

#include <iostream>
#include <vector>
#include "Game.h"

class Piece
{
public:
    Piece()
    {
        shape = std::vector<std::vector<char>>(4, std::vector<char>(4, ' '));
        
    };
    virtual Piece* rotate();
    void display(Screen& screen, int x, int y) const;
    const std::vector<std::vector<char>> showShape() const;
    virtual std::string type() = 0;
    int showStatus() const;
    virtual ~Piece(){};
    
    
protected:
    int status;
    std::vector<std::vector<char>> shape;
    
};

class O : public Piece
{
public:
    O ();
    virtual std::string type()
    {
        return m_type;
    }
    virtual ~O(){};
private:
    std::string m_type;
};



class T : public Piece
{
public:
    T (int stat = 0);
    virtual std::string type()
    {
        return m_type;
    }
    virtual Piece* rotate();
    virtual ~T(){};
private:
    std::string m_type;
};



class J : public Piece
{
public:
    J (int stat = 0);
    virtual std::string type()
    {
        return m_type;
    }
    virtual Piece* rotate();
    virtual ~J(){};
private:
    std::string m_type;
};

class L : public Piece
{
public:
    L (int stat = 0);
    virtual std::string type()
    {
        return m_type;
    }
    virtual Piece* rotate();
    virtual ~L(){};
private:
    std::string m_type;
};



class S : public Piece
{
public:
    S (int stat = 0);
    virtual std::string type()
    {
        return m_type;
    }
    virtual Piece* rotate();
    virtual ~S(){};
private:
    std::string m_type;
};



class Z : public Piece
{
public:
    Z (int stat = 0);
    virtual std::string type()
    {
        return m_type;
    }
    virtual Piece* rotate();
    virtual ~Z(){};
private:
    std::string m_type;
};




class I : public Piece
{
public:
    I (int stat = 0);
    virtual std::string type()
    {
        return m_type;
    }
    virtual Piece* rotate();
    virtual ~I(){};
private:
    std::string m_type;
};


class CRAZY : public Piece
{
public:
    CRAZY (int stat = 0);
    virtual std::string type()
    {
        return m_type;
    }
    virtual Piece* rotate();
    virtual ~CRAZY(){};
private:
    std::string m_type;
};




class VAPOR : public Piece
{
public:
    VAPOR (int stat = 0);
    virtual std::string type()
    {
        return m_type;
    }
    //virtual Piece* rotate();
    virtual ~VAPOR(){};
private:
    std::string m_type;
};


class FOAM : public Piece
{
public:
    FOAM (int stat = 0);
    virtual std::string type()
    {
        return m_type;
    }
    //virtual Piece* rotate();
    virtual ~FOAM(){};
private:
    std::string m_type;
};






#endif /* defined(__Project_3__Piece__) */
