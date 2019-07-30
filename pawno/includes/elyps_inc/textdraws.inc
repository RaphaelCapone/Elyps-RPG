#include <a_samp>
new PlayerText:IntroTD1[MAX_PLAYERS][3];
new PlayerText:IntroTD2[MAX_PLAYERS][45];
new PlayerText:IntroTD3[MAX_PLAYERS][55];
new PlayerText:pLoginTD[MAX_PLAYERS][7];
new PlayerText:IntroTD4[MAX_PLAYERS][36];
new Text:gLoginTD[34];

new CivilSkins[2][] = {
	{188, 170, 250, 289, 23},
	{12, 55, 56, 65, 226, 216}
};

//native TutorialTextDrawLoad(playerid, IntroStep, bool:load);
forward TutorialTextDrawLoad(playerid, IntroStep, bool:load);
forward LoadGlobalTextDraws();
forward LoadPlayerTextDraws(playerid);

public LoadGlobalTextDraws(){
	//TEXTDRAW LOGIN SYSTEM//======================================================================================================================================================================
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

	gLoginTD[7] = TextDrawCreate(203.866226, 93.555519, "Password");
	TextDrawLetterSize(gLoginTD[7], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[7], 249.000000, 10.000000);
	TextDrawAlignment(gLoginTD[7], 1);
	TextDrawColor(gLoginTD[7], -1);
	TextDrawUseBox(gLoginTD[7], 1);
	TextDrawBoxColor(gLoginTD[7], 0);
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

	gLoginTD[9] = TextDrawCreate(204.214996, 123.874000, "Repeat_password");
	TextDrawLetterSize(gLoginTD[9], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[9], 284.000000, 10.000000);
	TextDrawAlignment(gLoginTD[9], 1);
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

	gLoginTD[11] = TextDrawCreate(205.267486, 153.073638, "email");
	TextDrawLetterSize(gLoginTD[11], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[11], 230.000000, 10.000000);
	TextDrawAlignment(gLoginTD[11], 1);
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

	gLoginTD[13] = TextDrawCreate(205.533828, 183.817626, "age");
	TextDrawLetterSize(gLoginTD[13], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[13], 223.000000, 10.000000);
	TextDrawAlignment(gLoginTD[13], 1);
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

/*	gLoginTD[15] = TextDrawCreate(325.500579, 94.073997, "your_password_must_contain_at_least_6_characters!");
	TextDrawLetterSize(gLoginTD[15], 0.113333, 1.340744);
	TextDrawTextSize(gLoginTD[15], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[15], 1);
	TextDrawColor(gLoginTD[15], -13958913);
	TextDrawSetShadow(gLoginTD[15], 0);
	TextDrawBackgroundColor(gLoginTD[15], 255);
	TextDrawFont(gLoginTD[15], 1);
	TextDrawSetProportional(gLoginTD[15], 0);*/

	gLoginTD[15] = TextDrawCreate(325.416595, 127.035499, "box");
	TextDrawLetterSize(gLoginTD[15], 0.000000, 1.097331);
	TextDrawTextSize(gLoginTD[15], 436.000000, 0.000000);
	TextDrawAlignment(gLoginTD[15], 1);
	TextDrawColor(gLoginTD[15], -1);
	TextDrawUseBox(gLoginTD[15], 1);
	TextDrawBoxColor(gLoginTD[15], 255);
	TextDrawSetShadow(gLoginTD[15], 0);
	TextDrawBackgroundColor(gLoginTD[15], 255);
	TextDrawFont(gLoginTD[15], 1);
	TextDrawSetProportional(gLoginTD[15], 1);

	gLoginTD[16] = TextDrawCreate(327.250885, 125.124061, "the_passwords_does_not_match!");
	TextDrawLetterSize(gLoginTD[16], 0.160833, 1.371855);
	TextDrawTextSize(gLoginTD[16], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[16], 1);
	TextDrawColor(gLoginTD[16], -13958913);
	TextDrawSetShadow(gLoginTD[16], 0);
	TextDrawBackgroundColor(gLoginTD[16], 255);
	TextDrawFont(gLoginTD[16], 1);
	TextDrawSetProportional(gLoginTD[16], 0);

	gLoginTD[17] = TextDrawCreate(325.416595, 156.685958, "box");
	TextDrawLetterSize(gLoginTD[17], 0.000000, 1.097331);
	TextDrawTextSize(gLoginTD[17], 436.000000, 0.000000);
	TextDrawAlignment(gLoginTD[17], 1);
	TextDrawColor(gLoginTD[17], -1);
	TextDrawUseBox(gLoginTD[17], 1);
	TextDrawBoxColor(gLoginTD[17], 255);
	TextDrawSetShadow(gLoginTD[17], 0);
	TextDrawBackgroundColor(gLoginTD[17], 255);
	TextDrawFont(gLoginTD[17], 1);
	TextDrawSetProportional(gLoginTD[17], 1);

	gLoginTD[18] = TextDrawCreate(328.067779, 155.098236, "invalid_email!");
	TextDrawLetterSize(gLoginTD[18], 0.160833, 1.371855);
	TextDrawTextSize(gLoginTD[18], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[18], 1);
	TextDrawColor(gLoginTD[18], -13958913);
	TextDrawSetShadow(gLoginTD[18], 0);
	TextDrawBackgroundColor(gLoginTD[18], 255);
	TextDrawFont(gLoginTD[18], 1);
	TextDrawSetProportional(gLoginTD[18], 0);

	gLoginTD[19] = TextDrawCreate(325.416595, 187.336044, "box");
	TextDrawLetterSize(gLoginTD[19], 0.000000, 1.097331);
	TextDrawTextSize(gLoginTD[19], 436.000000, 0.000000);
	TextDrawAlignment(gLoginTD[19], 1);
	TextDrawColor(gLoginTD[19], -1);
	TextDrawUseBox(gLoginTD[19], 1);
	TextDrawBoxColor(gLoginTD[19], 255);
	TextDrawSetShadow(gLoginTD[19], 0);
	TextDrawBackgroundColor(gLoginTD[19], 255);
	TextDrawFont(gLoginTD[19], 1);
	TextDrawSetProportional(gLoginTD[19], 1);

	gLoginTD[20] = TextDrawCreate(328.067779, 185.766860, "invalid_age!");
	TextDrawLetterSize(gLoginTD[20], 0.160833, 1.371855);
	TextDrawTextSize(gLoginTD[20], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[20], 1);
	TextDrawColor(gLoginTD[20], -13958913);
	TextDrawSetShadow(gLoginTD[20], 0);
	TextDrawBackgroundColor(gLoginTD[20], 255);
	TextDrawFont(gLoginTD[20], 1);
	TextDrawSetProportional(gLoginTD[20], 0);

	gLoginTD[21] = TextDrawCreate(277.916809, 376.148254, "Register");
	TextDrawLetterSize(gLoginTD[21], 0.400000, 1.600000);
	TextDrawTextSize(gLoginTD[21], 355.000000, 12.000000);
	TextDrawAlignment(gLoginTD[21], 1);
	TextDrawColor(gLoginTD[21], -1);
	TextDrawSetShadow(gLoginTD[21], 0);
	TextDrawBackgroundColor(gLoginTD[21], 255);
	TextDrawFont(gLoginTD[21], 2);
	TextDrawSetProportional(gLoginTD[21], 1);
	TextDrawSetSelectable(gLoginTD[21], true);

	gLoginTD[22] = TextDrawCreate(316.666748, 374.074005, "_");
	TextDrawLetterSize(gLoginTD[22], 0.051249, 2.247776);
	TextDrawTextSize(gLoginTD[22], 0.000000, 92.000000);
	TextDrawAlignment(gLoginTD[22], 2);
	TextDrawColor(gLoginTD[22], -1);
	TextDrawUseBox(gLoginTD[22], 1);
	TextDrawBoxColor(gLoginTD[22], 255);
	TextDrawSetShadow(gLoginTD[22], 0);
	TextDrawBackgroundColor(gLoginTD[22], 255);
	TextDrawFont(gLoginTD[22], 1);
	TextDrawSetProportional(gLoginTD[22], 1);

	gLoginTD[23] = TextDrawCreate(201.249893, 240.814941, "error");
	TextDrawLetterSize(gLoginTD[23], 0.266665, 1.154072);
	TextDrawAlignment(gLoginTD[23], 1);
	TextDrawColor(gLoginTD[23], -2013265665);
	TextDrawSetShadow(gLoginTD[23], 0);
	TextDrawBackgroundColor(gLoginTD[23], 255);
	TextDrawFont(gLoginTD[23], 2);
	TextDrawSetProportional(gLoginTD[23], 1);

	gLoginTD[24] = TextDrawCreate(198.966644, 242.157470, "_");
	TextDrawLetterSize(gLoginTD[24], -0.217083, 2.891112);
	TextDrawTextSize(gLoginTD[24], 315.800048, 0.000000);
	TextDrawAlignment(gLoginTD[24], 1);
	TextDrawColor(gLoginTD[24], -1);
	TextDrawUseBox(gLoginTD[24], 1);
	TextDrawBoxColor(gLoginTD[24], 255);
	TextDrawSetShadow(gLoginTD[24], 0);
	TextDrawBackgroundColor(gLoginTD[24], 255);
	TextDrawFont(gLoginTD[24], 1);
	TextDrawSetProportional(gLoginTD[24], 1);

	gLoginTD[25] = TextDrawCreate(207.500015, 252.740676, "Please_complete_all_forms!");
	TextDrawLetterSize(gLoginTD[25], 0.169999, 1.340741);
	TextDrawTextSize(gLoginTD[25], -31.000000, 0.000000);
	TextDrawAlignment(gLoginTD[25], 1);
	TextDrawColor(gLoginTD[25], -1);
	TextDrawSetShadow(gLoginTD[25], 0);
	TextDrawBackgroundColor(gLoginTD[25], 255);
	TextDrawFont(gLoginTD[25], 2);
	TextDrawSetProportional(gLoginTD[25], 1);

	gLoginTD[26] = TextDrawCreate(391.249542, 272.963134, "box");
	TextDrawLetterSize(gLoginTD[26], 0.000000, 1.500000);
	TextDrawTextSize(gLoginTD[26], 0.000000, 101.000000);
	TextDrawAlignment(gLoginTD[26], 2);
	TextDrawUseBox(gLoginTD[26], 1);
	TextDrawBoxColor(gLoginTD[26], 255);
	TextDrawSetShadow(gLoginTD[26], 0);
	TextDrawFont(gLoginTD[26], 1);
	TextDrawSetProportional(gLoginTD[26], 1);

	gLoginTD[27] = TextDrawCreate(350.833465, 272.962951, "Choose_Skin");
	TextDrawLetterSize(gLoginTD[27], 0.302082, 1.345926);
	TextDrawAlignment(gLoginTD[27], 1);
	TextDrawColor(gLoginTD[27], -1);
	TextDrawSetShadow(gLoginTD[27], 0);
	TextDrawBackgroundColor(gLoginTD[27], 255);
	TextDrawFont(gLoginTD[27], 2);
	TextDrawSetProportional(gLoginTD[27], 1);

	gLoginTD[28] = TextDrawCreate(364.999938, 326.629791, "LD_BEAT:left");
	TextDrawTextSize(gLoginTD[28], 17.000000, 13.000000);
	TextDrawAlignment(gLoginTD[28], 1);
	TextDrawColor(gLoginTD[28], -1);
	TextDrawSetShadow(gLoginTD[28], 0);
	TextDrawBackgroundColor(gLoginTD[28], 255);
	TextDrawFont(gLoginTD[28], 4);
	TextDrawSetProportional(gLoginTD[28], 0);
	TextDrawSetSelectable(gLoginTD[28], true);

	gLoginTD[29] = TextDrawCreate(415.916168, 326.111267, "LD_BEAT:right");
	TextDrawTextSize(gLoginTD[29], 17.000000, 13.000000);
	TextDrawAlignment(gLoginTD[29], 1);
	TextDrawColor(gLoginTD[29], -1);
	TextDrawSetShadow(gLoginTD[29], 0);
	TextDrawBackgroundColor(gLoginTD[29], 255);
	TextDrawFont(gLoginTD[29], 4);
	TextDrawSetProportional(gLoginTD[29], 0);
	TextDrawSetSelectable(gLoginTD[29], true);

	gLoginTD[30] = TextDrawCreate(198.749984, 216.578857, "_");
	TextDrawLetterSize(gLoginTD[30], 0.000000, 1.333333);
	TextDrawTextSize(gLoginTD[30], 317.000000, 0.000000);
	TextDrawAlignment(gLoginTD[30], 1);
	TextDrawColor(gLoginTD[30], -1);
	TextDrawUseBox(gLoginTD[30], 1);
	TextDrawBoxColor(gLoginTD[30], 255);
	TextDrawSetShadow(gLoginTD[30], 0);
	TextDrawBackgroundColor(gLoginTD[30], 255);
	TextDrawFont(gLoginTD[30], 0);
	TextDrawSetProportional(gLoginTD[30], 1);

	gLoginTD[31] = TextDrawCreate(204.433853, 214.917785, "Gender");
	TextDrawLetterSize(gLoginTD[31], 0.203749, 1.527405);
	TextDrawTextSize(gLoginTD[31], 237.000000, 10.000000);
	TextDrawAlignment(gLoginTD[31], 1);
	TextDrawColor(gLoginTD[31], -1);
	TextDrawSetShadow(gLoginTD[31], 0);
	TextDrawBackgroundColor(gLoginTD[31], 255);
	TextDrawFont(gLoginTD[31], 2);
	TextDrawSetProportional(gLoginTD[31], 1);
	TextDrawSetSelectable(gLoginTD[31], true);

	gLoginTD[32] = TextDrawCreate(325.416595, 218.035995, "box");
	TextDrawLetterSize(gLoginTD[32], 0.000000, 1.097331);
	TextDrawTextSize(gLoginTD[32], 436.000000, 0.000000);
	TextDrawAlignment(gLoginTD[32], 1);
	TextDrawColor(gLoginTD[32], -1);
	TextDrawUseBox(gLoginTD[32], 1);
	TextDrawBoxColor(gLoginTD[32], 255);
	TextDrawSetShadow(gLoginTD[32], 0);
	TextDrawBackgroundColor(gLoginTD[32], 255);
	TextDrawFont(gLoginTD[32], 1);
	TextDrawSetProportional(gLoginTD[32], 1);

	gLoginTD[33] = TextDrawCreate(328.067779, 216.017120, "please_choose_a_gender!");
	TextDrawLetterSize(gLoginTD[33], 0.160833, 1.371855);
	TextDrawTextSize(gLoginTD[33], -11.000000, 0.000000);
	TextDrawAlignment(gLoginTD[33], 1);
	TextDrawColor(gLoginTD[33], -13958913);
	TextDrawSetShadow(gLoginTD[33], 0);
	TextDrawBackgroundColor(gLoginTD[33], 255);
	TextDrawFont(gLoginTD[33], 1);
	TextDrawSetProportional(gLoginTD[33], 0);
	//TEXTDRAW LOGIN SYSTEM END//======================================================================================================================================================================
	return 1;
}
public LoadPlayerTextDraws(playerid){
	// TEXTDRAW LOGIN SYSTEM =================================================================================================
	pLoginTD[playerid][0] = CreatePlayerTextDraw(playerid, 303.333312, 94.140342, "LD_CHAT:thumbup");//password
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][0], 13.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][0], 0);

	pLoginTD[playerid][1] = CreatePlayerTextDraw(playerid, 303.333312, 123.709266, "LD_CHAT:thumbup");//confirm_password
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][1], 13.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][1], 0);

	pLoginTD[playerid][2] = CreatePlayerTextDraw(playerid, 303.333312, 153.709259, "LD_CHAT:thumbup");//email
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][2], 13.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][2], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][2], 0);

	pLoginTD[playerid][3] = CreatePlayerTextDraw(playerid, 302.916656, 184.709259, "LD_CHAT:thumbup");//age
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
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][4], 0);
	PlayerTextDrawBoxColor(playerid, pLoginTD[playerid][4], 0);
	PlayerTextDrawUseBox(playerid, pLoginTD[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][4], 0);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][4], 5);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][4], 0);
	PlayerTextDrawSetPreviewModel(playerid, pLoginTD[playerid][4], CivilSkins[0][0]);
	PlayerTextDrawSetPreviewRot(playerid, pLoginTD[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);

	pLoginTD[playerid][5] = CreatePlayerTextDraw(playerid, 302.916656, 215.009140, "LD_CHAT:thumbup");//gender
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][5], 13.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][5], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][5], 0);
	
	pLoginTD[playerid][6] = CreatePlayerTextDraw(playerid, 325.917236, 93.555480, "your_password_is_too_long(max_25_characters)");
	PlayerTextDrawLetterSize(playerid, pLoginTD[playerid][6], 0.127082, 1.537779);
	PlayerTextDrawTextSize(playerid, pLoginTD[playerid][6], -7.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, pLoginTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, pLoginTD[playerid][6], -13958913);
	PlayerTextDrawSetShadow(playerid, pLoginTD[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, pLoginTD[playerid][6], 255);
	PlayerTextDrawFont(playerid, pLoginTD[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, pLoginTD[playerid][6], 0);
	// TEXTDRAW LOGIN SYSTEM END =============================================================================================
	return 1;
}
public TutorialTextDrawLoad(playerid, IntroStep, bool:load)
{
	if(load == true)
	{
		switch(IntroStep)
		{
			case 1:
			{
				//part 1+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				IntroTD1[playerid][0] = CreatePlayerTextDraw(playerid, -8.333323, -21.555534, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD1[playerid][0], 0.000000, 54.916671);
				PlayerTextDrawTextSize(playerid, IntroTD1[playerid][0], 982.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD1[playerid][0], 1);
				PlayerTextDrawColor(playerid, IntroTD1[playerid][0], -1);
				PlayerTextDrawUseBox(playerid, IntroTD1[playerid][0], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD1[playerid][0], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD1[playerid][0], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD1[playerid][0], 255);
				PlayerTextDrawFont(playerid, IntroTD1[playerid][0], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD1[playerid][0], 1);

				IntroTD1[playerid][1] = CreatePlayerTextDraw(playerid, 290.000000, 190.000000, "Elyps_RPG~n~");
				PlayerTextDrawLetterSize(playerid, IntroTD1[playerid][1], 0.400000, 1.600000);
				PlayerTextDrawAlignment(playerid, IntroTD1[playerid][1], 1);
				PlayerTextDrawColor(playerid, IntroTD1[playerid][1], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD1[playerid][1], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD1[playerid][1], 255);
				PlayerTextDrawFont(playerid, IntroTD1[playerid][1], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD1[playerid][1], 1);

				IntroTD1[playerid][2] = CreatePlayerTextDraw(playerid, 289.166656, 208.148132, "Prezinta...");
				PlayerTextDrawLetterSize(playerid, IntroTD1[playerid][2], 0.400000, 1.600000);
				PlayerTextDrawTextSize(playerid, IntroTD1[playerid][2], 27.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD1[playerid][2], 1);
				PlayerTextDrawColor(playerid, IntroTD1[playerid][2], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD1[playerid][2], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD1[playerid][2], 255);
				PlayerTextDrawFont(playerid, IntroTD1[playerid][2], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD1[playerid][2], 1);	
				//end of part 1++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			}
			case 2:
			{
				//part 2+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				IntroTD2[playerid][0] = CreatePlayerTextDraw(playerid, 173.783416, 125.185226, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][0], 0.329997, 21.371103);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][0], -89.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][0], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][0], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][0], 130);
				PlayerTextDrawSetOutline(playerid, IntroTD2[playerid][0], -1);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][0], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][0], 3);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][0], 0);

				IntroTD2[playerid][1] = CreatePlayerTextDraw(playerid, 246.716827, 142.666732, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][1], 0.287916, 21.174043);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][1], -89.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][1], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][1], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][1], 0);
				PlayerTextDrawSetOutline(playerid, IntroTD2[playerid][1], 1);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][1], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][1], 3);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][1], 0);

				IntroTD2[playerid][2] = CreatePlayerTextDraw(playerid, 143.333206, 190.518646, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][2], 7.847064, -3.502243);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][2], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][2], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][2], -1);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][2], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][2], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][2], 1);

				IntroTD2[playerid][3] = CreatePlayerTextDraw(playerid, 138.333267, 346.463134, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][3], 7.847064, -3.507430);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][3], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][3], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][3], -1);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][3], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][3], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][3], 1);

				IntroTD2[playerid][4] = CreatePlayerTextDraw(playerid, 260.833465, 69.185180, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][4], 1.850414, 31.279989);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][4], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][4], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][4], -6);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][4], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][4], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][4], 1);
				PlayerTextDrawSetSelectable(playerid, IntroTD2[playerid][4], true);

				IntroTD2[playerid][5] = CreatePlayerTextDraw(playerid, 260.833465, 69.185180, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][5], 1.850414, 31.279989);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][5], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][5], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][5], -6);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][5], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][5], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][5], 1);
				PlayerTextDrawSetSelectable(playerid, IntroTD2[playerid][5], true);

				IntroTD2[playerid][6] = CreatePlayerTextDraw(playerid, 364.365844, 69.185180, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][6], 1.850414, 31.279989);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][6], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][6], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][6], -6);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][6], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][6], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][6], 1);
				PlayerTextDrawSetSelectable(playerid, IntroTD2[playerid][6], true);

				IntroTD2[playerid][7] = CreatePlayerTextDraw(playerid, 363.532531, 69.185180, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][7], 1.850414, 31.279989);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][7], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][7], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][7], -6);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][7], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][7], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][7], 1);
				PlayerTextDrawSetSelectable(playerid, IntroTD2[playerid][7], true);

				IntroTD2[playerid][8] = CreatePlayerTextDraw(playerid, 158.333358, 130.888885, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][8], 21.062900, -1.402222);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][8], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][8], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][8], 0);
				PlayerTextDrawSetOutline(playerid, IntroTD2[playerid][8], 252);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][8], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][8], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][8], 1);

				IntroTD2[playerid][9] = CreatePlayerTextDraw(playerid, 158.333358, 361.889556, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][9], 21.062900, -1.402222);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][9], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][9], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][9], 0);
				PlayerTextDrawSetOutline(playerid, IntroTD2[playerid][9], 251);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][9], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][9], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][9], 1);

				IntroTD2[playerid][10] = CreatePlayerTextDraw(playerid, -1.999976, -1.333348, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][10], 0.000000, 51.920978);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][10], 174.829193, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][10], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][10], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][10], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][10], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][10], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][10], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][10], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][10], 1);

				IntroTD2[playerid][11] = CreatePlayerTextDraw(playerid, 177.500030, -94.148208, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][11], 0.000000, 24.372642);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][11], 717.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][11], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][11], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][11], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][11], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][11], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][11], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][11], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][11], 1);

				IntroTD2[playerid][12] = CreatePlayerTextDraw(playerid, 177.616638, 128.588745, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][12], 0.000000, 4.168979);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][12], 272.409851, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][12], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][12], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][12], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][12], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][12], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][12], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][12], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][12], 1);

				IntroTD2[playerid][13] = CreatePlayerTextDraw(playerid, 202.032516, 169.551712, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][13], 0.000000, 0.112975);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][13], 278.604064, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][13], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][13], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][13], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][13], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][13], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][13], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][13], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][13], 1);

				IntroTD2[playerid][14] = CreatePlayerTextDraw(playerid, 221.132537, 174.151718, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][14], 0.000000, 0.120641);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][14], 268.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][14], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][14], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][14], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][14], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][14], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][14], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][14], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][14], 1);

				IntroTD2[playerid][15] = CreatePlayerTextDraw(playerid, 238.249404, 178.620422, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][15], 0.000000, -0.007021);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][15], 274.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][15], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][15], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][15], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][15], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][15], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][15], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][15], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][15], 1);

				IntroTD2[playerid][16] = CreatePlayerTextDraw(playerid, 249.032653, 181.989089, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][16], 0.000000, 16.787012);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][16], 270.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][16], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][16], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][16], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][16], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][16], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][16], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][16], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][16], 1);

				IntroTD2[playerid][17] = CreatePlayerTextDraw(playerid, 177.532501, 325.450164, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][17], 0.000000, 16.872983);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][17], 197.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][17], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][17], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][17], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][17], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][17], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][17], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][17], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][17], 1);

				IntroTD2[playerid][18] = CreatePlayerTextDraw(playerid, 199.382553, 330.635375, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][18], 0.000000, 21.855611);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][18], 219.110107, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][18], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][18], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][18], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][18], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][18], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][18], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][18], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][18], 1);

				IntroTD2[playerid][19] = CreatePlayerTextDraw(playerid, 221.765731, 336.320434, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][19], 0.000000, 22.341608);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][19], 269.439758, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][19], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][19], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][19], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][19], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][19], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][19], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][19], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][19], 1);

				IntroTD2[playerid][20] = CreatePlayerTextDraw(playerid, 272.182373, 361.727813, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][20], 0.000000, 24.716611);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][20], 707.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][20], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][20], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][20], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][20], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][20], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][20], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][20], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][20], 0);

				IntroTD2[playerid][21] = CreatePlayerTextDraw(playerid, 393.266967, 401.555999, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][21], 0.962082, -26.223707);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][21], -129.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][21], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][21], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][21], 130);
				PlayerTextDrawSetOutline(playerid, IntroTD2[playerid][21], -1);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][21], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][21], 3);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][21], 0);

				IntroTD2[playerid][22] = CreatePlayerTextDraw(playerid, 474.100341, 377.185577, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][22], 0.962082, -26.223707);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][22], -129.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][22], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][22], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][22], 130);
				PlayerTextDrawSetOutline(playerid, IntroTD2[playerid][22], -1);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][22], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][22], 3);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][22], 0);

				IntroTD2[playerid][23] = CreatePlayerTextDraw(playerid, 349.166442, 312.348144, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][23], 13.162495, 5.810340);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][23], -79.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][23], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][23], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][23], -1);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][23], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][23], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][23], 1);

				IntroTD2[playerid][24] = CreatePlayerTextDraw(playerid, 347.916809, 106.496223, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][24], 10.572904, 8.055529);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][24], -79.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][24], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][24], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][24], -1);
				PlayerTextDrawSetOutline(playerid, IntroTD2[playerid][24], -5);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][24], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][24], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][24], 1);

				IntroTD2[playerid][25] = CreatePlayerTextDraw(playerid, 483.066986, 128.359222, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][25], 0.000000, 25.587593);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][25], 678.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][25], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][25], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][25], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][25], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][25], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][25], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][25], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][25], 1);

				IntroTD2[playerid][26] = CreatePlayerTextDraw(playerid, 388.483703, 129.914840, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][26], 0.000000, 2.339261);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][26], 414.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][26], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][26], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][26], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][26], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][26], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][26], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][26], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][26], 1);

				IntroTD2[playerid][27] = CreatePlayerTextDraw(playerid, 416.400360, 123.174095, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][27], 0.000000, 2.255927);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][27], 439.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][27], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][27], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][27], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][27], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][27], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][27], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][27], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][27], 1);

				IntroTD2[playerid][28] = CreatePlayerTextDraw(playerid, 441.400360, 116.951873, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][28], 0.000000, 2.297593);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][28], 463.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][28], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][28], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][28], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][28], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][28], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][28], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][28], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][28], 1);

				IntroTD2[playerid][29] = CreatePlayerTextDraw(playerid, 460.150573, 110.211112, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][29], 0.000000, 2.489259);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][29], 486.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][29], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][29], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][29], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][29], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][29], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][29], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][29], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][29], 1);

				IntroTD2[playerid][30] = CreatePlayerTextDraw(playerid, 480.150604, 129.396301, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][30], 0.000000, 2.405925);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][30], 507.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][30], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][30], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][30], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][30], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][30], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][30], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][30], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][30], 1);

				IntroTD2[playerid][31] = CreatePlayerTextDraw(playerid, 375.567352, 354.951751, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][31], 0.000000, 0.387591);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][31], 480.499969, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][31], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][31], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][31], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][31], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][31], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][31], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][31], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][31], 1);

				IntroTD2[playerid][32] = CreatePlayerTextDraw(playerid, 431.817382, 346.061553, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][32], 0.000000, 0.627592);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][32], 480.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][32], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][32], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][32], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][32], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][32], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][32], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][32], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][32], 1);

				IntroTD2[playerid][33] = CreatePlayerTextDraw(playerid, 458.484008, 340.876281, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][33], 0.000000, 1.502591);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][33], 484.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][33], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][33], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][33], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][33], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][33], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][33], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][33], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][33], 1);

				IntroTD2[playerid][34] = CreatePlayerTextDraw(playerid, 387.650665, 154.209701, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][34], 0.000000, 25.585922);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][34], 400.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][34], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][34], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][34], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][34], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][34], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][34], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][34], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][34], 1);

				IntroTD2[playerid][35] = CreatePlayerTextDraw(playerid, 376.400665, 149.024459, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][35], 0.000000, 25.585922);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][35], 389.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][35], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][35], -63);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][35], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][35], 142);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][35], 3);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][35], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][35], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][35], 1);

				IntroTD2[playerid][36] = CreatePlayerTextDraw(playerid, 142.083190, 153.703750, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][36], 0.000000, 21.166667);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][36], 255.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][36], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][36], -1);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][36], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][36], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][36], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][36], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][36], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][36], 1);

				IntroTD2[playerid][37] = CreatePlayerTextDraw(playerid, 264.583099, 118.963027, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][37], 0.000000, 25.500001);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][37], 380.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][37], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][37], -1);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][37], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][37], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][37], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][37], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][37], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][37], 1);

				IntroTD2[playerid][38] = CreatePlayerTextDraw(playerid, 390.833526, 128.814895, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][38], 0.000000, 25.500001);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][38], 511.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][38], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][38], -1);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][38], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][38], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][38], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][38], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][38], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][38], 1);

				IntroTD2[playerid][39] = CreatePlayerTextDraw(playerid, 156.666534, 339.333251, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][39], 0.000000, 6.375001);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][39], 249.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][39], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][39], -1);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][39], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][39], 41);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][39], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][39], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][39], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][39], 1);

				IntroTD2[playerid][40] = CreatePlayerTextDraw(playerid, 251.666488, 353.851776, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][40], 0.000000, 7.750000);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][40], 541.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][40], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][40], -1);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][40], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][40], 41);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][40], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][40], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][40], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][40], 1);

				IntroTD2[playerid][41] = CreatePlayerTextDraw(playerid, 126.666397, 335.185119, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][41], 0.000000, 3.416666);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][41], 218.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][41], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][41], -1);
				PlayerTextDrawUseBox(playerid, IntroTD2[playerid][41], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][41], 41);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][41], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][41], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][41], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][41], 1);
				
				IntroTD2[playerid][42] = CreatePlayerTextDraw(playerid, 91.666709, 199.851730, "Un_server_RPG~n~Unic_facut_de_la~n~zero_pentru_tine");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][42], 0.400000, 2.263701);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][42], -5.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][42], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][42], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][42], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][42], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][42], 0);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][42], 1);

				IntroTD2[playerid][43] = CreatePlayerTextDraw(playerid, 245.000198, 103.925781, "Sisteme_unice_si_captivante");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][43], 0.400000, 2.263701);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][43], -5.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][43], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][43], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][43], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][43], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][43], 0);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][43], 1);

				IntroTD2[playerid][44] = CreatePlayerTextDraw(playerid, 485.833496, 178.592437, "O_comunitate_in_care_~n~sa_te_simti_ca_acasa.~n~Adminii_sunt_atenti_~n~sa_elimine_comportamentul~n~toxic_de_pe_server.");
				PlayerTextDrawLetterSize(playerid, IntroTD2[playerid][44], 0.400000, 2.263701);
				PlayerTextDrawTextSize(playerid, IntroTD2[playerid][44], -5.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD2[playerid][44], 1);
				PlayerTextDrawColor(playerid, IntroTD2[playerid][44], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD2[playerid][44], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD2[playerid][44], 255);
				PlayerTextDrawFont(playerid, IntroTD2[playerid][44], 0);
				PlayerTextDrawSetProportional(playerid, IntroTD2[playerid][44], 1);
				//end of part 2++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			}
			case 3:
			{
				//part 3+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				IntroTD3[playerid][0] = CreatePlayerTextDraw(playerid, 114.583259, 7.481513, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][0], 3.101665, 32.197788);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][0], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][0], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][0], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][0], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][0], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][0], 1);

				IntroTD3[playerid][1] = CreatePlayerTextDraw(playerid, 205.833297, 16.814832, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][1], 3.101665, 32.197788);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][1], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][1], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][1], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][1], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][1], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][1], 1);

				IntroTD3[playerid][2] = CreatePlayerTextDraw(playerid, 102.499938, 84.740768, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][2], 12.571245, -2.112590);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][2], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][2], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][2], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][2], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][2], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][2], 1);

				IntroTD3[playerid][3] = CreatePlayerTextDraw(playerid, 69.999946, 318.592651, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][3], 12.571245, -2.112590);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][3], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][3], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][3], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][3], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][3], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][3], 1);

				IntroTD3[playerid][4] = CreatePlayerTextDraw(playerid, 300.000061, 17.333353, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][4], -1.853747, 29.952600);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][4], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][4], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][4], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][4], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][4], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][4], 1);

				IntroTD3[playerid][5] = CreatePlayerTextDraw(playerid, 387.083374, 12.148161, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][5], -1.853747, 29.952600);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][5], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][5], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][5], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][5], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][5], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][5], 1);

				IntroTD3[playerid][6] = CreatePlayerTextDraw(playerid, 217.499816, 97.703727, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][6], 16.107923, -2.641479);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][6], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][6], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][6], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][6], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][6], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][6], 0);

				IntroTD3[playerid][7] = CreatePlayerTextDraw(playerid, 241.666549, 298.888977, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][7], 16.107923, -2.641479);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][7], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][7], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][7], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][7], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][7], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][7], 0);

				IntroTD3[playerid][8] = CreatePlayerTextDraw(playerid, 403.750091, 347.629486, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][8], 3.246668, -29.298505);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][8], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][8], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][8], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][8], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][8], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][8], 1);

				IntroTD3[playerid][9] = CreatePlayerTextDraw(playerid, -8.333456, -99.851898, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][9], 0.000000, 94.624984);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][9], 133.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][9], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][9], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][9], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][9], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][9], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][9], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][9], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][9], 1);

				IntroTD3[playerid][10] = CreatePlayerTextDraw(playerid, 135.416534, 1.259153, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][10], 0.000000, 17.624967);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][10], 146.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][10], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][10], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][10], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][10], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][10], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][10], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][10], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][10], 1);

				IntroTD3[playerid][11] = CreatePlayerTextDraw(playerid, 148.333129, -75.481590, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][11], 0.000000, 16.208309);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][11], 644.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][11], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][11], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][11], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][11], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][11], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][11], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][11], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][11], 1);

				IntroTD3[playerid][12] = CreatePlayerTextDraw(playerid, 224.583129, 72.814689, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][12], 0.000000, 0.583307);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][12], 672.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][12], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][12], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][12], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][12], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][12], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][12], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][12], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][12], 1);

				IntroTD3[playerid][13] = CreatePlayerTextDraw(playerid, 343.750152, 81.629531, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][13], 0.000000, 0.624975);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][13], 667.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][13], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][13], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][13], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][13], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][13], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][13], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][13], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][13], 1);

				IntroTD3[playerid][14] = CreatePlayerTextDraw(playerid, 428.750000, 90.444351, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][14], 0.000000, 16.916645);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][14], 911.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][14], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][14], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][14], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][14], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][14], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][14], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][14], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][14], 1);

				IntroTD3[playerid][15] = CreatePlayerTextDraw(playerid, 433.750000, 245.999862, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][15], 0.000000, 29.874977);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][15], 915.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][15], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][15], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][15], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][15], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][15], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][15], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][15], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][15], 1);

				IntroTD3[playerid][16] = CreatePlayerTextDraw(playerid, 135.416748, 313.407196, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][16], 0.000000, 37.291656);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][16], 432.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][16], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][16], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][16], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][16], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][16], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][16], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][16], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][16], 1);

				IntroTD3[playerid][17] = CreatePlayerTextDraw(playerid, 235.416793, 81.629409, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][17], 0.000000, 25.625022);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][17], 283.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][17], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][17], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][17], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][17], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][17], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][17], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][17], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][17], 1);

				IntroTD3[playerid][18] = CreatePlayerTextDraw(playerid, 223.333450, 228.888702, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][18], 0.000000, 9.875020);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][18], 243.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][18], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][18], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][18], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][18], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][18], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][18], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][18], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][18], 1);

				IntroTD3[playerid][19] = CreatePlayerTextDraw(playerid, 276.666809, 238.222045, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][19], 0.000000, 9.166687);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][19], 293.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][19], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][19], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][19], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][19], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][19], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][19], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][19], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][19], 1);

				IntroTD3[playerid][20] = CreatePlayerTextDraw(playerid, 291.666870, 290.073913, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][20], 0.000000, 3.500024);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][20], 435.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][20], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][20], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][20], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][20], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][20], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][20], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][20], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][20], 1);

				IntroTD3[playerid][21] = CreatePlayerTextDraw(playerid, 290.000152, 280.221923, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][21], 0.000000, 2.750024);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][21], 366.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][21], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][21], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][21], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][21], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][21], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][21], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][21], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][21], 1);

				IntroTD3[playerid][22] = CreatePlayerTextDraw(playerid, 132.916824, 307.185180, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][22], 0.000000, 1.083353);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][22], 166.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][22], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][22], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][22], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][22], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][22], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][22], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][22], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][22], 1);

				IntroTD3[playerid][23] = CreatePlayerTextDraw(playerid, 165.416809, 309.777679, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][23], 0.000000, 1.083353);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][23], 200.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][23], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][23], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][23], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][23], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][23], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][23], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][23], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][23], 1);

				IntroTD3[playerid][24] = CreatePlayerTextDraw(playerid, 232.083435, 159.925765, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][24], 0.000000, 9.208353);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][24], 287.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][24], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][24], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][24], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][24], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][24], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][24], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][24], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][24], 1);

				IntroTD3[playerid][25] = CreatePlayerTextDraw(playerid, 422.500061, 81.110977, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][25], 0.000000, 10.958353);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][25], 433.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][25], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][25], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][25], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][25], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][25], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][25], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][25], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][25], 1);

				IntroTD3[playerid][26] = CreatePlayerTextDraw(playerid, 192.083389, 68.666557, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][26], 0.000000, 0.500024);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][26], 247.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][26], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][26], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][26], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][26], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][26], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][26], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][26], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][26], 1);

				IntroTD3[playerid][27] = CreatePlayerTextDraw(playerid, 414.583587, 87.333251, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][27], 0.000000, 2.666690);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][27], 424.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][27], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][27], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][27], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][27], 147);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][27], -73);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][27], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][27], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][27], 1);

				IntroTD3[playerid][28] = CreatePlayerTextDraw(playerid, 403.750091, 347.629486, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][28], 3.246668, -29.298505);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][28], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][28], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][28], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][28], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][28], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][28], 1);

				IntroTD3[playerid][29] = CreatePlayerTextDraw(playerid, 114.583259, 7.481513, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][29], 3.101665, 32.197788);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][29], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][29], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][29], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][29], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][29], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][29], 1);

				IntroTD3[playerid][30] = CreatePlayerTextDraw(playerid, 205.833297, 16.814832, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][30], 3.101665, 32.197788);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][30], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][30], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][30], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][30], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][30], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][30], 1);

				IntroTD3[playerid][31] = CreatePlayerTextDraw(playerid, 102.499938, 84.740768, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][31], 12.571245, -2.112590);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][31], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][31], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][31], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][31], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][31], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][31], 1);

				IntroTD3[playerid][32] = CreatePlayerTextDraw(playerid, 300.000061, 17.333353, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][32], -1.853747, 29.952600);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][32], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][32], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][32], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][32], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][32], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][32], 1);

				IntroTD3[playerid][33] = CreatePlayerTextDraw(playerid, 69.999946, 318.592651, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][33], 12.571245, -2.112590);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][33], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][33], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][33], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][33], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][33], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][33], 1);

				IntroTD3[playerid][34] = CreatePlayerTextDraw(playerid, 387.083374, 12.148161, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][34], -1.853747, 29.952600);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][34], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][34], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][34], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][34], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][34], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][34], 1);

				IntroTD3[playerid][35] = CreatePlayerTextDraw(playerid, 217.499816, 97.703727, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][35], 16.107923, -2.641479);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][35], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][35], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][35], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][35], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][35], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][35], 0);

				IntroTD3[playerid][36] = CreatePlayerTextDraw(playerid, 241.666549, 298.888977, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][36], 16.107923, -2.641479);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][36], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][36], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][36], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][36], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][36], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][36], 0);

				IntroTD3[playerid][37] = CreatePlayerTextDraw(playerid, 403.750091, 347.629486, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][37], 3.246668, -29.298505);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][37], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][37], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][37], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][37], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][37], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][37], 1);

				IntroTD3[playerid][38] = CreatePlayerTextDraw(playerid, 231.250015, 7.037048, "~r~Un_server_romanesc~n~~y~unde_sa_te_relaxezi_si~n~~b~sa-ti_creezi_propria_cariera_virtuala");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][38], 0.400000, 1.600000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][38], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][38], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][38], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][38], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][38], 0);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][38], 1);

				IntroTD3[playerid][39] = CreatePlayerTextDraw(playerid, 473.583251, 36.029685, "Factiuni");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][39], 0.701250, 2.875554);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][39], 178.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][39], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][39], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][39], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][39], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][39], 0);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][39], 1);

				IntroTD3[playerid][40] = CreatePlayerTextDraw(playerid, 438.750091, 73.851844, "Departamente:");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][40], 0.177916, 2.113332);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][40], -47.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][40], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][40], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][40], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][40], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][40], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][40], 1);

				IntroTD3[playerid][41] = CreatePlayerTextDraw(playerid, 479.166625, 95.111099, "]LSPD~n~]LVPD~n~]F.B.I~n~]National_Guard");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][41], 0.318333, 1.657036);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][41], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][41], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][41], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][41], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][41], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][41], 1);

				IntroTD3[playerid][42] = CreatePlayerTextDraw(playerid, 438.750091, 158.751617, "Factiuni_Pasnice:");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][42], 0.177916, 2.113332);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][42], -47.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][42], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][42], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][42], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][42], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][42], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][42], 1);

				IntroTD3[playerid][43] = CreatePlayerTextDraw(playerid, 479.166625, 179.711242, "]Paramedic~n~]News_Reporters~n~]School_Instructors~n~]Uber");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][43], 0.318333, 1.657036);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][43], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][43], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][43], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][43], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][43], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][43], 1);

				IntroTD3[playerid][44] = CreatePlayerTextDraw(playerid, 445.950042, 239.751754, "MafiI:");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][44], 0.177916, 2.113332);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][44], -47.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][44], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][44], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][44], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][44], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][44], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][44], 1);

				IntroTD3[playerid][45] = CreatePlayerTextDraw(playerid, 479.166625, 262.511322, "]Grove_Street~n~]Ballas~n~]Los_Vagos~n~]The_Russian_Mafia");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][45], 0.318333, 1.657036);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][45], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][45], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][45], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][45], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][45], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][45], 1);

				IntroTD3[playerid][46] = CreatePlayerTextDraw(playerid, 23.584398, 133.229782, "~y~~w~Joburi");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][46], 0.701250, 2.875554);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][46], 178.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][46], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][46], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][46], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][46], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][46], 0);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][46], 1);

				IntroTD3[playerid][47] = CreatePlayerTextDraw(playerid, 5.416735, 178.700042, "LEGALE:");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][47], 0.177916, 2.113332);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][47], -47.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][47], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][47], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][47], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][47], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][47], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][47], 1);

				IntroTD3[playerid][48] = CreatePlayerTextDraw(playerid, 21.249996, 204.296478, "|Detectiv~n~|Avocat~n~|Sofer_pe_tir~n~|Fermier~n~|Gunoier~n~|Miner");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][48], 0.318333, 1.657036);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][48], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][48], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][48], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][48], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][48], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][48], 1);

				IntroTD3[playerid][49] = CreatePlayerTextDraw(playerid, 5.833402, 298.536926, "ILEGALE:");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][49], 0.177916, 2.113332);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][49], -47.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][49], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][49], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][49], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][49], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][49], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][49], 1);

				IntroTD3[playerid][50] = CreatePlayerTextDraw(playerid, 20.549999, 325.577453, "|Hot_de_masini~n~|Hot_de_buzunare~n~|Escorta~n~|Dealer_de_droguri~n~|Dealer_de_Arme~n~|Cultivator_de_Marijuana");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][50], 0.318333, 1.657036);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][50], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][50], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][50], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][50], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][50], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][50], 1);

				IntroTD3[playerid][51] = CreatePlayerTextDraw(playerid, 117.499938, 63.999996, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][51], 0.000000, 28.249992);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][51], 248.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][51], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][51], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][51], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][51], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][51], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][51], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][51], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][51], 1);

				IntroTD3[playerid][52] = CreatePlayerTextDraw(playerid, 370.833129, 82.148124, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][52], 0.000000, 12.708327);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][52], 434.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][52], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][52], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][52], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][52], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][52], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][52], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][52], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][52], 1);

				IntroTD3[playerid][53] = CreatePlayerTextDraw(playerid, 378.749847, 177.555526, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][53], 0.000000, 12.666660);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][53], 444.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][53], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][53], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][53], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][53], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][53], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][53], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][53], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][53], 1);

				IntroTD3[playerid][54] = CreatePlayerTextDraw(playerid, 261.249877, 72.296272, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD3[playerid][54], 0.000000, 25.083322);
				PlayerTextDrawTextSize(playerid, IntroTD3[playerid][54], 376.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD3[playerid][54], 1);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][54], -1);
				PlayerTextDrawUseBox(playerid, IntroTD3[playerid][54], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][54], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD3[playerid][54], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD3[playerid][54], 255);
				PlayerTextDrawFont(playerid, IntroTD3[playerid][54], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD3[playerid][54], 1);
				//end of part 3++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			}
			case 4:{
				IntroTD4[playerid][0] = CreatePlayerTextDraw(playerid, 91.250038, 58.814792, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][0], 3.567498, 35.464443);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][0], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][0], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][0], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][0], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][0], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][0], 1);

				IntroTD4[playerid][1] = CreatePlayerTextDraw(playerid, 91.250038, 58.814792, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][1], 3.567498, 35.464443);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][1], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][1], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][1], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][1], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][1], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][1], 1);

				IntroTD4[playerid][2] = CreatePlayerTextDraw(playerid, 255.416793, 57.777786, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][2], 3.673332, 37.097785);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][2], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][2], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][2], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][2], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][2], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][2], 1);

				IntroTD4[playerid][3] = CreatePlayerTextDraw(playerid, 255.416793, 57.777786, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][3], 3.673332, 37.097785);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][3], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][3], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][3], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][3], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][3], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][3], 1);

				IntroTD4[playerid][4] = CreatePlayerTextDraw(playerid, 57.916698, 139.185272, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][4], 28.156269, -2.216300);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][4], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][4], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][4], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][4], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][4], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][4], 1);

				IntroTD4[playerid][5] = CreatePlayerTextDraw(playerid, 57.916698, 139.185272, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][5], 28.156269, -2.216300);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][5], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][5], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][5], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][5], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][5], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][5], 1);

				IntroTD4[playerid][6] = CreatePlayerTextDraw(playerid, 57.916698, 401.986450, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][6], 28.973329, -2.117782);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][6], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][6], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][6], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][6], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][6], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][6], 1);

				IntroTD4[playerid][7] = CreatePlayerTextDraw(playerid, 57.916698, 401.986450, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][7], 28.973329, -2.117782);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][7], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][7], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][7], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][7], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][7], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][7], 1);

				IntroTD4[playerid][8] = CreatePlayerTextDraw(playerid, 383.333374, 447.703826, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][8], 1.042083, -34.634063);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][8], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][8], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][8], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][8], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][8], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][8], 1);

				IntroTD4[playerid][9] = CreatePlayerTextDraw(playerid, 383.333374, 447.703826, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][9], 1.042083, -34.634063);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][9], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][9], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][9], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][9], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][9], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][9], 1);

				IntroTD4[playerid][10] = CreatePlayerTextDraw(playerid, 385.833465, 437.851959, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][10], 0.932501, -21.738510);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][10], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][10], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][10], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][10], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][10], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][10], 1);

				IntroTD4[playerid][11] = CreatePlayerTextDraw(playerid, 385.833465, 437.851959, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][11], 0.932501, -21.738510);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][11], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][11], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][11], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][11], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][11], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][11], 1);

				IntroTD4[playerid][12] = CreatePlayerTextDraw(playerid, 587.083007, 122.429618, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][12], -17.099590, 2.419259);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][12], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][12], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][12], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][12], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][12], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][12], 1);

				IntroTD4[playerid][13] = CreatePlayerTextDraw(playerid, 587.083007, 387.630615, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][13], -17.099590, 2.419259);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][13], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][13], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][13], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][13], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][13], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][13], 1);

				IntroTD4[playerid][14] = CreatePlayerTextDraw(playerid, 587.083007, 387.630615, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][14], -17.099590, 2.419259);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][14], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][14], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][14], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][14], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][14], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][14], 1);

				IntroTD4[playerid][15] = CreatePlayerTextDraw(playerid, 587.083007, 122.616752, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][15], -17.099590, 2.419259);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][15], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][15], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][15], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][15], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][15], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][15], 1);

				IntroTD4[playerid][16] = CreatePlayerTextDraw(playerid, 530.000061, 420.740539, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][16], 3.003746, -29.464427);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][16], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][16], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][16], 0);
				PlayerTextDrawSetOutline(playerid, IntroTD4[playerid][16], -13);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][16], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][16], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][16], 1);

				IntroTD4[playerid][17] = CreatePlayerTextDraw(playerid, 533.750183, 437.333282, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][17], 1.532915, -13.810365);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][17], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][17], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][17], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][17], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][17], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][17], 1);

				IntroTD4[playerid][18] = CreatePlayerTextDraw(playerid, 533.750183, 437.333282, "/");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][18], 1.532915, -13.810365);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][18], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][18], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][18], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][18], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][18], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][18], 1);

				IntroTD4[playerid][19] = CreatePlayerTextDraw(playerid, -9.166665, -18.444427, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][19], 0.000000, 54.083339);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][19], 112.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][19], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][19], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][19], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][19], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][19], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][19], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][19], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][19], 1);

				IntroTD4[playerid][20] = CreatePlayerTextDraw(playerid, 114.166648, -19.999984, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][20], 0.000000, 25.833335);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][20], 131.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][20], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][20], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][20], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][20], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][20], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][20], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][20], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][20], 1);

				IntroTD4[playerid][21] = CreatePlayerTextDraw(playerid, 132.916702, -4.444458, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][21], 0.000000, 13.958337);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][21], 744.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][21], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][21], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][21], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][21], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][21], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][21], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][21], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][21], 1);

				IntroTD4[playerid][22] = CreatePlayerTextDraw(playerid, 285.416717, 121.036964, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][22], 0.000000, 1.333341);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][22], 697.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][22], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][22], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][22], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][22], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][22], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][22], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][22], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][22], 1);

				IntroTD4[playerid][23] = CreatePlayerTextDraw(playerid, 495.416656, 136.073989, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][23], 0.000000, 0.791674);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][23], 683.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][23], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][23], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][23], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][23], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][23], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][23], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][23], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][23], 1);

				IntroTD4[playerid][24] = CreatePlayerTextDraw(playerid, 552.916503, 145.925796, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][24], 0.000000, 35.500015);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][24], 708.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][24], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][24], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][24], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][24], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][24], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][24], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][24], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][24], 1);

				IntroTD4[playerid][25] = CreatePlayerTextDraw(playerid, 114.633071, 385.494140, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][25], 0.000000, 8.958345);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][25], 277.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][25], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][25], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][25], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][25], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][25], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][25], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][25], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][25], 1);

				IntroTD4[playerid][26] = CreatePlayerTextDraw(playerid, 278.383026, 395.864501, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][26], 0.000000, 10.583345);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][26], 443.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][26], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][26], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][26], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][26], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][26], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][26], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][26], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][26], 1);

				IntroTD4[playerid][27] = CreatePlayerTextDraw(playerid, 442.549713, 404.679199, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][27], 0.000000, 15.041687);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][27], 516.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][27], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][27], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][27], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][27], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][27], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][27], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][27], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][27], 1);

				IntroTD4[playerid][28] = CreatePlayerTextDraw(playerid, 511.716400, 409.345916, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][28], 0.000000, 15.041687);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][28], 582.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][28], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][28], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][28], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][28], 174);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][28], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][28], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][28], 2);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][28], 1);

				IntroTD4[playerid][29] = CreatePlayerTextDraw(playerid, 5.416648, 155.777709, "Sisteme_unice_de_war-uri.~n~War-urile_se_executa~n~numai_intre_orele_19:00~n~si_20:35.");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][29], 0.400000, 1.600000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][29], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][29], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][29], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][29], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][29], 0);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][29], 1);

				IntroTD4[playerid][30] = CreatePlayerTextDraw(playerid, 523.333312, 122.073974, "Sistem_de_dealership_unic.~n~Momentan_exista_o_locatie~n~unde_poti_cumpara_masini~n~noi._");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][30], 0.400000, 1.600000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][30], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][30], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][30], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][30], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][30], 0);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][30], 1);

				IntroTD4[playerid][31] = CreatePlayerTextDraw(playerid, 549.583374, 317.555236, "De_asemenea_pe_server~n~exista_si_o_piata_auto~n~unde_iti_poti_vinde_masinile~n~personale.");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][31], 0.331666, 1.434073);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][31], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][31], -1);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][31], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][31], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][31], 0);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][31], 1);

				IntroTD4[playerid][32] = CreatePlayerTextDraw(playerid, 285.116790, 111.185165, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][32], 0.000000, 33.749980);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][32], 406.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][32], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][32], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][32], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][32], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][32], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][32], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][32], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][32], 1);

				IntroTD4[playerid][33] = CreatePlayerTextDraw(playerid, 267.616790, 326.888854, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][33], 0.000000, 7.166643);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][33], 290.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][33], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][33], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][33], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][33], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][33], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][33], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][33], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][33], 1);

				IntroTD4[playerid][34] = CreatePlayerTextDraw(playerid, 112.200080, 115.851821, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][34], 0.000000, 32.166637);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][34], 282.309387, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][34], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][34], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][34], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][34], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][34], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][34], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][34], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][34], 1);

				IntroTD4[playerid][35] = CreatePlayerTextDraw(playerid, 407.616790, 116.370376, "box");
				PlayerTextDrawLetterSize(playerid, IntroTD4[playerid][35], 0.000000, 32.166637);
				PlayerTextDrawTextSize(playerid, IntroTD4[playerid][35], 580.000000, 0.000000);
				PlayerTextDrawAlignment(playerid, IntroTD4[playerid][35], 1);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][35], -1);
				PlayerTextDrawUseBox(playerid, IntroTD4[playerid][35], 1);
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][35], 255);
				PlayerTextDrawSetShadow(playerid, IntroTD4[playerid][35], 0);
				PlayerTextDrawBackgroundColor(playerid, IntroTD4[playerid][35], 255);
				PlayerTextDrawFont(playerid, IntroTD4[playerid][35], 1);
				PlayerTextDrawSetProportional(playerid, IntroTD4[playerid][35], 1);					
			}
		}
	}
	else{
		switch(IntroStep){
			case 1:{
				for(new i; i<sizeof(IntroTD1[]); i++){
					PlayerTextDrawHide(playerid, IntroTD1[playerid][i]);
					PlayerTextDrawDestroy(playerid, IntroTD1[playerid][i]);	
				}
			}
			case 2:{
				for(new i; i<sizeof(IntroTD2[]); i++){
					PlayerTextDrawHide(playerid, IntroTD2[playerid][i]);
					PlayerTextDrawDestroy(playerid, IntroTD2[playerid][i]);
				}
			}
			case 3:{
				for(new i; i<sizeof(IntroTD3[]); i++){
					PlayerTextDrawHide(playerid, IntroTD3[playerid][i]);
					PlayerTextDrawDestroy(playerid, IntroTD3[playerid][i]);
				}
			}
			case 4:{
				for(new i; i<sizeof(IntroTD4[]); i++){
					PlayerTextDrawHide(playerid, IntroTD4[playerid][i]);
					PlayerTextDrawDestroy(playerid, IntroTD4[playerid][i]);
				}				
			}
		}
	}
	return 1;
}