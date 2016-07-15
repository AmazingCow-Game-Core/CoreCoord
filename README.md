# CoreCoord

**Made with <3 by [Amazing Cow](http://www.amazingcow.com).**



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Description:

```CoreCoord``` provides a very meaningful way to represent 2D values in 
games (and possible other applications too).   
We tried to keep the lib very simple only adding methods to ease the very 
common operations.


### Motivation:

Often in the Amazing Cow's board games we need a way to represent a 
two dimensional value - a coordinate - so instead of using types like C++ 
```std::pair<int,int>``` that doesn't provide enough context we decide to 
create a very, very simple type.


<br>
As usual, you are **very welcomed** to **share** and **hack** it.




<!-- ####################################################################### -->
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
<!-- ####################################################################### -->

## Documentation:

We strive to make our source code fully documented.   
While there are a myriad of comments, one might find useful take a look at:

* [Doxygen Docs](http://www.amazingcow.com/projects/corecoord/doxygen/).

Anyway if you didn't understand something let us know sending a mail to  
[help_opensource@amazingcow.com]() with the subject filled with the
name of this repo.



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Dependencies:

There is no dependency for ```CoreCoord```.



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## License:

This software is released under GPLv3.



<!-- ####################################################################### -->
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
<!-- ####################################################################### -->

## Others:

Check our repos and take a look at our 
[open source site](http://opensource.amazingcow.com).
