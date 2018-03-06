#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "redPlayer.h"
#include "blackPlayer.h"

using namespace std;

// check if a certain position on the board is occupied by a red or black piece

//print board according to red and black arrays indicating positions on the board
void printBoard(int red[][6], int black[][6])
{
    cout << "\n";
    cout << "   ____ ____ ____ ____ ____ ____ " << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "5 | " << checkPos(0, 5, red, black) << " |    | " << checkPos(2, 5, red, black) << " |    | " << checkPos(4, 5, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "4 |    | " << checkPos(1, 4, red, black) << " |    | " << checkPos(3, 4, red, black) << " |    | " << checkPos(5, 4, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "3 | " << checkPos(0, 3, red, black) << " |    | " << checkPos(2, 3, red, black) << " |    | " << checkPos(4, 3, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "2 |    | " << checkPos(1, 2, red, black) << " |    | " << checkPos(3, 2, red, black) << " |    | " << checkPos(5, 2, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "1 | " << checkPos(0, 1, red, black) << " |    | " << checkPos(2, 1, red, black) << " |    | " << checkPos(4, 1, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "0 |    | " << checkPos(1, 0, red, black) << " |    | " << checkPos(3, 0, red, black) << " |    | " << checkPos(5, 0, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "    0    1    2    3    4    5   \n" << endl;
}

void initializePieces(int red[][6], int black[][6])
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            red[i][j] = 0;
            black[i][j] = 0;
        }
    red[0][1] = 1;
    red[1][0] = 2;
    red[2][1] = 1;
    red[3][0] = 2;
    red[4][1] = 1;
    red[5][0] = 2;

    black[0][5] = 2;
    black[1][4] = 1;
    black[2][5] = 2;
    black[3][4] = 1;
    black[4][5] = 2;
    black[5][4] = 1;

}

bool checkLikeJumps(int x, int y, int jumpedx, int jumpedy, int red[][6], int black[][6])
{
  if ( (checkPos(jumpedx, jumpedy, red, black)=="r1" &&
                 checkPos(x, y, red, black)!="b1") ||
                 checkPos(jumpedx, jumpedy, red, black)=="r2" &&
                 checkPos(x, y, red, black)!="b2" ||
                 checkPos(x, y, red, black)=="r1" &&
                 checkPos(jumpedx, jumpedy, red, black)!="b1" ||
                 checkPos(x, y, red, black)=="r2" &&
                 checkPos(jumpedx, jumpedy, red, black)!="b2")
                    return false;
         else if (checkPos(jumpedx, jumpedy, red, black)=="b1" &&
                     checkPos(x, y, red, black)!="r1" ||
                     checkPos(x, y, red, black)=="b2" &&
                     checkPos(jumpedx, jumpedy, red, black)!="r2")
                        return false;
        else
            return true;
}


///++++++++++++++++++checkEmptyJump function description
///if the x coordinate of the selected positon (the piece doing the jumping) - 2 == to the newx and
///and the y coordinate of the selected position + 2== newy
///then the piece is equal to the newx+1 and the newy-1;
///use the checkPos function to find out what is inside the coordinates
///if the jumped piece is a blank then return false
///call the function checkLikeJumps to check if it is not jumping like pieces, which is expanded below
///else if the jumped piece is equal "r1" and the selected position(the piece doing the jumping)
///is not equal to "b1" or if the jumped piece is qual to "r2" and the selected piece is not equal to "b2"
///or if the selected piece is equal to "r1" and the jumped piece is not equal to "b1" or if the selected
///piece is equal to "r2" and the jumped piece is not equal to "b2" then return false; else return true.
///else if the x coordinate + 2 == newx and the y coordinate of the selected piece + 2==newy
///then the jumped x = newx -1 and the jumpedy = newy-1;
///then check if it is not jumping a piece that does not match its number the same way explained in lines 16-22.
///else if the selected x postion + 2 ==newx and the selected postion-2 is equal to newy
///the jumped x is qual to the newx-1 and the jumpedy=newy+1.
///then check if it is not jumping a invalid piece the same way explained in lines 16-22.
bool checkEmptyJump (int x, int y, int newx, int newy, int red[][6], int black[][6])
{
    string blank = "  ";
     if (x-2 ==newx && y+2==newy)
    {
        int jumpedx=newx+1;
        int jumpedy=newy-1;

        if(checkPos(jumpedx, jumpedy, red, black)==blank)
            return false;

        else if(checkLikeJumps(x, y, jumpedx, jumpedy, red, black)==false)
            return false;
        else
          return true;

    }
    else if (x + 2==newx && y + 2==newy)
   {
        int jumpedx=newx-1;
        int jumpedy= newy-1;

        if (checkPos(jumpedx, jumpedy, red, black)==blank)
            return false;
        else if(checkLikeJumps(x, y, jumpedx, jumpedy, red, black)==false)
            return false;
        else
            return true;

   }
   else if ( x - 2 ==newx && y - 2 == newy)
   {
       int jumpedx=newx + 1;
       int jumpedy= newy + 1;

       if (checkPos(jumpedx, jumpedy, red, black)=="  ")
            return false;
        else if(checkLikeJumps(x, y, jumpedx, jumpedy, red, black)==false)
            return false;
        else
           return true;
   }
   else if (x+2==newx && y-2==newy)
   {
       int jumpedx=newx-1;
       int jumpedy=newy+1;

       if (checkPos(jumpedx, jumpedy, red, black)=="  ")
            return false;
        else if (checkLikeJumps(x, y, jumpedx, jumpedy, red, black)==false)
            return false;
        else
            return true;
   }
    else if (x+1==newx && y+1==newy)
    {
       return true;
    }
    else if (x-1 ==newx && y+1==newy)
    {
       return true;
    }
    else if (x-1 ==newx && y-1==newy)
    {
       return true;
    }
    else if (x+1==newx && y-1 == newy)
    {
       return true;
    }


    return false;

}


void playGame(int red[][6], int black[][6], int &redPoints, int &blackPoints)
{

    int x=0, y=0;
    int newx=0, newy=0;
    int x2=0, y2=0;
    int newx1=0, newy2=0;
    redPoints=0;
    blackPoints=0;
    int redScore=0, blackScore=0;
    ///it will loop until one of the scores equals to 3
    while (redScore!=3 || blackScore!=3)
    {
        ///**Get the position of the piece to be moved from the red player.
        getRedData(x , y);

        ///while the checkRed function evaluates to false, it will print out that it is an invalid input and ask the user to enter a new one.
        while (checkRed(x, y, red, black)==false)
        {
            cout<<"\ninvalid input, please try again \n"<<endl;
            getRedData(x, y);
        }
        ///ask the user to enter the position it wants to move to and validate the input
        cout<<"Red player, select the place to move your piece (x y) (-1 -1 to pass): ";
        cin>>newx>>newy;
        ///if red x value and y value is equal to negative 1, print out skipping your turn
         if (newx==-1 && newy==-1)
            {
                cout<<"skipping your turn.\n"<<endl;

            }
        else{
                ///else check for an empty jump
                while (checkEmptyJump(x, y, newx, newy, red, black)==false)
                {
                    if (newx == -1 && newy == -1)
                        break;
                    else
                    {
                        cout<<"\nInvalid jump by red player, Please enter again: ";
                        cin >> newx >> newy;
                    }
                }

                ///now check if the newx and newy values are too big or too little by calling checkNewRed function.
                while(checkNewRed(newx, newy, red, black)==false)
                {
                    if (newx == -1 && newy == -1)
                        break;
                    else
                    {
                        cout<<"\ninvalid position, please enter again: ";
                        cin >> newx >> newy;
                    }

                }

                ///call the checkRedJump in playgame function in an if statement to determine weather to increment points.
                if(checkRedJump(x, y, newx, newy, red, black)==true)
                {
                    redPoints+=1;
                    redScore=redPoints;
                }
                ///now use the swap function to switch positions of the initial postion with the new position.
                if (newx!=-1 && newy!=-1)
                {
                    swap(red[x][y],red[newx][newy]);
                }

        }

        ///right after the red turn finishes, check if there is a winner.
        ///if the red points is qual to 3 print out that red wins and use a break statement to exit
        ///else if the blackPoints is equal to 3, print out that blackPoints wins and use a break statement to exit.
        if (redPoints==3)
            {
                printBoard(red, black);
                cout<<"**********************************"<<endl;
                cout<<"Red Player Score: "<<redPoints<<endl;
                cout<<"Black Player Score: "<<blackPoints<<endl;
                cout<<"GAME OVER! RED PLAYER WINS!"<<endl;
                cout<<"**********************************"<<endl;
                break;
            }
        else if(blackPoints==3)
            {
                printBoard(red, black);
                cout<<"*************************************"<<endl;
                cout<<"Red Player Score: "<<redPoints<<endl;
                cout<<"Black Player Score: "<<blackPoints<<endl;
                cout<<"GAME OVER! BLACK PLAYER WINS!"<<endl;
                cout<<"*************************************"<<endl;
                break;
            }

        printBoard(red, black);

        cout<<"Red points: "<<redScore<<endl;
        cout<<"Black points: "<<blackScore<<endl;
        ///prompt the black player to enter position of the piece to be moved.
        getBlackData(x2, y2);

        ///check if the values inputed by the black player are valid.
        ///while checkBlackdata function is ==false, print out an invalid statement and ask black player to enter again.
        while (checkBlackData(x2, y2, red, black)==false)
        {
            cout<<"\nInvalid position\n"<<endl;
            getBlackData(x2, y2);
        }

        ///prompt the black player to enter the new position it would like to move to and store them
        cout<<"\nBlack player, select the place to move your piece (x y) (-1 -1 to pass): ";
        cin >> newx1 >> newy2;

    ///check if newx and newy is equal to -1, if they are skip the turn and tell the user.
        if (newx1==-1 && newy2 == -1)
        {
            cout<<"\nSkipping your turn."<<endl;
        }
        else
        {
            ///call the function checkEmptyJump to check if it is jumping an empty space, or if it is jumping its own pieces.
            while(checkEmptyJump(x2, y2, newx1, newy2, red, black)==false)
            {

                if(newx1==-1&&newy2==-1)
                    break;
                else
                {
                    cout<<"\nInvalid input by black player, Please enter again: ";
                    cin>> newx1 >> newy2;
                }

            }
        ///call the function checkNewBlack to check it is landing on a piece.
        while(checkNewBlack(newx1, newy2, red, black)==false)
        {
            if (newx1==-1 && newy2==-1)
                break;
            else
                cout<<"\nInvalid input, please try again: ";
                cin >> newx1 >> newy2;
        }
        ///call the function checkBlackJump to check if the jump is valid and to clear the position that was jumped.
        ///if the checkBlackJump evaluates to true, increment the blackPoints.
        if (checkBlackJump(x2, y2, newx1, newy2, red, black)==true)
        {
            blackPoints=blackPoints+1;
            blackScore=blackPoints;
        }
        ///using the swap function, swap selected black postion with the new selected black postion.
        if (newx1!=-1 && newy2!=-1)
        {
              swap(black[x2][y2],black[newx1][newy2]);
        }


        if (redPoints==3)
        {
            printBoard(red, black);
            cout<<"**********************************"<<endl;
            cout<<"Red Player Score: "<<redPoints<<endl;
            cout<<"Black Player Score: "<<blackPoints<<endl;
            cout<<"GAME OVER! RED PLAYER WINS!"<<endl;
            cout<<"**********************************"<<endl;
            break;
        }
        else if(blackPoints==3)
        {
            printBoard(red, black);
            cout<<"*************************************"<<endl;
            cout<<"Red Player Score: "<<redPoints<<endl;
            cout<<"Black Player Score: "<<blackPoints<<endl;
            cout<<"GAME OVER! BLACK PLAYER WINS!"<<endl;
            cout<<"*************************************"<<endl;
            break;
        }
    }

        printBoard(red, black);


    } ///end of loop
    } /// end of function

int main()
{
    int red[6][6];
    int black[6][6];
    int redPoints = 0;
    int blackPoints = 0;
    initializePieces(red, black);
    printBoard(red, black);
    playGame(red, black, redPoints, blackPoints);
    return 0;
}

