#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "redPlayer.h"
#include "blackPlayer.h"

using namespace std;
///=============================================================
void getBlackData(int &x, int &y)
{
    cout<<"Black player, select the piece you would like to move (x y): ";
    cin >> x >> y;
}
///===============================================================
///checkBlackdata function expansion.
///using the checkPos function, if the selected position is equal to "r1" or "r2" or a space return false
///else if the x and y coordinates are greater than 6 or less than 0, return false, else return true.
bool checkBlackData (int x, int y, int red[][6], int black[][6])
{
    if (checkPos(x, y, red, black)=="r1"|| checkPos(x, y, red, black)=="r2"
        || checkPos(x, y, red, black)=="  ")
            return false;
    else if (x < 0 || y < 0 || x > 6 || y > 6)
        return false;
    else
        return true;
}
///=================================================================
///checkNewBlack function expansion
///using checkPos, if the new position is=="b1" or "b2" or "r1" or "r2", return false, else return true.
bool checkNewBlack (int newx1, int newx2, int red[][6], int black[][6])
{
    if (checkPos(newx1, newx2, red, black)=="b1" || checkPos(newx1, newx2, red, black)=="b2"
        || checkPos(newx1, newx2, red, black)=="r1" || checkPos(newx1, newx2, red, black)=="r2")
            return false;
  else
    return true;
}
///==================================================================
bool checkBlackJump (int x, int y, int newx, int newy, int red[][6], int black[][6])
{

    if (x-2 ==newx && y+2==newy)
    {
        int jumpedx=newx+1;
        int jumpedy=newy-1;

        if(checkPos(jumpedx, jumpedy, red, black)=="  " || checkPos(jumpedx, jumpedy, red, black)=="b1"
           || checkPos(jumpedx, jumpedy, red, black)=="b2")
        {
            return false;
        }

        else
            {
                red[jumpedx][jumpedy]=0;
                return true;
            }
    }
    else if (x + 2==newx && y + 2==newy)
   {
        int jumpedx=newx-1;
        int jumpedy= newy-1;

        if (checkPos(jumpedx, jumpedy, red, black)=="  " || checkPos(jumpedx, jumpedy, red, black)=="b1"
            || checkPos(jumpedx, jumpedy, red, black)=="b2")
                return false;
        else
        {
            red[jumpedx][jumpedy]=0;
            return true;
            }
   }

   else if ( x - 2 ==newx && y - 2 == newy)
   {
       int jumpedx=newx + 1;
       int jumpedy= newy + 1;

       if (checkPos(jumpedx, jumpedy, red, black)=="  " || checkPos(jumpedx, jumpedy, red, black)=="b1"
           || checkPos(jumpedx, jumpedy, red, black)=="b2")
            return false;
       else
       {
          red[jumpedx][jumpedy]=0;
          return true;
       }
   }
   else if (x+2==newx && y-2==newy)
   {
       int jumpedx=newx-1;
       int jumpedy=newy+1;

       if (checkPos(jumpedx, jumpedy, red, black)=="  " || checkPos(jumpedx, jumpedy, red, black)=="b1"
           || checkPos(jumpedx, jumpedy, red, black)=="b2")
            return false;
        else
       {
           red[jumpedx][jumpedy]=0;
           return true;
       }
   }

    return false;
}


