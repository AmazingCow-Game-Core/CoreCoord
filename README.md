# CoreCoord

**Made with <3 by [Amazing Cow](http://www.amazingcow.com).**



<!-- ####################################################################### -->
<!-- Websites                                                                -->
<!-- ####################################################################### -->

## Websites:

General:
* [Amazing Cow's page](http://www.amazingcow.com).
* [Amazing Cow's Github](https://github.com/AmazingCow).

Libs:
* [Amazing Cow's Libs page](https://github.com/AmazingCow-Libs).
* [Amazing Cow's Libs Github](http://www.amazingcow.com/libs).



<!-- ####################################################################### -->
<!-- Description                                                             -->
<!-- ####################################################################### -->

## Description:

```CoreCoord``` provides a very meaningful way to represent 2D values in 
games (and possible other applications too).   
We tried to keep the lib very simple only adding methods to ease the very 
common operations.

As usual, you are **very welcomed** to **share** and **hack** it.

### Motivation:

Often in the Amazing Cow's board games we need a way to represent a 
two dimensional value - a coordinate - so instead of using types like C++ 
```std::pair<int,int>``` that doesn't provide enough context we decide to 
create a very, very simple type.


<!-- ####################################################################### -->
<!-- Examples                                                                -->
<!-- ####################################################################### -->

## Examples:

#### Minesweeper:

Let's imagine a scenario that we want check if a block in Minesweeper 
is surrounded by a bomb. 

We can do:

```c++
auto surroundCoords = currentBlock.getCoord().getSurrounding();
for(const auto& coord : surroundCoords)
{
    const auto& block = Board.getBlockAt(coord);
    if(block.isMine())
        //Do something here...
    else
        //Do other thing here...
}
```

#### Chess:

In a chess the pawn can move only forward and attack an enemy piece diagonally.   
So let's check if the current move is valid for a pawn...

PS: We're ignoring the ability if move two squares in first move ;D
PS: We're checking only for white pawns and this is not a better way   
to represent a chess board, but is a nice example anyway...

``` c++
bool isValidPawnMove(const Coord& srcCoord, const Coord& dstCoord)
{
    auto targetPiece = board.getPieceAt(dstCoord);
    auto targetColor = targetPiece.getColor();

    //Check for normal move first.
    if(srcCoord.getUp() == dstCoord && 
       targetPiece == Piece::Empty)
    {
        return true;
    }

    //Check for attack moves.
    auto diagLeft  = srcCoord.getUp().getLeft();
    auto diagRight = srcCoord.getUp().getRight();

    if(diagLeft  == dstCoord && targetColor == Piece::Color::Black || 
       diagRight == dstCoord && targetColor == Piece::Color::Black)
    {
        return true;
    }

    //dstCoord is out of reach of pawn move.
    //Or it is attacking a non black piece.
    return false;
}
```

#### Lights Off:

In Lights Off we want turn just the orthogonal coords of a given coord.

```c++
void turnLightAt(const Coord& coord)
{
    auto targetCoords = coord.getOrthogonal();
    for(const auto &targetCoord : targetCoords)
    {
        board.getLightAt(targetCoord).turn();
    }
} 
```

We hope that you enjoy :D



<!-- ####################################################################### -->
<!-- Building                                                                -->
<!-- ####################################################################### -->

## Building:

```CoreCoord``` is intended to be include as source in your project.  
So to use it, just grab the whole CoreCoord directory, put it in your 
project and setup the include paths in the compiler.

As example, let's imagine that you are copying it to a directory called ```libs```.
In your build script you need to do just the following:

``` bash
g++ -I /path/to/libs/CoreCoord \
    ... Other stuff ...        \
    /path/to/libs/CoreCoord/CoreCoord/src/Coord.cpp 
```


<!-- ####################################################################### -->
<!-- Documentation                                                           -->
<!-- ####################################################################### -->

## Documentation:

We strive to make our source code fully documented.   
While there are a myriad of comments, one might find useful take a look at:

* [Doxygen Docs](http://www.amazingcow.com/docs/CoreCoord/).

Anyway if you didn't understand something let us know sending a mail to  
[help_floss@amazingcow.com]() with the subject filled with the name of this repo.



<!-- ####################################################################### -->
<!-- Dependencies                                                            -->
<!-- ####################################################################### -->

## Dependencies:

There is no dependency for ```CoreCoord```.



<!-- ####################################################################### -->
<!-- License                                                                 -->
<!-- ####################################################################### -->

## License:

This software is **proudly** released under [GPLv3](https://www.gnu.org/licenses/gpl-3.0.en.html).


<!-- ####################################################################### -->
<!-- BUGS                                                                    -->
<!-- ####################################################################### -->

## BUGS:

We strive to make all our code the most bug-free as possible - But we know 
that few of them can pass without we notice ;).

Please if you find any bug report to [bugs_floss@amazingcow.com]() 
with the name of this project and/or create an issue here in Github.


<!-- ####################################################################### -->
<!-- TODO                                                                    -->
<!-- ####################################################################### -->

## TODO:

Check the TODO file for general things.

This projects uses the COWTODO tags.   
So install [cowtodo](http://www.github.com/AmazingCow-Tools/COWTODO) and run:

``` bash
$ cd path/to/the/project
$ cowtodo 
```

That's gonna give you all things to do :D.


<!-- ####################################################################### -->
<!-- Others                                                                  -->
<!-- ####################################################################### -->

## Others:

Check our other Free Software repos and take a look at our 
[free software site](http://www.amazingcow.com/floss).

