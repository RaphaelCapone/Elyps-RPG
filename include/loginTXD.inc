#include <a_samp>
#include <YSI_Coding\y_hooks>

new Text:gLoginTD[35];
new PlayerText:pLoginTD[MAX_PLAYERS][6];
hook OnGamemodeInit(){
	gLoginTD[0] = TextDrawCreate(316.399627, 1.537348, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~____________________________________________________~n~~n~~n~~n~~n~~n~~n~~n~");
	TextDrawLetterSize(gLoginTD[0], 0.398750, 1.807407);
	TextDrawTextSize(gLoginTD[0], -6.650002, 261.010375);
	TextDrawAlignment(gLoginTD[0], 2);
	TextDrawColor(gLoginTD[0], -1);
	TextDrawUseBox(gLoginTD[0], 1);
	TextDrawBoxColor(gLoginTD[0], 220);
	TextDrawSetShadow(gLoginTD[0], 0);
	TextDrawBackgroundColor(gLoginTD[0], 49407);
	TextDrawFont(gLoginTD[0], 0);
	TextDrawSetProportional(gLoginTD[0], 0);

	gLoginTD[1] = TextDrawCreate(316.250000, 26.666612, "~n~");
	TextDrawLetterSize(gLoginTD[1], 1.213330, 43.081459);
	TextDrawTextSize(gLoginTD[1], 0.000000, 261.000000);
	TextDrawAlignment(gLoginTD[1], 2);
	TextDrawColor(gLoginTD[1], -1);
	TextDrawUseBox(gLoginTD[1], 1);
	TextDrawBoxColor(gLoginTD[1], 961107683);
	TextDrawSetShadow(gLoginTD[1], 0);
	TextDrawSetOutline(gLoginTD[1], 1059);
	TextDrawBackgroundColor(gLoginTD[1], 16777215);
	TextDrawFont(gLoginTD[1], 1);
	TextDrawSetProportional(gLoginTD[1], 1);

	gLoginTD[2] = TextDrawCreate(316.250122, 42.222236, "_");
	TextDrawLetterSize(gLoginTD[2], -0.235412, 1.729635);
	TextDrawTextSize(gLoginTD[2], 0.000000, 261.000000);
	TextDrawAlignment(gLoginTD[2], 2);
	TextDrawColor(gLoginTD[2], -1);
	TextDrawUseBox(gLoginTD[2], 1);
	TextDrawBoxColor(gLoginTD[2], 255);
	TextDrawSetShadow(gLoginTD[2], 0);
	TextDrawSetOutline(gLoginTD[2], 25);
	TextDrawBackgroundColor(gLoginTD[2], 255);
	TextDrawFont(gLoginTD[2], 1);
	TextDrawSetProportional(gLoginTD[2], 1);

	gLoginTD[3] = TextDrawCreate(317.916595, 0.740727, "Elyps_RPG");
	TextDrawLetterSize(gLoginTD[3], 0.604165, 2.165184);
	TextDrawAlignment(gLoginTD[3], 2);
	TextDrawColor(gLoginTD[3], -1);
	TextDrawSetShadow(gLoginTD[3], 0);
	TextDrawBackgroundColor(gLoginTD[3], 255);
	TextDrawFont(gLoginTD[3], 1);
	TextDrawSetProportional(gLoginTD[3], 1);

	gLoginTD[4] = TextDrawCreate(317.499969, 40.666645, "Register_step");
	TextDrawLetterSize(gLoginTD[4], 0.406250, 1.703703);
	TextDrawAlignment(gLoginTD[4], 2);
	TextDrawColor(gLoginTD[4], -1);
	TextDrawSetShadow(gLoginTD[4], 0);
	TextDrawBackgroundColor(gLoginTD[4], 255);
	TextDrawFont(gLoginTD[4], 1);
	TextDrawSetProportional(gLoginTD[4], 1);

	gLoginTD[5] = TextDrawCreate(370.416687, 16.296268, "v_0.1");
	TextDrawLetterSize(gLoginTD[5], 0.167080, 0.931110);
	TextDrawAlignment(gLoginTD[5], 2);
	TextDrawColor(gLoginTD[5], -1);
	TextDrawSetShadow(gLoginTD[5], 0);
	TextDrawBackgroundColor(gLoginTD[5], 255);
	TextDrawFont(gLoginTD[5], 1);
	TextDrawSetProportional(gLoginTD[5], 1);

	gLoginTD[6] = TextDrawCreate(198.749984, 95.629631, "box");
	TextDrawLetterSize(gLoginTD[6], 0.000000, 1.333333);
	TextDrawTextSize(gLoginTD[6], 317.000000, 0.000000);
	TextDrawAlignment(gLoginTD[6], 1);
	TextDrawColor(gLoginTD[6], -1);
	TextDrawUseBox(gLoginTD[6], 1);
	TextDrawBoxColor(gLoginTD[6], 255);
	TextDrawSetShadow(gLoginTD[6], 0);
	TextDrawBackgroundColor(gLoginTD[6], 255);
	TextDrawFont(gLoginTD[6], 0);
	TextDrawSetProportional(gLoginTD[6], 1);

	gLoginTD[7] = TextDrawCreate(248.333343, 93.555519, "Password");
	TextDrawLetterSize(gLoginTD[7], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[7], -9.000000, 0.000000);
	TextDrawAlignment(gLoginTD[7], 3);
	TextDrawColor(gLoginTD[7], -1);
	TextDrawSetShadow(gLoginTD[7], 0);
	TextDrawBackgroundColor(gLoginTD[7], 255);
	TextDrawFont(gLoginTD[7], 2);
	TextDrawSetProportional(gLoginTD[7], 1);
	TextDrawSetSelectable(gLoginTD[7], true);

	gLoginTD[8] = TextDrawCreate(198.749984, 125.229278, "box");
	TextDrawLetterSize(gLoginTD[8], 0.000000, 1.333333);
	TextDrawTextSize(gLoginTD[8], 317.000000, 0.000000);
	TextDrawAlignment(gLoginTD[8], 1);
	TextDrawColor(gLoginTD[8], -1);
	TextDrawUseBox(gLoginTD[8], 1);
	TextDrawBoxColor(gLoginTD[8], 255);
	TextDrawSetShadow(gLoginTD[8], 0);
	TextDrawBackgroundColor(gLoginTD[8], 255);
	TextDrawFont(gLoginTD[8], 0);
	TextDrawSetProportional(gLoginTD[8], 1);

	gLoginTD[9] = TextDrawCreate(283.316528, 123.874000, "Repeat_password");
	TextDrawLetterSize(gLoginTD[9], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[9], -9.000000, 0.000000);
	TextDrawAlignment(gLoginTD[9], 3);
	TextDrawColor(gLoginTD[9], -1);
	TextDrawSetShadow(gLoginTD[9], 0);
	TextDrawBackgroundColor(gLoginTD[9], 255);
	TextDrawFont(gLoginTD[9], 2);
	TextDrawSetProportional(gLoginTD[9], 1);
	TextDrawSetSelectable(gLoginTD[9], true);

	gLoginTD[10] = TextDrawCreate(198.749984, 155.129364, "box");
	TextDrawLetterSize(gLoginTD[10], 0.000000, 1.333333);
	TextDrawTextSize(gLoginTD[10], 317.000000, 0.000000);
	TextDrawAlignment(gLoginTD[10], 1);
	TextDrawColor(gLoginTD[10], -1);
	TextDrawUseBox(gLoginTD[10], 1);
	TextDrawBoxColor(gLoginTD[10], 255);
	TextDrawSetShadow(gLoginTD[10], 0);
	TextDrawBackgroundColor(gLoginTD[10], 255);
	TextDrawFont(gLoginTD[10], 0);
	TextDrawSetProportional(gLoginTD[10], 1);

	gLoginTD[11] = TextDrawCreate(228.917358, 153.073638, "email");
	TextDrawLetterSize(gLoginTD[11], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[11], -9.000000, 0.000000);
	TextDrawAlignment(gLoginTD[11], 3);
	TextDrawColor(gLoginTD[11], -1);
	TextDrawSetShadow(gLoginTD[11], 0);
	TextDrawBackgroundColor(gLoginTD[11], 255);
	TextDrawFont(gLoginTD[11], 2);
	TextDrawSetProportional(gLoginTD[11], 1);
	TextDrawSetSelectable(gLoginTD[11], true);

	gLoginTD[12] = TextDrawCreate(198.749984, 185.928894, "_");
	TextDrawLetterSize(gLoginTD[12], 0.000000, 1.333333);
	TextDrawTextSize(gLoginTD[12], 317.000000, 0.000000);
	TextDrawAlignment(gLoginTD[12], 1);
	TextDrawColor(gLoginTD[12], -1);
	TextDrawUseBox(gLoginTD[12], 1);
	TextDrawBoxColor(gLoginTD[12], 255);
	TextDrawSetShadow(gLoginTD[12], 0);
	TextDrawBackgroundColor(gLoginTD[12], 255);
	TextDrawFont(gLoginTD[12], 0);
	TextDrawSetProportional(gLoginTD[12], 1);

	gLoginTD[13] = TextDrawCreate(221.784088, 183.817626, "age");
	TextDrawLetterSize(gLoginTD[13], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[13], -9.000000, 0.000000);
	TextDrawAlignment(gLoginTD[13], 3);
	TextDrawColor(gLoginTD[13], -1);
	TextDrawSetShadow(gLoginTD[13], 0);
	TextDrawBackgroundColor(gLoginTD[13], 255);
	TextDrawFont(gLoginTD[13], 2);
	TextDrawSetProportional(gLoginTD[13], 1);
	TextDrawSetSelectable(gLoginTD[13], true);

	gLoginTD[14] = TextDrawCreate(325.416595, 97.185203, "box");
	TextDrawLetterSize(gLoginTD[14], 0.000000, 1.097331);
	TextDrawTextSize(gLoginTD[14], 436.000000, 0.000000);
	TextDrawAlignment(gLoginTD[14], 1);
	TextDrawColor(gLoginTD[14], -1);
	TextDrawUseBox(gLoginTD[14], 1);
	TextDrawBoxColor(gLoginTD[14], 255);
	TextDrawSetShadow(gLoginTD[14], 0);
	TextDrawBackgroundColor(gLoginTD[14], 255);
	TextDrawFont(gLoginTD[14], 1);
	TextDrawSetProportional(gLoginTD[14], 1);

	gLoginTD[15] = TextDrawCreate(325.500579, 94.073997, "your_password_must_contain_at_least_6_characters!");
	TextDrawLetterSize(gLoginTD[15], 0.113333, 1.340744);
	TextDrawTextSize(gLoginTD[15], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[15], 1);
	TextDrawColor(gLoginTD[15], -13958913);
	TextDrawSetShadow(gLoginTD[15], 0);
	TextDrawBackgroundColor(gLoginTD[15], 255);
	TextDrawFont(gLoginTD[15], 1);
	TextDrawSetProportional(gLoginTD[15], 0);

	gLoginTD[16] = TextDrawCreate(325.416595, 127.035499, "box");
	TextDrawLetterSize(gLoginTD[16], 0.000000, 1.097331);
	TextDrawTextSize(gLoginTD[16], 436.000000, 0.000000);
	TextDrawAlignment(gLoginTD[16], 1);
	TextDrawColor(gLoginTD[16], -1);
	TextDrawUseBox(gLoginTD[16], 1);
	TextDrawBoxColor(gLoginTD[16], 255);
	TextDrawSetShadow(gLoginTD[16], 0);
	TextDrawBackgroundColor(gLoginTD[16], 255);
	TextDrawFont(gLoginTD[16], 1);
	TextDrawSetProportional(gLoginTD[16], 1);

	gLoginTD[17] = TextDrawCreate(327.250885, 125.124061, "the_passwords_does_not_match!");
	TextDrawLetterSize(gLoginTD[17], 0.160833, 1.371855);
	TextDrawTextSize(gLoginTD[17], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[17], 1);
	TextDrawColor(gLoginTD[17], -13958913);
	TextDrawSetShadow(gLoginTD[17], 0);
	TextDrawBackgroundColor(gLoginTD[17], 255);
	TextDrawFont(gLoginTD[17], 1);
	TextDrawSetProportional(gLoginTD[17], 0);

	gLoginTD[18] = TextDrawCreate(325.416595, 156.685958, "box");
	TextDrawLetterSize(gLoginTD[18], 0.000000, 1.097331);
	TextDrawTextSize(gLoginTD[18], 436.000000, 0.000000);
	TextDrawAlignment(gLoginTD[18], 1);
	TextDrawColor(gLoginTD[18], -1);
	TextDrawUseBox(gLoginTD[18], 1);
	TextDrawBoxColor(gLoginTD[18], 255);
	TextDrawSetShadow(gLoginTD[18], 0);
	TextDrawBackgroundColor(gLoginTD[18], 255);
	TextDrawFont(gLoginTD[18], 1);
	TextDrawSetProportional(gLoginTD[18], 1);

	gLoginTD[19] = TextDrawCreate(328.067779, 155.098236, "invalid_email!");
	TextDrawLetterSize(gLoginTD[19], 0.160833, 1.371855);
	TextDrawTextSize(gLoginTD[19], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[19], 1);
	TextDrawColor(gLoginTD[19], -13958913);
	TextDrawSetShadow(gLoginTD[19], 0);
	TextDrawBackgroundColor(gLoginTD[19], 255);
	TextDrawFont(gLoginTD[19], 1);
	TextDrawSetProportional(gLoginTD[19], 0);

	gLoginTD[20] = TextDrawCreate(325.416595, 187.336044, "box");
	TextDrawLetterSize(gLoginTD[20], 0.000000, 1.097331);
	TextDrawTextSize(gLoginTD[20], 436.000000, 0.000000);
	TextDrawAlignment(gLoginTD[20], 1);
	TextDrawColor(gLoginTD[20], -1);
	TextDrawUseBox(gLoginTD[20], 1);
	TextDrawBoxColor(gLoginTD[20], 255);
	TextDrawSetShadow(gLoginTD[20], 0);
	TextDrawBackgroundColor(gLoginTD[20], 255);
	TextDrawFont(gLoginTD[20], 1);
	TextDrawSetProportional(gLoginTD[20], 1);

	gLoginTD[21] = TextDrawCreate(328.067779, 185.766860, "invalid_age!");
	TextDrawLetterSize(gLoginTD[21], 0.160833, 1.371855);
	TextDrawTextSize(gLoginTD[21], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[21], 1);
	TextDrawColor(gLoginTD[21], -13958913);
	TextDrawSetShadow(gLoginTD[21], 0);
	TextDrawBackgroundColor(gLoginTD[21], 255);
	TextDrawFont(gLoginTD[21], 1);
	TextDrawSetProportional(gLoginTD[21], 0);

	gLoginTD[22] = TextDrawCreate(277.916809, 376.148254, "Register");
	TextDrawLetterSize(gLoginTD[22], 0.400000, 1.600000);
	TextDrawAlignment(gLoginTD[22], 1);
	TextDrawColor(gLoginTD[22], -1);
	TextDrawSetShadow(gLoginTD[22], 0);
	TextDrawBackgroundColor(gLoginTD[22], 255);
	TextDrawFont(gLoginTD[22], 2);
	TextDrawSetProportional(gLoginTD[22], 1);
	TextDrawSetSelectable(gLoginTD[22], true);

	gLoginTD[23] = TextDrawCreate(316.666748, 374.074005, "_");
	TextDrawLetterSize(gLoginTD[23], 0.051249, 2.247776);
	TextDrawTextSize(gLoginTD[23], 0.000000, 92.000000);
	TextDrawAlignment(gLoginTD[23], 2);
	TextDrawColor(gLoginTD[23], -1);
	TextDrawUseBox(gLoginTD[23], 1);
	TextDrawBoxColor(gLoginTD[23], 255);
	TextDrawSetShadow(gLoginTD[23], 0);
	TextDrawBackgroundColor(gLoginTD[23], 255);
	TextDrawFont(gLoginTD[23], 1);
	TextDrawSetProportional(gLoginTD[23], 1);

	gLoginTD[24] = TextDrawCreate(201.249893, 240.814941, "error");
	TextDrawLetterSize(gLoginTD[24], 0.266665, 1.154072);
	TextDrawAlignment(gLoginTD[24], 1);
	TextDrawColor(gLoginTD[24], -2013265665);
	TextDrawSetShadow(gLoginTD[24], 0);
	TextDrawBackgroundColor(gLoginTD[24], 255);
	TextDrawFont(gLoginTD[24], 2);
	TextDrawSetProportional(gLoginTD[24], 1);

	gLoginTD[25] = TextDrawCreate(198.966644, 242.157470, "_");
	TextDrawLetterSize(gLoginTD[25], -0.217083, 2.891112);
	TextDrawTextSize(gLoginTD[25], 315.800048, 0.000000);
	TextDrawAlignment(gLoginTD[25], 1);
	TextDrawColor(gLoginTD[25], -1);
	TextDrawUseBox(gLoginTD[25], 1);
	TextDrawBoxColor(gLoginTD[25], 255);
	TextDrawSetShadow(gLoginTD[25], 0);
	TextDrawBackgroundColor(gLoginTD[25], 255);
	TextDrawFont(gLoginTD[25], 1);
	TextDrawSetProportional(gLoginTD[25], 1);

	gLoginTD[26] = TextDrawCreate(207.500015, 252.740676, "Please_complete_all_forms!");
	TextDrawLetterSize(gLoginTD[26], 0.169999, 1.340741);
	TextDrawTextSize(gLoginTD[26], -31.000000, 0.000000);
	TextDrawAlignment(gLoginTD[26], 1);
	TextDrawColor(gLoginTD[26], -1);
	TextDrawSetShadow(gLoginTD[26], 0);
	TextDrawBackgroundColor(gLoginTD[26], 255);
	TextDrawFont(gLoginTD[26], 2);
	TextDrawSetProportional(gLoginTD[26], 1);

	gLoginTD[27] = TextDrawCreate(391.249542, 272.963134, "box");
	TextDrawLetterSize(gLoginTD[27], 0.000000, 1.500000);
	TextDrawTextSize(gLoginTD[27], 0.000000, 101.000000);
	TextDrawAlignment(gLoginTD[27], 2);
	TextDrawUseBox(gLoginTD[27], 1);
	TextDrawBoxColor(gLoginTD[27], 255);
	TextDrawSetShadow(gLoginTD[27], 0);
	TextDrawFont(gLoginTD[27], 1);
	TextDrawSetProportional(gLoginTD[27], 1);

	gLoginTD[28] = TextDrawCreate(350.833465, 272.962951, "Choose_Skin");
	TextDrawLetterSize(gLoginTD[28], 0.302082, 1.345926);
	TextDrawAlignment(gLoginTD[28], 1);
	TextDrawColor(gLoginTD[28], -1);
	TextDrawSetShadow(gLoginTD[28], 0);
	TextDrawBackgroundColor(gLoginTD[28], 255);
	TextDrawFont(gLoginTD[28], 2);
	TextDrawSetProportional(gLoginTD[28], 1);

	gLoginTD[29] = TextDrawCreate(364.999938, 326.629791, "LD_BEAT:left");
	TextDrawTextSize(gLoginTD[29], 17.000000, 13.000000);
	TextDrawAlignment(gLoginTD[29], 1);
	TextDrawColor(gLoginTD[29], -1);
	TextDrawSetShadow(gLoginTD[29], 0);
	TextDrawBackgroundColor(gLoginTD[29], 255);
	TextDrawFont(gLoginTD[29], 4);
	TextDrawSetProportional(gLoginTD[29], 0);

	gLoginTD[30] = TextDrawCreate(415.916168, 326.111267, "LD_BEAT:right");
	TextDrawTextSize(gLoginTD[30], 17.000000, 13.000000);
	TextDrawAlignment(gLoginTD[30], 1);
	TextDrawColor(gLoginTD[30], -1);
	TextDrawSetShadow(gLoginTD[30], 0);
	TextDrawBackgroundColor(gLoginTD[30], 255);
	TextDrawFont(gLoginTD[30], 4);
	TextDrawSetProportional(gLoginTD[30], 0);
	TextDrawSetSelectable(gLoginTD[30], true);

	gLoginTD[31] = TextDrawCreate(198.749984, 216.578857, "_");
	TextDrawLetterSize(gLoginTD[31], 0.000000, 1.333333);
	TextDrawTextSize(gLoginTD[31], 317.000000, 0.000000);
	TextDrawAlignment(gLoginTD[31], 1);
	TextDrawColor(gLoginTD[31], -1);
	TextDrawUseBox(gLoginTD[31], 1);
	TextDrawBoxColor(gLoginTD[31], 255);
	TextDrawSetShadow(gLoginTD[31], 0);
	TextDrawBackgroundColor(gLoginTD[31], 255);
	TextDrawFont(gLoginTD[31], 0);
	TextDrawSetProportional(gLoginTD[31], 1);

	gLoginTD[32] = TextDrawCreate(237.184020, 214.917785, "Gender");
	TextDrawLetterSize(gLoginTD[32], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[32], -9.000000, 0.000000);
	TextDrawAlignment(gLoginTD[32], 3);
	TextDrawColor(gLoginTD[32], -1);
	TextDrawSetShadow(gLoginTD[32], 0);
	TextDrawBackgroundColor(gLoginTD[32], 255);
	TextDrawFont(gLoginTD[32], 2);
	TextDrawSetProportional(gLoginTD[32], 1);
	TextDrawSetSelectable(gLoginTD[32], true);

	gLoginTD[33] = TextDrawCreate(325.416595, 218.035995, "box");
	TextDrawLetterSize(gLoginTD[33], 0.000000, 1.097331);
	TextDrawTextSize(gLoginTD[33], 436.000000, 0.000000);
	TextDrawAlignment(gLoginTD[33], 1);
	TextDrawColor(gLoginTD[33], -1);
	TextDrawUseBox(gLoginTD[33], 1);
	TextDrawBoxColor(gLoginTD[33], 255);
	TextDrawSetShadow(gLoginTD[33], 0);
	TextDrawBackgroundColor(gLoginTD[33], 255);
	TextDrawFont(gLoginTD[33], 1);
	TextDrawSetProportional(gLoginTD[33], 1);

	gLoginTD[34] = TextDrawCreate(328.067779, 216.017120, "please_choose_a_gender!");
	TextDrawLetterSize(gLoginTD[34], 0.160833, 1.371855);
	TextDrawTextSize(gLoginTD[34], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[34], 1);
	TextDrawColor(gLoginTD[34], -13958913);
	TextDrawSetShadow(gLoginTD[34], 0);
	TextDrawBackgroundColor(gLoginTD[34], 255);
	TextDrawFont(gLoginTD[34], 1);
	TextDrawSetProportional(gLoginTD[34], 0);
}
hook OnPlayerConnect(playerid){
	pLoginTD[playerid][0] = CreatePlayerTextDraw(playerid, 303.333312, 94.140342, "LD_CHAT:thumbup");
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][0], 13.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][0], 0);

	pLoginTD[playerid][1] = CreatePlayerTextDraw(playerid, 303.333312, 123.709266, "LD_CHAT:thumbup");
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][1], 13.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][1], 0);

	pLoginTD[playerid][2] = CreatePlayerTextDraw(playerid, 303.333312, 153.709259, "LD_CHAT:thumbup");
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][2], 13.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][2], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][2], 0);

	pLoginTD[playerid][3] = CreatePlayerTextDraw(playerid, 302.916656, 184.709259, "LD_CHAT:thumbup");
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][3], 13.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][3], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][3], 0);

	pLoginTD[playerid][4] = CreatePlayerTextDraw(playerid, 360.833343, 287.152648, "");
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][4], 75.000000, 84.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][4], 0);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][4], 5);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][4], 0);
	PlayerTextDrawSetPreviewModel(playerid, pLoginTD[playerid][4], 0);
	PlayerTextDrawSetPreviewRot(playerid, pLoginTD[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);

	pLoginTD[playerid][5] = CreatePlayerTextDraw(playerid, 302.916656, 215.009140, "LD_CHAT:thumbup");
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][5], 13.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][5], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][5], 0);
}