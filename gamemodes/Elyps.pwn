/**************************************************
***************************************************
*****************Shortcut-uri**********************
***************************************************
***************************************************
1. Libraries
2. Difines
	2.1 Dialog IDs
3. Player Variables
4. Forwarduri
5. Functii utile
6. Functii Primare
8. OnGamemodeInit
	8.1 TEXTDRAW LOGIN SYSTEM
9. OnPlayerConnect
	9.1 TEXTDRAW LOGIN SYSTEM
===================================================
===================================================
===================================================
4286f4
*/
//Libraries
native WP_Hash(buffer[], len, const str[]);
#include <a_samp>
#include <crashdetect>
#include <jit>
#include <YSI_Data\y_iterate>
//
#include <YSF>
#include <a_mysql>
#include <strlib>
#include <sscanf2>
#include <Pawn.CMD>

//Defines
#if !defined isnull
    #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif
#if !defined strcpy
    #define strcpy(%0,%1) strcat((%0[0] = EOS, %0), %1)
#endif
#define MYSQL_HOST	"localhost"
#define MYSQL_USER	"root"
#define MYSQL_PASS	""
#define MYSQL_DB	"elypsgm"
#define GM_VERSION	"Elyps"
#define SCM			SendClientMessage
#define MAX_PASSWORD_LENGTH 25
//***** Dialog IDs *****//
#define DIALOG_PASSWORD 				1
#define DIALOG_CONFIRM_PASSWORD 		2
#define DIALOG_EMAIL					3
#define DIALOG_AGE						4
#define DIALOG_GENDER					5
#define DIALOG_INVALID_TEXTDRAW			6
#define DIALOG_LOCATION					7
//***** End Dialog IDs *****//
//***** SERVER COLORS *****//
#define COLOR_ERROR 0xd33f3fFF

//******** Global Variables ********
new MySQL:SQL;
new Text:gLoginTD[34];
new PlayerText:pLoginTD[MAX_PLAYERS][7];
new CivilSkins[2][] = {
	{188, 170, 250, 289, 23},
	{12, 55, 56, 65, 226, 216}
};
//******** End Global Variables ********
// ======== Player Variables =========
enum LoginSteps{
	lPassword,
	lRepeatPassword,
	lEmail,
	lAge,
	lGender
};
new pLoginSteps[MAX_PLAYERS][LoginSteps];
enum pInfo{
	pNormalName[MAX_PLAYER_NAME],
	pLogged,
	pPassword[256],
	pEmail[80],
	pAge,
	pGender,
	pSkin[2],
	pSpawnLocation
};
new PlayerInfo[MAX_PLAYERS][pInfo];
// ======== End Player Variables =========
main()
{
	print("\n----------------------------------");
	print(" Elyps RPG v0.1 loaded!");
	print("----------------------------------\n");
}

//=============== FORWARDURI =================
forward MySQLCheckAccount(playerid);
forward ChangeLoginTextDrawPreviewModel(playerid, LR);
//=============== FORWARDURI END =================

//=+=+=+=+= Functii utile =========================
 stock GetPName(playerid){
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, MAX_PLAYER_NAME);
	return name;
}
//native SetPlayerPosEx(playerid, Float:x, Float:y, Float:z, VirtualWorld = 0, Interior = 0)
stock SetPlayerPosEx(playerid, Float:x, Float:y, Float:z, VirtualWorld = 0, Interior = 0){
	SetPlayerPos(playerid, x, y, z);
	SetPlayerVirtualWorld(playerid, VirtualWorld);
	SetPlayerInterior(playerid, Interior);
	return 1;
}
//=+=+=+=+= Functii utile END =========================
public OnGameModeInit()
{
	printf("Size: %d", strlen(CivilSkins[0]));
//	AddPlayerClass(0,1958.3783,1343.1572,1100.3746,269.1425,-1,-1,-1,-1,-1,-1);
	SetGameModeText(GM_VERSION);
	SQL = mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASS, MYSQL_DB);
	if(mysql_errno(SQL) != 0){
		printf("Server failed to connect to the database. Trying to connect from mysql config file...");
		SQL = mysql_connect_file();
		if(mysql_errno(SQL) != 0){
			printf("Server failed to connect to the database from the config file. Server is shutting down.");
			SendRconCommand("exit");
		}
		else printf("Server succesfully connected to MySQL database from the mysql config file!");
	}
	else printf("Server succesfully connected to MySQL database!");
	
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

