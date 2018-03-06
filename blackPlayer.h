#ifndef BLACKPLAYER_H_INCLUDED
#define BLACKPLAYER_H_INCLUDED

void getBlackData(int &x, int &y);
bool checkBlackData (int x, int y, int red[][6], int black[][6]);
bool checkNewBlack (int newx1, int newx2, int red[][6], int black[][6]);
bool checkBlackJump (int x, int y, int newx, int newy, int red[][6], int black[][6]);
#endif // BLACKPLAYER_H_INCLUDED
