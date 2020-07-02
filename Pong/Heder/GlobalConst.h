#ifndef GLOBAL_CONST_H
#define GLOBAL_CONST_H

const int   WINDOW_WIDTH      =  600;
const int   WINDOW_HEIGHT     =  480;
const char  WINDOW_CAPTION[]  = { "PONG" };

const double pi               = 3.141592;

const int   H_BALL            =  5;
const int   W_BALL            =  5;

const int    H_PADDLES        =  40;
const int    W_PADDLES        =  10;

const int    X_PADDLES_PALYER =  10;
const int    Y_PADDLES_PALYER =  (WINDOW_HEIGHT / 2) - (H_PADDLES / 2);

const int    X_PADDLES_BOT    =  WINDOW_WIDTH  - 20;
const int    Y_PADDLES_BOT    =  (WINDOW_HEIGHT / 2) - (H_PADDLES / 2);

const int    X_POINT_BOT      = (WINDOW_WIDTH / 2) + 50;
const int    Y_POINT_BOT      = 10;

const int    X_POINT_PLAYER   = (WINDOW_WIDTH / 2) - 78;
const int    Y_POINT_PLAYER   = 10;

const int    X_BALL           = WINDOW_WIDTH  / 2;
const int    Y_BALL           = WINDOW_HEIGHT / 2;

const double SPEED_BOT        = 3;
const double SPEED_BALL       = 5;
const double SPEED_PLAYER     = 15;

#endif