/*---------------------------------------------------------------------------
--                          Vertical Shump Demo                            --  
-----------------------------------------------------------------------------
--                                                                         --
--  This is an example demo for MaRTE OS.                                  --
--                                                                         --
--  author:   Alvaro Garcia Cuesta                                         --
--  email:    alvaro@binarynonsense.com                                    --
--  website:  www.binarynonsense.com                                       --
--                                                                         --
--  file: csprite.h                                                        --
--                                                                         --
--  this file contains [...]                                               --
-----------------------------------------------------------------------------
--                               License                                  -- 
-----------------------------------------------------------------------------
--                                                                         --
-- This is free software; you can redistribute it and/or modify it         --
-- under the terms of the GNU General Public License version 2 as          -- 
-- published by the Free Software Foundation.                              --
-- See COPYING file for more info about the license                        --
--                                                                         --
-----------------------------------------------------------------------------
--                      last update: 25 Aug 2014                           --
---------------------------------------------------------------------------*/

#ifndef CSPRITE_H
#define CSPRITE_H

#include "vga.h"
#include <stdio.h>

#include "cframe.h"

//enum states {IDLE, WALKING, JUMPING};
//enum directions {LEFT, RIGHT};

enum states {FREE,EXPLODING,ACTIVE,INVINCIBLE};
enum directions {UP,DOWN,LEFT, RIGHT};

class CSprite
{
    private:
        
        int posX,posY;
        int numFrames;  
        
    public:   
        
        CFrame *frames; 
        CSprite();
        CSprite(int nFrames);
        
        //states stateNow;
        //states previousState;
        //directions directionNow;
        //int frameState[3][6];
        states state;
        directions direction;
        int actualFrame;
        int getPosX(){return posX;};
        int getPosY(){return posY;};
        void setPosX(int x){ posX = x;};
        void setPosY(int y){ posY = y;};
        int getWidth ();
        int getHeight ();
        
        void checkForMovement();
        void draw (unsigned char *buffer, int screenWidth);
        virtual void draw(CFrame *frame, unsigned char *buffer, int screenWidth);
        int collision(CSprite *otherSprite);
};

#endif
