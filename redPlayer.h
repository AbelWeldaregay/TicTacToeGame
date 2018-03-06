#ifndef REDPLAYER_H_INCLUDED
#define REDPLAYER_H_INCLUDED
using namespace std;

bool checkRedJump (int x, int y, int newx, int newy, int red[][6], int black[][6]);
string checkPos(int x, int y, int red[][6], int black[][6]);
void getRedData(int &x, int &y);
bool checkRed (int x, int y, int red[][6], int black[][6]);
bool checkNewRed (int newx, int newy, int red[][6], int black[][6]);
#endif // REDPLAYER_H_INCLUDED
