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
--  file: chip.cpp                                                         --
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

#include "cship.h"

CShip :: CShip()
{
    numExplosionFrames=1;
    actualExplosionFrame=0;
    explosionFrames=new CFrame[numExplosionFrames];
    maxMissiles=10;
    missiles=new CSprite[maxMissiles];         
}

CShip :: CShip(int nFrames, int nExplosionFrames) : CSprite(nFrames)
{ 
    numExplosionFrames=nExplosionFrames;
    actualExplosionFrame=0;
    explosionFrames=new CFrame[numExplosionFrames];
    maxMissiles=10;
    missiles=new CSprite[maxMissiles];         
}

void CShip :: draw(unsigned char *buffer, int screenWidth)
{
    if(state == ACTIVE)
    {
        CSprite::draw(&frames[actualFrame], buffer,screenWidth);
        //CSprite::draw(&explosionFrames[actualExplosionFrame], buffer,screenWidth);
    }
    else if(state == EXPLODING)
    {
        if(actualExplosionFrame < numExplosionFrames)
        {
            CSprite::draw(&explosionFrames[actualExplosionFrame], buffer,screenWidth);
            actualExplosionFrame++;
            
        }
        else
        {
            state = FREE;
        }
    }
}

void CShip :: shotMissile()
{
    int i;
    int free = -1;

    // ¿Hay alguna bala libre?
    for (i=0 ; i<maxMissiles ; i++) 
    {
        if (missiles[i].state == FREE)
            free=i;
    }
    if (free>=0) 
    {
        missiles[free].setPosX(getPosX());
        missiles[free].setPosY(getPosY() - 15);

        missiles[free].state = ACTIVE;
    }
}