public OnGameModeExit()
{
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{	
	if(IsPlayerNPC(playerid)) return 1;
	TogglePlayerSpectating(playerid, true);
	MySQLCheckAccount(playerid);
	InterpolateCameraPos(playerid, 2157.884277, 1778.892822, 109.327987, 2051.111816, 1715.612548, 36.595863, 29000);
	InterpolateCameraLookAt(playerid, 2160.093994, 1775.069702, 106.982727, 2047.538696, 1712.142944, 36.155029, 26000);
	SetPlayerPosEx(playerid, 2157.884277, 1778.892822, 109.327987, playerid + 1);
	foreach(new i : Player)
	{
		HidePlayerForPlayer(i, playerid);
	}
	return 1;
}
//============ Functii Primare ===============
public MySQLCheckAccount(playerid)
{
	new string[256], Cache:result, registred = 0;
	mysql_format(SQL, string, sizeof(string), "SELECT * FROM `accounts` WHERE `username` = '%e'", GetPName(playerid));
	result = mysql_query(SQL, string);
	cache_get_row_count(registred);
	if(registred == 1){
		SCM(playerid, -1, "Esti inregistrat!");
	}
	else ShowPlayerRegisterTXD(playerid, true), PlayerInfo[playerid][pLogged] = 2;
	cache_delete(result);
	return 1;
}
stock ShowPlayerRegisterTXD(playerid, bool:show = true){
	if(show){
		SelectTextDraw(playerid, 0xc0cde5FF);
		for(new i; i<=13; i++) TextDrawShowForPlayer(playerid, gLoginTD[i]);
		for(new i = 21; i<= 22; i++) TextDrawShowForPlayer(playerid, gLoginTD[i]);
		for(new i=26; i<=29; i++) TextDrawShowForPlayer(playerid, gLoginTD[i]);
		for(new i=30; i<=31; i++) TextDrawShowForPlayer(playerid, gLoginTD[i]);
		for(new i=0; i<sizeof(pLoginTD[])-1; i++) {
			PlayerTextDrawShow(playerid, pLoginTD[playerid][i]);
			if(i==1 || i==2 || i==3 || i==5 || i==0)
			{
				PlayerTextDrawSetString(playerid, pLoginTD[playerid][i], "LD_CHAT:thumbdn");
			}
		}
	}
	else{
		for(new i=0; i<sizeof(gLoginTD); i++){
			TextDrawHideForPlayer(playerid, gLoginTD[i]);
		}
		for(new i;i<sizeof(pLoginTD[]); i++){
			PlayerTextDrawHide(playerid, pLoginTD[playerid][i]);
		}
	}
	return 1;
}
CMD:txd(playerid)
{
	for(new i; i<=13; i++) TextDrawShowForPlayer(playerid, gLoginTD[i]);
	for(new i=27; i<=30; i++) TextDrawShowForPlayer(playerid, gLoginTD[i]);
	for(new i=31; i<=32; i++) TextDrawShowForPlayer(playerid, gLoginTD[i]);
	PlayerTextDrawShow(playerid, pLoginTD[playerid][4]);
/*	for(new i; i < sizeof(gLoginTD); i++)
	{
		TextDrawShowForPlayer(playerid, gLoginTD[i]);
	}
	for(new i; i < sizeof(pLoginTD); i++)
	{
		PlayerTextDrawShow(playerid, pLoginTD[playerid][i]);
	}*/
	return 1;
}
//============ Functii Primare END ===============
public OnPlayerConnect(playerid)
{
	ResetVars(playerid);
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
ResetVars(playerid){
	static t[pInfo];
	static l[LoginSteps];
	pLoginSteps[playerid] = l;
	new s[MAX_PASSWORD_LENGTH+1] = EOS;
	SetPVarString(playerid, "pConfirmPass", s);
	DeletePVar(playerid, "pPassConf");
	PlayerInfo[playerid] = t;
}
public OnPlayerDisconnect(playerid, reason)
{
	DeletePVar(playerid, "pConfirmPass");
	return 1;
}

public OnPlayerSpawn(playerid)
{
	SCM(playerid, -1, "Te-ai spawnat plm.");
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}
public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if(clickedid == gLoginTD[7])
	{
		ShowPlayerDialog(playerid, DIALOG_PASSWORD, DIALOG_STYLE_PASSWORD, "Please type your password", sprintf("Max password length: %d\nMin password length: 6", MAX_PASSWORD_LENGTH), "OK", "");
	}
	else if(clickedid == gLoginTD[9])
	{
		ShowPlayerDialog(playerid, DIALOG_CONFIRM_PASSWORD, DIALOG_STYLE_PASSWORD, "Please retype your password", "Confirm your password.", "OK", "");
	}
	else if(clickedid == gLoginTD[11])
	{
		ShowPlayerDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, "Email", "Please type you email\nto be able to recover your\npassword in the future.", "Ok", "");
	}
	else if(clickedid == gLoginTD[13])
	{
		ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "Type your age", "Please type your age here.", "Ok", "");
	}
	else if(clickedid == gLoginTD[31])
	{
		ShowPlayerDialog(playerid, DIALOG_GENDER, DIALOG_STYLE_MSGBOX, "Choose your gender", "Please choose your gender.", "Male", "Female");
	}
	else if(clickedid == gLoginTD[28] || clickedid == gLoginTD[29]){
		if(PlayerInfo[playerid][pGender] == 0) return TextDrawShowForPlayer(playerid, gLoginTD[33]), TextDrawShowForPlayer(playerid, gLoginTD[32]);
		if(clickedid == gLoginTD[28]) ChangeLoginTextDrawPreviewModel(playerid, 2);
		else if(clickedid == gLoginTD[29]) ChangeLoginTextDrawPreviewModel(playerid, 1);
	}
	else if(clickedid == gLoginTD[21]){
		new j;
		for(new i; i<sizeof(pLoginSteps[]); i++)
		{
			if(pLoginSteps[playerid][LoginSteps:i] == 1){
				j++;
			}
			else{
				for(new k = 22; k<26; k++){
					TextDrawShowForPlayer(playerid, gLoginTD[k]);
				}
				break;
			}
		}
		if(j == sizeof(pLoginSteps[])){
			ShowPlayerDialog(playerid, DIALOG_LOCATION, DIALOG_STYLE_MSGBOX, "Choose your spawn location", "{e0e0e0}Please choose your preffered spawn loctaion\n{ff6a26}LS {e0e0e0}- {544fff}L{e0e0e0}os {544fff}S{e0e0e0}antos\n{e5741d}LV - {646adb}L{e0e0e0}as {646adb}V{e0e0e0}enturas", "LS", "LV");
		}
	}
	else if(clickedid == Text:INVALID_TEXT_DRAW){
		if(PlayerInfo[playerid][pLogged] == 2) ShowPlayerDialog(playerid, DIALOG_INVALID_TEXTDRAW, DIALOG_STYLE_MSGBOX, "{db2323}!!! {dbdbdb}[warning]:Return to register {db2323}!!!", "It seems that you left from the register selection.\nTo return back please click Return or you will be kicked\nfrom the server.", "Return", "Quit");
	}
