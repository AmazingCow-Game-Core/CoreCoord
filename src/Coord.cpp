//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        Coord.cpp                                 //
//            █ █        █ █        CoreCoord                                 //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

//Header
#include "../include/Coord.h"

//Usings.
USING_NS_CORECOORD;

// Operators //
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


// CTOR/DTOR //
Coord::Coord(int _y /* = 0 */, int _x /* = 0 */) :
    y(_y),
    x(_x)
{
    //Empty...
}


// Public Methods //
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
