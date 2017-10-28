//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Coord.h                                                       //
//  Project   : CoreCoord                                                     //
//  Date      : Nov 23, 2015                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2015 - 2017                                      //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#ifndef __CoreCoord_include_Coord_h__
#define __CoreCoord_include_Coord_h__

//std
#include <ostream>
#include <vector>
//CoreCoord
#include "CoreCoord_Utils.h"


NS_CORECOORD_BEGIN

class Coord
{
    // Enums / Constants / Typedefs //
public:
    ///@brief Typedef to ease the typing of "a vector of Coords".
    typedef std::vector<Coord> Vec;


    // Static Methods //
public:
    //COWTODO: Add the documentation...
    static const Coord& Left ();
    static const Coord& Right();
    static const Coord& Up   ();
    static const Coord& Down ();


    // Operator //
public:
    //Friends
    ///@brief Output a string representation in form of (y, x).
    friend std::ostream& operator <<(std::ostream &os, const Coord &coord);

    ///@brief Check if two coords have the same y and x.
    friend bool operator ==(const Coord &lhs, const Coord rhs);

    ///@brief Check if two coords have the different y and x.
    friend bool operator !=(const Coord &lhs, const Coord rhs);

    ///@brief Adds the y and x.
    friend Coord operator +(const Coord &lhs, const Coord &rhs);

    ///@brief Subtracts y and x.
    friend Coord operator -(const Coord &lhs, const Coord &rhs);

    ///@brief Multiplies by a scalar.
    friend Coord operator *(const Coord &lhs, int scalar);

    //Members
    ///@brief Adds the y and x.
    Coord& operator +=(const Coord &rhs);

    ///@brief Subtracts y and x.
    Coord& operator -=(const Coord &rhs);

    ///@brief Multiplies y and x by scalar.
    Coord& operator *=(int scalar);


    // CTOR/DTOR //
public:
    ///@brief Constructs a Coord.
    ///@param y The Y coordinate - Default is 0.
    ///@param x The X coordinate - Default is 0.
    ///@note Coord is Y axis first - Take care with it.
    ///@warning Coord is Y axis first - Take care with it.
    explicit Coord(int y = 0, int x = 0);


    // Public Methods //
public:
    ///@brief Gets a Coord that is top of this coord.
    ///@param offset How many times it will be on top.
    ///@returns A coord that have the y coordinate "offset" times less
    ///than this coord.
    Coord getUp(int offset = 1) const;

    ///@brief Gets a Coord that is bottom of this coord.
    ///@param offset How many times it will be on bottom.
    ///@returns A coord that have the y coordinate "offset" times more
    ///than this coord.
    Coord getDown(int offset = 1) const;

    ///@brief Gets a Coord that is on left of this coord.
    ///@param offset How many times it will be on left.
    ///@returns A coord that have the x coordinate "offset" times less
    ///than this coord.
    Coord getLeft(int offset = 1) const;

    ///@brief Gets a Coord that is on right of this coord.
    ///@param offset How many times it will be on right.
    ///@returns A coord that have the x coordinate "offset" times more
    ///than this coord.
    Coord getRight(int offset = 1) const;

    ///@brief Gets a Coord that is in the middle of two coords.
    ///@param coord2 The second coord that will be compared.
    ///@returns A coord that has the y and y coordinates specified
    ///by formula: (c1.y + c2.y) / 2 and (c1.x + c2.x) / 2.
    Coord getMiddle(const Coord &coord2) const;


    ///@brief Gets a the orthogonal coords.
    ///@returns a vector of coords starting from top going clockwise.
    ///@see Coord::getSurrounding.
    Vec getOrthogonal() const;

    ///@brief Gets a the surrounding coords.
    ///@returns a vector of coords starting from top going clockwise.
    ///@see Coord::getSurrounding.
    Vec getSurrounding() const;


    ///@brief Gets if the both coords have the same X coordinate.
    ///@returns True if they are at same X, false otherwise.
    ///@see isSameY().
    bool isSameX(const Coord &coord2) const;

    ///@brief Gets if the both coords have the same Y coordinate.
    ///@returns True if they are at same Y, false otherwise.
    ///@see isSameX().
    bool isSameY(const Coord &coord2) const;


    ///@brief Make the values of the Coord in range of (-1, 1).
    ///@see getUnit().
    void makeUnit();

    ///@brief Return a new Unit Coord with the values in range of(-1, 1).
    ///@returns A new Unit Coord.
    ///@see makeUnit();
    Coord getUnit() const;


    // iVars //
public:
    int y, x;
};


NS_CORECOORD_END
#endif // defined(__CoreCoord_include_Coord_h__) //