/*	if(clickedid == gLoginTD[7] || clickedid == gLoginTD[29] || clickedid == gLoginTD[30]){
		SCM(playerid, -1, "Test");
	}*/
	return 1;
}
public ChangeLoginTextDrawPreviewModel(playerid, LR){ // L = LEFT = 2 // R = RIGHT = 1
	if(LR == 1 && PlayerInfo[playerid][pSkin][1] >= 0 && PlayerInfo[playerid][pSkin][1] <= 4){
		if(PlayerInfo[playerid][pSkin][1] < 4) PlayerInfo[playerid][pSkin][1]++;
	}
	if(LR == 2 && PlayerInfo[playerid][pSkin][1] >= 0 && PlayerInfo[playerid][pSkin][1] <= 4){
		if(PlayerInfo[playerid][pSkin][1] > 0) PlayerInfo[playerid][pSkin][1]--;
	}
	PlayerInfo[playerid][pSkin][0] = PlayerInfo[playerid][pSkin][1];
	PlayerTextDrawHide(playerid, pLoginTD[playerid][4]), PlayerTextDrawSetPreviewModel(playerid, pLoginTD[playerid][4], CivilSkins[PlayerInfo[playerid][pGender]-1][PlayerInfo[playerid][pSkin][1]]), PlayerTextDrawShow(playerid, pLoginTD[playerid][4]);	
	return 1;
}
public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	return 0;
}
public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags){
	if(result == -1){
		SCM(playerid, -1, sprintf("{d9d9d9}Command {ffaa80}/%s {d9d9d9}was not found. Please use /help to see server commands!", cmd));
		return 0;
	}
	return 1;
}
public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_PASSWORD:{
			if(isnull(inputtext)) return 1;
			new y=0;
			if(strlen(inputtext) < 6){
				y=1;
				PlayerTextDrawShow(playerid, pLoginTD[playerid][6]), TextDrawShowForPlayer(playerid, gLoginTD[14]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][0], "LD_CHAT:thumbdn"), PlayerTextDrawSetString(playerid, pLoginTD[playerid][6], "your_password_is_too_short(min_6_characters)");
			}
			else if(strlen(inputtext) > 25){
				y=1;
				PlayerTextDrawShow(playerid, pLoginTD[playerid][6]), TextDrawShowForPlayer(playerid, gLoginTD[14]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][0], "LD_CHAT:thumbdn"), PlayerTextDrawSetString(playerid, pLoginTD[playerid][6], "your_password_is_too_long(max_25_characters)");
			}
			if(strfind(inputtext, "%") != -1){
				y=1;
				PlayerTextDrawShow(playerid, pLoginTD[playerid][6]), TextDrawShowForPlayer(playerid, gLoginTD[14]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][0], "LD_CHAT:thumbdn"), PlayerTextDrawSetString(playerid, pLoginTD[playerid][6], "your_password_contain_unnallowed_characters!");
			}
			if(y==1){
				if(GetPVarInt(playerid, "pPassConf") == 1){//DeletePVar(playerid, "pConfirmPass");
					pLoginSteps[playerid][lPassword] = 1;
					TextDrawShowForPlayer(playerid, gLoginTD[15]), TextDrawShowForPlayer(playerid, gLoginTD[16]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][1], "LD_CHAT:thumbdn");
				}
				return 1;
			}
			PlayerTextDrawHide(playerid, pLoginTD[playerid][6]), TextDrawHideForPlayer(playerid, gLoginTD[14]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][0], "LD_CHAT:thumbup"), pLoginSteps[playerid][lPassword] = 1;
			SetPVarInt(playerid, "pPassConf", 1);
			new str[MAX_PASSWORD_LENGTH+1];
			GetPVarString(playerid, "pConfirmPass", str, sizeof(str));
			if(!isnull(str) && strcmp(inputtext, str)){
				TextDrawShowForPlayer(playerid, gLoginTD[15]), TextDrawShowForPlayer(playerid, gLoginTD[16]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][1], "LD_CHAT:thumbdn");
			}
			if(!strcmp(inputtext, str) && !isnull(str)){
				TextDrawHideForPlayer(playerid, gLoginTD[15]), TextDrawHideForPlayer(playerid, gLoginTD[16]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][1], "LD_CHAT:thumbup");
			}
