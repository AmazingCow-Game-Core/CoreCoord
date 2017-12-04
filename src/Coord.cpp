//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Coord.cpp                                                     //
//  Project   : CoreCoord                                                     //
//  Date      : Nov 23, 2015                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2015 - 2017                                      //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "../include/Coord.h"

// Usings.
USING_NS_CORECOORD;


//----------------------------------------------------------------------------//
// Static Methods                                                             //
//----------------------------------------------------------------------------//
const Coord& Coord::Left()
{
    static Coord s_left(0, -1);
    return s_left;
}

const Coord& Coord::Right()
{
    static Coord s_right(0, +1);
    return s_right;
}

const Coord& Coord::Up()
{
    static Coord s_up(-1, 0);
    return s_up;
}

const Coord& Coord::Down()
{
    static Coord s_down(1, 0);
    return s_down;
}


//----------------------------------------------------------------------------//
// Operators                                                                  //
//----------------------------------------------------------------------------//
//Friends
NS_CORECOORD_BEGIN
std::ostream& operator <<(std::ostream &os, const Coord &coord)
{
    os << "(" << coord.y << "," << coord.x << ")";
    return os;
}

bool operator ==(const Coord &lhs, const Coord rhs)
{
    return (lhs.y == rhs.y) && (lhs.x == rhs.x);
}

bool operator !=(const Coord &lhs, const Coord rhs)
{
    return !(lhs == rhs);
}

Coord operator +(const Coord &lhs, const Coord &rhs)
{
    return Coord(lhs.y + rhs.y, lhs.x + rhs.x);
}

Coord operator -(const Coord &lhs, const Coord &rhs)
{
    return Coord(lhs.y - rhs.y, lhs.x - rhs.x);
}

Coord operator *(const Coord &lhs, int scalar)
{
    return Coord(lhs.y * scalar, lhs.x * scalar);
}
NS_CORECOORD_END


//Members
///@brief Adds the y and x.
Coord& Coord::operator +=(const Coord &rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;

    return (*this);
}

Coord& Coord::operator -=(const Coord &rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;

    return (*this);
}

Coord& Coord::operator *=(int scalar)
{
    this->x *= scalar;
    this->y *= scalar;

    return (*this);
}


//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
Coord::Coord(int _y /* = 0 */, int _x /* = 0 */) :
    y(_y),
    x(_x)
{
    //Empty...
}


//----------------------------------------------------------------------------//
// Public Methods                                                             //
//----------------------------------------------------------------------------//
Coord Coord::getUp(int offset /* = 1 */) const
{
    return Coord(this->y - offset, this->x);
}

Coord Coord::getDown(int offset /* = 1 */) const
{
    return Coord(this->y + offset, this->x);
}

Coord Coord::getLeft(int offset /* = 1 */) const
{
    return Coord(this->y, this->x - offset);
}

Coord Coord::getRight(int offset /* = 1 */) const
{
    return Coord(this->y, this->x + offset);
}

Coord Coord::getMiddle(const Coord &coord2) const
{
    return Coord((this->y + coord2.y) / 2,
                 (this->x + coord2.x) / 2);
}


Coord::Vec Coord::getOrthogonal() const
{
    return {
        getUp   (),
        getRight(),
        getDown (),
        getLeft ()
    };
}

Coord::Vec Coord::getSurrounding() const
{
    return {
        getUp(),              //Top.
        getUp().getRight(),   //Top Right.

        getRight(),           //Right.

        getDown().getRight(), //Bottom Right.
        getDown(),            //Bottom.
        getDown().getLeft(),  //Bottom Left.

        getLeft(),            //Left.

        getUp().getLeft()     //Top Left.
    };
}


bool Coord::isSameX(const Coord &coord2) const
{
    return this->x == coord2.x;
}

bool Coord::isSameY(const Coord &coord2) const
{
    return this->y == coord2.y;
}


void Coord::makeUnit()
{
    if(this->x != 0)
        this->x /= abs(this->x);

    if(this->y != 0)
        this->y /= abs(this->y);
}

Coord Coord::getUnit() const
{
    auto ret = Coord(*this);
    ret.makeUnit();

    return ret;
}
