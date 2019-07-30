#include <a_samp>
#include <YSI_Coding\y_hooks>


new PlayerText:TDEditor_PTD[MAX_PLAYERS][42];

hook OnPlayerConnect(playerid){

	TDEditor_PTD[playerid][0] = CreatePlayerTextDraw(playerid, 173.783416, 125.185226, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][0], 0.329997, 21.371103);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][0], -89.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][0], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][0], 130);
	PlayerTextDrawSetOutline(playerid, TDEditor_PTD[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][0], 3);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][0], 0);

	TDEditor_PTD[playerid][1] = CreatePlayerTextDraw(playerid, 246.716827, 142.666732, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][1], 0.287916, 21.174043);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][1], -89.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][1], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, TDEditor_PTD[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][1], 3);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][1], 0);

	TDEditor_PTD[playerid][2] = CreatePlayerTextDraw(playerid, 143.333206, 190.518646, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][2], 7.847064, -3.502243);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][2], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][2], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][2], 1);

	TDEditor_PTD[playerid][3] = CreatePlayerTextDraw(playerid, 138.333267, 346.463134, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][3], 7.847064, -3.507430);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][3], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][3], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][3], 1);

	TDEditor_PTD[playerid][4] = CreatePlayerTextDraw(playerid, 260.833465, 69.185180, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][4], 1.850414, 31.279989);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][4], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][4], -6);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][4], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, TDEditor_PTD[playerid][4], true);

	TDEditor_PTD[playerid][5] = CreatePlayerTextDraw(playerid, 260.833465, 69.185180, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][5], 1.850414, 31.279989);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][5], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][5], -6);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][5], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, TDEditor_PTD[playerid][5], true);

	TDEditor_PTD[playerid][6] = CreatePlayerTextDraw(playerid, 364.365844, 69.185180, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][6], 1.850414, 31.279989);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][6], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][6], -6);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][6], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, TDEditor_PTD[playerid][6], true);

	TDEditor_PTD[playerid][7] = CreatePlayerTextDraw(playerid, 363.532531, 69.185180, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][7], 1.850414, 31.279989);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][7], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][7], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][7], -6);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][7], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, TDEditor_PTD[playerid][7], true);

	TDEditor_PTD[playerid][8] = CreatePlayerTextDraw(playerid, 158.333358, 130.888885, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][8], 21.062900, -1.402222);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][8], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][8], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, TDEditor_PTD[playerid][8], 252);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][8], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][8], 1);

	TDEditor_PTD[playerid][9] = CreatePlayerTextDraw(playerid, 158.333358, 361.889556, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][9], 21.062900, -1.402222);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][9], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][9], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, TDEditor_PTD[playerid][9], 251);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][9], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][9], 1);

	TDEditor_PTD[playerid][10] = CreatePlayerTextDraw(playerid, -1.999976, -1.333348, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][10], 0.000000, 51.920978);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][10], 174.829193, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][10], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][10], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][10], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][10], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][10], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][10], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][10], 1);

	TDEditor_PTD[playerid][11] = CreatePlayerTextDraw(playerid, 177.500030, -94.148208, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][11], 0.000000, 24.372642);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][11], 717.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][11], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][11], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][11], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][11], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][11], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][11], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][11], 1);

	TDEditor_PTD[playerid][12] = CreatePlayerTextDraw(playerid, 177.616638, 128.588745, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][12], 0.000000, 4.168979);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][12], 272.409851, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][12], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][12], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][12], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][12], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][12], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][12], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][12], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][12], 1);

	TDEditor_PTD[playerid][13] = CreatePlayerTextDraw(playerid, 202.032516, 169.551712, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][13], 0.000000, 0.112975);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][13], 278.604064, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][13], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][13], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][13], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][13], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][13], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][13], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][13], 1);

	TDEditor_PTD[playerid][14] = CreatePlayerTextDraw(playerid, 221.132537, 174.151718, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][14], 0.000000, 0.120641);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][14], 268.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][14], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][14], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][14], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][14], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][14], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][14], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][14], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][14], 1);

	TDEditor_PTD[playerid][15] = CreatePlayerTextDraw(playerid, 238.249404, 178.620422, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][15], 0.000000, -0.007021);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][15], 274.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][15], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][15], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][15], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][15], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][15], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][15], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][15], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][15], 1);

	TDEditor_PTD[playerid][16] = CreatePlayerTextDraw(playerid, 249.032653, 181.989089, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][16], 0.000000, 16.787012);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][16], 270.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][16], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][16], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][16], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][16], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][16], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][16], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][16], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][16], 1);

	TDEditor_PTD[playerid][17] = CreatePlayerTextDraw(playerid, 177.532501, 325.450164, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][17], 0.000000, 16.872983);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][17], 197.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][17], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][17], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][17], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][17], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][17], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][17], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][17], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][17], 1);

	TDEditor_PTD[playerid][18] = CreatePlayerTextDraw(playerid, 199.382553, 330.635375, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][18], 0.000000, 21.855611);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][18], 219.110107, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][18], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][18], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][18], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][18], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][18], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][18], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][18], 1);

	TDEditor_PTD[playerid][19] = CreatePlayerTextDraw(playerid, 221.765731, 336.320434, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][19], 0.000000, 22.341608);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][19], 269.439758, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][19], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][19], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][19], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][19], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][19], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][19], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][19], 1);

	TDEditor_PTD[playerid][20] = CreatePlayerTextDraw(playerid, 272.182373, 361.727813, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][20], 0.000000, 24.716611);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][20], 707.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][20], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][20], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][20], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][20], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][20], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][20], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][20], 0);

	TDEditor_PTD[playerid][21] = CreatePlayerTextDraw(playerid, 393.266967, 401.555999, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][21], 0.962082, -26.223707);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][21], -129.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][21], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][21], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][21], 130);
	PlayerTextDrawSetOutline(playerid, TDEditor_PTD[playerid][21], -1);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][21], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][21], 3);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][21], 0);

	TDEditor_PTD[playerid][22] = CreatePlayerTextDraw(playerid, 474.100341, 377.185577, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][22], 0.962082, -26.223707);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][22], -129.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][22], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][22], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][22], 130);
	PlayerTextDrawSetOutline(playerid, TDEditor_PTD[playerid][22], -1);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][22], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][22], 3);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][22], 0);

	TDEditor_PTD[playerid][23] = CreatePlayerTextDraw(playerid, 349.166442, 312.348144, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][23], 13.162495, 5.810340);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][23], -79.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][23], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][23], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][23], -1);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][23], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][23], 2);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][23], 1);

	TDEditor_PTD[playerid][24] = CreatePlayerTextDraw(playerid, 347.916809, 106.496223, "/");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][24], 10.572904, 8.055529);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][24], -79.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][24], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][24], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][24], -1);
	PlayerTextDrawSetOutline(playerid, TDEditor_PTD[playerid][24], -5);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][24], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][24], 2);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][24], 1);

	TDEditor_PTD[playerid][25] = CreatePlayerTextDraw(playerid, 483.066986, 128.359222, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][25], 0.000000, 25.587593);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][25], 678.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][25], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][25], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][25], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][25], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][25], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][25], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][25], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][25], 1);

	TDEditor_PTD[playerid][26] = CreatePlayerTextDraw(playerid, 388.483703, 129.914840, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][26], 0.000000, 2.339261);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][26], 414.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][26], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][26], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][26], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][26], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][26], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][26], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][26], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][26], 1);

	TDEditor_PTD[playerid][27] = CreatePlayerTextDraw(playerid, 416.400360, 123.174095, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][27], 0.000000, 2.255927);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][27], 439.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][27], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][27], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][27], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][27], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][27], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][27], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][27], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][27], 1);

	TDEditor_PTD[playerid][28] = CreatePlayerTextDraw(playerid, 441.400360, 116.951873, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][28], 0.000000, 2.297593);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][28], 463.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][28], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][28], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][28], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][28], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][28], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][28], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][28], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][28], 1);

	TDEditor_PTD[playerid][29] = CreatePlayerTextDraw(playerid, 460.150573, 110.211112, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][29], 0.000000, 2.489259);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][29], 486.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][29], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][29], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][29], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][29], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][29], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][29], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][29], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][29], 1);

	TDEditor_PTD[playerid][30] = CreatePlayerTextDraw(playerid, 480.150604, 129.396301, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][30], 0.000000, 2.405925);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][30], 507.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][30], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][30], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][30], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][30], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][30], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][30], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][30], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][30], 1);

	TDEditor_PTD[playerid][31] = CreatePlayerTextDraw(playerid, 375.567352, 354.951751, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][31], 0.000000, 0.387591);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][31], 480.499969, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][31], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][31], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][31], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][31], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][31], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][31], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][31], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][31], 1);

	TDEditor_PTD[playerid][32] = CreatePlayerTextDraw(playerid, 431.817382, 346.061553, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][32], 0.000000, 0.627592);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][32], 480.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][32], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][32], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][32], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][32], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][32], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][32], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][32], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][32], 1);

	TDEditor_PTD[playerid][33] = CreatePlayerTextDraw(playerid, 458.484008, 340.876281, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][33], 0.000000, 1.502591);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][33], 484.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][33], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][33], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][33], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][33], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][33], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][33], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][33], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][33], 1);

	TDEditor_PTD[playerid][34] = CreatePlayerTextDraw(playerid, 387.650665, 154.209701, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][34], 0.000000, 25.585922);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][34], 400.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][34], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][34], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][34], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][34], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][34], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][34], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][34], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][34], 1);

	TDEditor_PTD[playerid][35] = CreatePlayerTextDraw(playerid, 376.400665, 149.024459, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][35], 0.000000, 25.585922);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][35], 389.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][35], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][35], -63);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][35], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][35], 142);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][35], 3);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][35], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][35], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][35], 1);

	TDEditor_PTD[playerid][36] = CreatePlayerTextDraw(playerid, 142.083190, 153.703750, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][36], 0.000000, 21.166667);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][36], 255.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][36], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][36], -1);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][36], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][36], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][36], 0);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][36], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][36], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][36], 1);

	TDEditor_PTD[playerid][37] = CreatePlayerTextDraw(playerid, 264.583099, 118.963027, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][37], 0.000000, 25.500001);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][37], 380.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][37], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][37], -1);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][37], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][37], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][37], 0);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][37], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][37], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][37], 1);

	TDEditor_PTD[playerid][38] = CreatePlayerTextDraw(playerid, 390.833526, 128.814895, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][38], 0.000000, 25.500001);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][38], 511.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][38], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][38], -1);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][38], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][38], 255);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][38], 0);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][38], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][38], 1);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][38], 1);

	TDEditor_PTD[playerid][39] = CreatePlayerTextDraw(playerid, 156.666534, 339.333251, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][39], 0.000000, 6.375001);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][39], 249.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][39], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][39], -1);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][39], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][39], 41);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][39], 0);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][39], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][39], 2);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][39], 1);

	TDEditor_PTD[playerid][40] = CreatePlayerTextDraw(playerid, 251.666488, 353.851776, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][40], 0.000000, 7.750000);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][40], 541.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][40], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][40], -1);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][40], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][40], 41);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][40], 0);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][40], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][40], 2);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][40], 1);

	TDEditor_PTD[playerid][41] = CreatePlayerTextDraw(playerid, 126.666397, 335.185119, "box");
	PlayerTextDrawLetterSize(playerid, TDEditor_PTD[playerid][41], 0.000000, 3.416666);
	PlayerTextDrawTextSize(playerid, TDEditor_PTD[playerid][41], 218.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDEditor_PTD[playerid][41], 1);
	PlayerTextDrawColor(playerid, TDEditor_PTD[playerid][41], -1);
	PlayerTextDrawUseBox(playerid, TDEditor_PTD[playerid][41], 1);
	PlayerTextDrawBoxColor(playerid, TDEditor_PTD[playerid][41], 41);
	PlayerTextDrawSetShadow(playerid, TDEditor_PTD[playerid][41], 0);
	PlayerTextDrawBackgroundColor(playerid, TDEditor_PTD[playerid][41], 255);
	PlayerTextDrawFont(playerid, TDEditor_PTD[playerid][41], 2);
	PlayerTextDrawSetProportional(playerid, TDEditor_PTD[playerid][41], 1);

}