//			DeletePVar(playerid, "pConfirmPass");
			format(PlayerInfo[playerid][pPassword], 256, "%s", inputtext);
		}
		case DIALOG_CONFIRM_PASSWORD:{
			if(isnull(inputtext) || GetPVarInt(playerid, "pPassConf") == 0) return 1;
			else if(!strcmp(inputtext, PlayerInfo[playerid][pPassword])){
				TextDrawHideForPlayer(playerid, gLoginTD[15]), TextDrawHideForPlayer(playerid, gLoginTD[16]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][1], "LD_CHAT:thumbup"), pLoginSteps[playerid][lRepeatPassword] = 1;
				SetPVarString(playerid, "pConfirmPass", inputtext);
				SetPVarInt(playerid, "pPassConf", 1);
			}
			else if(strcmp(inputtext, PlayerInfo[playerid][pPassword]) || strlen(inputtext) < 6 || strlen(inputtext) > 25 || strfind(inputtext, "%") != -1){
				TextDrawShowForPlayer(playerid, gLoginTD[15]), TextDrawShowForPlayer(playerid, gLoginTD[16]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][1], "LD_CHAT:thumbdn"), pLoginSteps[playerid][lRepeatPassword] = 0;
				SetPVarString(playerid, "pConfirmPass", inputtext);
			}
			return 1;
		}
		case DIALOG_EMAIL:{
			if(IsValidEmailAddress(inputtext) && strfind(inputtext, "%") && !isnull(inputtext)){
				PlayerInfo[playerid][pEmail] = EOS;
				strcat(PlayerInfo[playerid][pEmail], inputtext);
				PlayerTextDrawShow(playerid, pLoginTD[playerid][2]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][2], "LD_CHAT:thumbup"), pLoginSteps[playerid][lEmail] = 1;
				TextDrawHideForPlayer(playerid, gLoginTD[17]), TextDrawHideForPlayer(playerid, gLoginTD[18]);
//				TextDrawShowForPlayer(playerid, gLoginTD[17]), TextDrawShowForPlayer(playerid, gLoginTD[18]);
			}
			else{
				TextDrawShowForPlayer(playerid, gLoginTD[17]), TextDrawShowForPlayer(playerid, gLoginTD[18]);
				PlayerTextDrawShow(playerid, pLoginTD[playerid][2]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][2], "LD_CHAT:thumbdn"), pLoginSteps[playerid][lEmail] = 0;
			}
		}
		case DIALOG_AGE:{
			if(isnull(inputtext)) return 1;
			new a = strval(inputtext);
			if(IsANumber(inputtext) && a > 9 && a < 99) PlayerTextDrawSetString(playerid, pLoginTD[playerid][3], "LD_CHAT:thumbup"), TextDrawHideForPlayer(playerid, gLoginTD[19]), TextDrawHideForPlayer(playerid, gLoginTD[20]), PlayerInfo[playerid][pAge] = strval(inputtext), pLoginSteps[playerid][lAge] = 1;
			else PlayerTextDrawSetString(playerid, pLoginTD[playerid][3], "LD_CHAT:thumbdn"), TextDrawShowForPlayer(playerid, gLoginTD[19]), TextDrawShowForPlayer(playerid, gLoginTD[20]), pLoginSteps[playerid][lAge] = 0;
		}
		case DIALOG_GENDER:{
			if(response)
			{
				if(PlayerInfo[playerid][pGender] != 1) PlayerInfo[playerid][pSkin][1] = 0;
				PlayerInfo[playerid][pGender] = 1;
				PlayerTextDrawHide(playerid, pLoginTD[playerid][4]), PlayerTextDrawSetPreviewModel(playerid, pLoginTD[playerid][4], CivilSkins[0][PlayerInfo[playerid][pSkin][1]]), PlayerTextDrawShow(playerid, pLoginTD[playerid][4]);
			}
			if(!response)
			{
				if(PlayerInfo[playerid][pGender] != 2) PlayerInfo[playerid][pSkin][1] = 0;
				PlayerInfo[playerid][pGender] = 2;
				PlayerTextDrawHide(playerid, pLoginTD[playerid][4]), PlayerTextDrawSetPreviewModel(playerid, pLoginTD[playerid][4], CivilSkins[1][PlayerInfo[playerid][pSkin][1]]), PlayerTextDrawShow(playerid, pLoginTD[playerid][4]);
			}
			PlayerTextDrawSetString(playerid, pLoginTD[playerid][5], "LD_CHAT:thumbup"), TextDrawHideForPlayer(playerid, gLoginTD[33]), TextDrawHideForPlayer(playerid, gLoginTD[32]),  pLoginSteps[playerid][lGender] = 1;
		}
		case DIALOG_LOCATION:{
			if(response){
				PlayerInfo[playerid][pSpawnLocation] = 1;
			}
			else if(!response) PlayerInfo[playerid][pSpawnLocation] = 2;
			ShowPlayerRegisterTXD(playerid, false);
			PlayerInfo[playerid][pLogged] = 1;
			CancelSelectTextDraw(playerid);
			SaveNewPlayer(playerid);
		}
		case DIALOG_INVALID_TEXTDRAW:{
			if(response){
				if(PlayerInfo[playerid][pLogged] == 2)SelectTextDraw(playerid, 0xc0cde5FF); // Register Selection
			}
			else Kick(playerid);
		}
	}
	return 1;
}
SaveNewPlayer(playerid){
	new HashedPassword[129];
	WP_Hash(HashedPassword, sizeof(HashedPassword), PlayerInfo[playerid][pPassword]);
	new string[900];
	mysql_format(SQL, string, sizeof(string), "INSERT INTO `accounts` (`username`, `password`, `email`, `spawn_location`, `skin`, `age`) VALUES ('%e', '%e', '%e', '%i', '%i', '%i')",
	GetPName(playerid),
	HashedPassword,
	PlayerInfo[playerid][pEmail],
	PlayerInfo[playerid][pSpawnLocation],
	PlayerInfo[playerid][pSkin],
	PlayerInfo[playerid][pAge]);
	mysql_query(SQL, string);
	return 1;
}
IsANumber(const inputtext[])
{
	for(new i; i < strlen(inputtext); i++)
	{
		if(inputtext[i] > '9' || inputtext[i] < '0') return 0;
	}
	return 1;
}
IsValidEmailAddress(const email[])
{
    new at_pos = strfind(email, "@", true);
    if(at_pos >= 1)
    {
        new offset = (at_pos + 1), dot_pos = strfind(email, ".", true, offset);
        if(dot_pos > offset)
        {
            return 1;
        }
    }
    return 0;
}
public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}
