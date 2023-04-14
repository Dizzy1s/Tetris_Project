/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * This header contains the global/common variables of the project.
 * You don't really need to change anything.
 * TIP: After completing your project, you can make changes for aesthetics.
 * */

//---Title: PF-Project, Fall-2022 for BS(CS)---//
const char title[] = "PF-Project, Fall-2022";

//---Height and Width of the Actual Interactive Game---//
const int M = 20;   //Number of rows for a piece to cover on the screen (not the entire screen) = 20
const int N = 10;   //Number of columns for a piece to cover on the screen (not the entire screen) = 10

//---The Actual Interactive Game Grid - Built Over (MxN)---//
int gameGrid[M][N] = {0};

//---To Hold the Coordinates of the Piece---//
int point_1[4][4], point_2[4][4];
int shadow[4][4] = {0};
int bomb[4][4] = {0};
int bomb_2[4][4] = {0};
int next[4][4] = {0};
//---Check Uncertain Conditions---//
bool anamoly(){
    for (int i=0;i<4;i++)
        if (point_1[i][0]<0 || point_1[i][0]>=N || point_1[i][1]>=M)			// The main anamoly
            return 0;
        else if (gameGrid[point_1[i][1]][point_1[i][0]])
            return 0;
    return 1;
};
bool shadow_anamoly(){
    for (int i=0;i<4;i++)
        if (shadow[i][0]<0 || shadow[i][0]>=N || shadow[i][1]>=M-1)			// anamoly for shadows
            return 0;
        else if (gameGrid[shadow[i][1]+1][shadow[i][0]])
            return 0;
    return 1;
};
bool bomb_anamoly(){
    for (int i=0;i<4;i++)
        if (bomb[i][0]<0 || bomb[i][0]>=N || bomb[i][1]>=M)				// anamoly for bombs
            return 0;
        else if (gameGrid[bomb[i][1]][bomb[i][0]])
            return 0;
    return 1;
};



