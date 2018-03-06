#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "redPlayer.h"
using namespace std;

///========================================================
string checkPos(int x, int y, int red[][6], int black[][6])
{
    string str = "";
    if(red[x][y] != 0)
        if(red[x][y] == 1)
            str = "r1";
        else
            str = "r2";
    else if(black[x][y] != 0)
        if(black[x][y] == 1)
            str = "b1";
        else
            str = "b2";
    else
        str = "  ";

    return str;
}
///======================================================
void getRedData(int &x, int &y)
{
    cout<<"Red player, select the piece you would like to move (x y): ";
    cin >> x >> y;
}

///if the postion selected has a "b1" or "b2" or "  ", then it will return false, if does not have any of these then it will return true.
///while the checkRedfunction evaluates to false, it will print out that it is an invalid input and ask the user to enter a new one.
bool checkRed (int x, int y, int red[][6], int black[][6])
{
    if (checkPos(x, y, red, black)=="b1" || checkPos(x, y, red, black)== "b2"
        || checkPos(x, y, red, black)=="  ")
            return false;
    else if(x<0 || y<0 || x>6 || y>6)
        return false;
    else
        return true;
}
///====================================================================

///using the checkpos function make sure the new position does not land on another piece
///then if the newx or the newy is greater than 6 or less than 6 and they are not equal to -1, return false.
///else, if they are equal to negative 1 return true, because that indicates they want to jump.
bool checkNewRed (int newx, int newy, int red[][6], int black[][6])
{
    if(checkPos(newx, newy, red, black)=="b1"||checkPos(newx, newy, red, black)=="b2"||
    checkPos(newx, newy, red, black)=="r1"||checkPos(newx, newy, red, black)=="r2")
        return false;
    else if (newx > 6 || newy > 6 || newx <0 || newy < 0 && newx !=-1 && newy !=-1)
        return false;
    else if (newx == -1 && newy==-1)
        return true;
    else
        return true;
}

///======================================================================
///if the selected x-2==the newx and the selectedy+2==newy
///then jumpedx is == the newx +1 and the jumpedy is = newy+1.
///use the checkPos function to check if the jumped position is a blank or "r1" or "r2"
///return false if any of those are true, else clear the jumped piece by initalizing it to 0, and return true.
///then it does the same thing for each quadrant
bool checkRedJump (int x, int y, int newx, int newy, int red[][6], int black[][6])
{

    if (x-2 ==newx && y+2==newy)
    {
        int jumpedx=newx+1;
        int jumpedy=newy-1;

        if(checkPos(jumpedx, jumpedy, red, black)=="  " || checkPos(jumpedx, jumpedy, red, black)=="r1"
           || checkPos(jumpedx, jumpedy, red, black)=="r2")
            return false;
        else
            {
                black[jumpedx][jumpedy]=0;

            return true;
            }
    }
    else if (x + 2==newx && y + 2==newy)
   {
        int jumpedx=newx-1;
        int jumpedy= newy-1;

        if (checkPos(jumpedx, jumpedy, red, black)=="  " || checkPos(jumpedx, jumpedy, red, black)=="r1"
            || checkPos(jumpedx, jumpedy, red, black)=="r2")
                return false;
        else
        {
            black[jumpedx][jumpedy]=0;

            return true;
            }
   }
   else if ( x - 2 ==newx && y - 2 == newy)
   {
       int jumpedx=newx + 1;
       int jumpedy= newy + 1;

       if (checkPos(jumpedx, jumpedy, red, black)=="  " || checkPos(jumpedx, jumpedy, red, black)=="r1"
           || checkPos(jumpedx, jumpedy, red, black)=="r2")
            return false;
       else
       {
          black[jumpedx][jumpedy]=0;

          return true;
       }
   }
   else if (x+2==newx && y-2==newy)
   {
       int jumpedx=newx-1;
       int jumpedy=newy+1;

       if (checkPos(jumpedx, jumpedy, red, black)=="  " || checkPos(jumpedx, jumpedy, red, black)=="r1"
           || checkPos(jumpedx, jumpedy, red, black)=="r2")
            return false;
       else
       {
           black[jumpedx][jumpedy]=0;

           return true;
       }
   }

    return false;
}
