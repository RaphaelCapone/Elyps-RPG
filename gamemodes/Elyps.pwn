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
#include <timerfix>
#include <crashdetect>
#include <jit>
#include <YSI_Data\y_iterate>
#include <YSI_Coding\y_hooks>
#include <streamer>
//
#include <YSF>
#include <a_mysql>
#include <strlib>
#include <sscanf2>
#include <Pawn.CMD>
//
#include <elyps_inc\textdraws>
//Defines
#define PawnPlus 0
#if !defined isnull
    #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif
#if !defined strcpy
    #define strcpy(%0,%1) strcat((%0[0] = EOS, %0), %1)
#endif
#define MYSQL_HOST	"host"
#define MYSQL_USER	"user"
#define MYSQL_PASS	"password"
#define MYSQL_DB	"database name"
#define GM_VERSION	"Elyps"
#define SCM			SendClientMessage
#define MAX_PASSWORD_LENGTH 25
#define MAX_INTRO_OBJECTS 3
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
new IntroObjects[MAX_PLAYERS][MAX_INTRO_OBJECTS][5];
/*new IntroActors[][4];
new IntroActorWeapons[4];*/
//******** End Global Variables ********
// ======== Player Variables =========
enum RegisterSteps{
	rPassword,
	rRepeatPassword,
	rEmail,
	rAge,
	rGender
};
new pRegisterSteps[MAX_PLAYERS][RegisterSteps];
enum pInfo{
	pNormalName[MAX_PLAYER_NAME],
	pLogged, // 1- Logged/Registred 2- Register Step 3- Intro/Tutorial step
	pPassword[256],
	pEmail[80],
	pAge,
	pGender,
	pSkin[2],
	pSpawnLocation
};
new PlayerInfo[MAX_PLAYERS][pInfo];
new pTutorialStep[MAX_PLAYERS],
	pTutorialTimer[MAX_PLAYERS];
/*new Float:SpawnLocations[][][] = {
	{{1642.1813,-2238.3936,-2.7150}}, //spawn 1 - 1
	{{1686.0148,-2238.4246,-2.7134}} //spawn 1 - 2
};*/
					  //[a][b][c]
new Float:SpawnLocations[][][] = {
	{{1642.1813,-2238.3936,-2.7150},
	{1686.0148,-2238.4246,-2.7134}} // spawn LS cu 1 locatii
};
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
forward StartTutorialForPlayer(playerid);
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
	LoadGlobalTextDraws();
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
	for(new i = 0;i < sizeof(IntroTD2[]); i++){
		switch(i){
			case 36..38:{
				continue;
			}
		}
		PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][i], 255);
		PlayerTextDrawShow(playerid, IntroTD2[playerid][i]);
	}
	return 1;
}
CMD:intro(playerid){
	TutorialTextDrawLoad(playerid, 1, true);
	pTutorialStep[playerid] = 1;
	StartTutorialForPlayer(playerid);
}
//============ Functii Primare END ===============
public OnPlayerConnect(playerid)
{
	ResetVars(playerid);
	LoadPlayerTextDraws(playerid);
	return 1;
}
ResetVars(playerid){
	static t[pInfo];
	static l[RegisterSteps];
	pRegisterSteps[playerid] = l;
	new s[MAX_PASSWORD_LENGTH+1] = EOS;
	SetPVarString(playerid, "pConfirmPass", s);
	DeletePVar(playerid, "pPassConf");
	PlayerInfo[playerid] = t;
}
public OnPlayerDisconnect(playerid, reason)
{
	DeletePVar(playerid, "pTextShow");
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
		for(new i; i<sizeof(pRegisterSteps[]); i++)
		{
			if(pRegisterSteps[playerid][RegisterSteps:i] == 1){
				j++;
			}
			else{
				for(new k = 22; k<26; k++){
					TextDrawShowForPlayer(playerid, gLoginTD[k]);
				}
				break;
			}
		}
		if(j == sizeof(pRegisterSteps[])){
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
	PlayerInfo[playerid][pSkin][0] = CivilSkins[PlayerInfo[playerid][pGender]-1][PlayerInfo[playerid][pSkin][1]];
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
					pRegisterSteps[playerid][rPassword] = 1;
					TextDrawShowForPlayer(playerid, gLoginTD[15]), TextDrawShowForPlayer(playerid, gLoginTD[16]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][1], "LD_CHAT:thumbdn");
				}
				return 1;
			}
			PlayerTextDrawHide(playerid, pLoginTD[playerid][6]), TextDrawHideForPlayer(playerid, gLoginTD[14]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][0], "LD_CHAT:thumbup"), pRegisterSteps[playerid][rPassword] = 1;
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
				TextDrawHideForPlayer(playerid, gLoginTD[15]), TextDrawHideForPlayer(playerid, gLoginTD[16]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][1], "LD_CHAT:thumbup"), pRegisterSteps[playerid][rRepeatPassword] = 1;
				SetPVarString(playerid, "pConfirmPass", inputtext);
				SetPVarInt(playerid, "pPassConf", 1);
			}
			else if(strcmp(inputtext, PlayerInfo[playerid][pPassword]) || strlen(inputtext) < 6 || strlen(inputtext) > 25 || strfind(inputtext, "%") != -1){
				TextDrawShowForPlayer(playerid, gLoginTD[15]), TextDrawShowForPlayer(playerid, gLoginTD[16]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][1], "LD_CHAT:thumbdn"), pRegisterSteps[playerid][rRepeatPassword] = 0;
				SetPVarString(playerid, "pConfirmPass", inputtext);
			}
			return 1;
		}
		case DIALOG_EMAIL:{
			if(IsValidEmailAddress(inputtext) && strfind(inputtext, "%") && !isnull(inputtext)){
				PlayerInfo[playerid][pEmail] = EOS;
				strcat(PlayerInfo[playerid][pEmail], inputtext);
				PlayerTextDrawShow(playerid, pLoginTD[playerid][2]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][2], "LD_CHAT:thumbup"), pRegisterSteps[playerid][rEmail] = 1;
				TextDrawHideForPlayer(playerid, gLoginTD[17]), TextDrawHideForPlayer(playerid, gLoginTD[18]);
//				TextDrawShowForPlayer(playerid, gLoginTD[17]), TextDrawShowForPlayer(playerid, gLoginTD[18]);
			}
			else{
				TextDrawShowForPlayer(playerid, gLoginTD[17]), TextDrawShowForPlayer(playerid, gLoginTD[18]);
				PlayerTextDrawShow(playerid, pLoginTD[playerid][2]), PlayerTextDrawSetString(playerid, pLoginTD[playerid][2], "LD_CHAT:thumbdn"), pRegisterSteps[playerid][rEmail] = 0;
			}
		}
		case DIALOG_AGE:{
			if(isnull(inputtext)) return 1;
			new a = strval(inputtext);
			if(IsANumber(inputtext) && a > 9 && a < 99) PlayerTextDrawSetString(playerid, pLoginTD[playerid][3], "LD_CHAT:thumbup"), TextDrawHideForPlayer(playerid, gLoginTD[19]), TextDrawHideForPlayer(playerid, gLoginTD[20]), PlayerInfo[playerid][pAge] = strval(inputtext), pRegisterSteps[playerid][rAge] = 1;
			else PlayerTextDrawSetString(playerid, pLoginTD[playerid][3], "LD_CHAT:thumbdn"), TextDrawShowForPlayer(playerid, gLoginTD[19]), TextDrawShowForPlayer(playerid, gLoginTD[20]), pRegisterSteps[playerid][rAge] = 0;
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
			PlayerTextDrawSetString(playerid, pLoginTD[playerid][5], "LD_CHAT:thumbup"), TextDrawHideForPlayer(playerid, gLoginTD[33]), TextDrawHideForPlayer(playerid, gLoginTD[32]),  pRegisterSteps[playerid][rGender] = 1, PlayerInfo[playerid][pSkin][0] = CivilSkins[PlayerInfo[playerid][pGender]-1][PlayerInfo[playerid][pSkin][1]];
		}
		case DIALOG_LOCATION:{
			if(response){
				PlayerInfo[playerid][pSpawnLocation] = 1;
			}
			else if(!response) PlayerInfo[playerid][pSpawnLocation] = 2;
			PlayerInfo[playerid][pLogged] = 1;
			SaveNewPlayer(playerid);
			ShowPlayerRegisterTXD(playerid, false);
			pTutorialStep[playerid] = 1;
			StartTutorialForPlayer(playerid);
			CancelSelectTextDraw(playerid);
		}
		case DIALOG_INVALID_TEXTDRAW:{
			if(response){
				if(PlayerInfo[playerid][pLogged] == 2)SelectTextDraw(playerid, 0xc0cde5FF); // Register Selection
			}
			else if(!response && PlayerInfo[playerid][pLogged] == 2) Kick(playerid);
		}
	}
	return 1;
}
SaveNewPlayer(playerid){
	strcat(PlayerInfo[playerid][pNormalName], GetPName(playerid));
	new HashedPassword[129];
	WP_Hash(HashedPassword, sizeof(HashedPassword), PlayerInfo[playerid][pPassword]);
	new string[900];
	mysql_format(SQL, string, sizeof(string), "INSERT INTO `accounts` (`username`, `password`, `email`, `spawn_location`, `skin`, `age`) VALUES ('%e', '%e', '%e', '%i', '%i', '%i')",
	PlayerInfo[playerid][pNormalName],
	HashedPassword,
	PlayerInfo[playerid][pEmail],
	PlayerInfo[playerid][pSpawnLocation],
	PlayerInfo[playerid][pSkin],
	PlayerInfo[playerid][pAge]);
	mysql_query(SQL, string);
	return 1;
}
public StartTutorialForPlayer(playerid){
	switch(pTutorialStep[playerid]){
		case 1:{
			PlayerInfo[playerid][pLogged] = 3;
			TutorialTextDrawLoad(playerid, 1, true);
			for(new i; i < sizeof(IntroTD1[]); i++){
				PlayerTextDrawShow(playerid, IntroTD1[playerid][i]);
			}
			pTutorialStep[playerid] = 2;
			pTutorialTimer[playerid] = SetTimerEx("StartTutorialForPlayer", 4435, false, "i", playerid); //2890ms
		}
		case 2:{
			TutorialTextDrawLoad(playerid, 2, true);
			for(new i; i < sizeof(IntroTD2[]); i++){
/*				switch(IntroTD2[playerid][i]){
					case 36..38:{
						PlayerTextDrawShow(playerid, IntroTD2[playerid][i]);
						continue;
					}
				}*/
				if(i == 42) break;
				PlayerTextDrawBoxColor(playerid, IntroTD2[playerid][i], 255);
				PlayerTextDrawShow(playerid, IntroTD2[playerid][i]);
			}
			TutorialTextDrawLoad(playerid, 1, false);
/*			for(new i; i< sizeof(IntroTD1[]); i++){
				PlayerTextDrawHide(playerid, IntroTD1[playerid][i]);
			}*/
			InterpolateCameraPos(playerid, 1620.183593, -1541.790161, 129.892456, 1620.183593, -1541.790161, 129.892456, 10000);
			InterpolateCameraLookAt(playerid, 1618.188598, -1537.212280, 129.642562, 1618.188598, -1537.212280, 129.642562, 10000);			
			#if PawnPlus == 1
			
			#else
			pTutorialStep[playerid] = 3;
			SetPVarInt(playerid, "pTextShow", 1);			
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 1000, false, "ii", playerid, 1);
			#endif
		}
		case 3:{
			InterpolateCameraPos(playerid, 1640.481689, -1534.251708, 146.509735, 1682.516357, -1576.309570, 301.238220, 10000);
			InterpolateCameraLookAt(playerid, 1638.117919, -1529.860595, 146.147094, 1679.867065, -1572.078613, 300.954437, 10000);
/*
			TutorialTextDrawLoad(playerid, 2, false);
			TutorialTextDrawLoad(playerid, 3, true);
*/
			#if PawnPlus == 1
			
			#else
			TutorialTextDrawLoad(playerid, 3, true);
			SetPVarInt(playerid, "pTextShow", 1);
			pTutorialStep[playerid] = 4;
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 11300, false, "ii", playerid, 2);
			#endif
		}
		case 4:{
			InterpolateCameraPos(playerid, 2485.626220, 2132.563964, 38.364555, 2243.112304, 2157.244873, 44.499011, 12000);
			InterpolateCameraLookAt(playerid, 2480.821777, 2132.610839, 36.980831, 2238.138916, 2156.781494, 44.276428, 5000);		
			pTutorialStep[playerid] = 5;
			pTutorialTimer[playerid] = SetTimerEx("StartTutorialForPlayer", 13800, false, "i", playerid);
		}
		case 5:{
			//===========================Objects Loading + Actors==========================================
			//IntroObjects types: 0 - Actors ::: 1 - Objects ::: 2 - Vehicles
			IntroObjects[playerid][2][0] = CreateVehicle(412,1667.9530,-806.0679,56.2625,299.0900,171,171, -1);
			SetVehicleVirtualWorld(IntroObjects[playerid][2][0], GetPlayerVirtualWorld(playerid));
			LinkVehicleToInterior(IntroObjects[playerid][2][0], GetPlayerInterior(playerid));
			
			IntroObjects[playerid][0][0] = CreateDynamicActor(107, 1665.2905, -804.3958, 55.8668, -60.0000, 1, 100, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), playerid);
			ApplyDynamicActorAnimation(IntroObjects[playerid][0][0], "SHOP", "SHP_GUN_AIM", 4.0, 1, 0, 0, 0, 0);

			IntroObjects[playerid][0][1] = CreateDynamicActor(104, 1667.9333,-797.5499,55.8541,163.9448, 1, 100, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), playerid);
			ApplyDynamicActorAnimation(IntroObjects[playerid][0][1], "SHOP", "SHP_GUN_AIM", 4.0, 1, 0, 0, 0, 0);

			IntroObjects[playerid][0][2] = CreateDynamicActor(103, 1670.8167,-800.3084,55.6557,127.2845, 1, 100, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), playerid);
			ApplyDynamicActorAnimation(IntroObjects[playerid][0][2], "SHOP", "SHP_GUN_AIM", 4.0, 1, 0, 0, 0, 0);

			IntroObjects[playerid][0][3] = CreateDynamicActor(106, 1660.0460,-803.8052,56.6396,299.3530, 1, 100, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), playerid);
			ApplyDynamicActorAnimation(IntroObjects[playerid][0][3], "SHOP", "SHP_GUN_AIM", 4.0, 1, 0, 0, 0, 0);
			
			ApplyDynamicActorAnimation(IntroObjects[playerid][0][0], "SHOP", "SHP_GUN_AIM", 4.0, 1, 0, 0, 0, 0);
			
			IntroObjects[playerid][1][0] = CreateObject(353, 1665.598022, -804.399658, 56.770793, 0.000000, 0.000000, 48.099945, 300.00); 
			IntroObjects[playerid][1][1] = CreateObject(353, 1660.330810, -803.809936, 57.030944, -1.799999, -2.700000, 42.699943, 300.00); 
			IntroObjects[playerid][1][2] = CreateObject(353, 1667.721679, -797.778686, 56.235710, -1.799999, -2.700000, -91.100112, 300.00); 
			IntroObjects[playerid][1][3] = CreateObject(355, 1670.482421, -800.306213, 56.085571, -36.399993, -10.899998, -123.100021, 300.00);		
			//===========================Objects Loading + Actors==========================================
			TutorialTextDrawLoad(playerid, 4, true);
			for(new i; i<sizeof(IntroTD4[]); i++){
				if(i==29) i=32;
				PlayerTextDrawBoxColor(playerid, IntroTD4[playerid][i], 0x000000FF);
				PlayerTextDrawColor(playerid, IntroTD4[playerid][i], 0x000000FF);
				PlayerTextDrawShow(playerid, IntroTD4[playerid][i]);
			}
			TogglePlayerControllable(playerid, false);
			SetPlayerPos(playerid, 1656.809326+90, -810.696044+90, 61.113971+90);
			InterpolateCameraPos(playerid, 1656.809326, -810.696044, 61.113971, 1656.809326, -810.696044, 61.113971, 1000);
			InterpolateCameraLookAt(playerid, 1660.348754, -807.624938, 59.370159, 1660.348754, -807.624938, 59.370159, 1000);
			pTutorialStep[playerid] = 6;
			#if PawnPlus == 1
			
			#else
			SetPVarInt(playerid, "pTextShow", 1);
			TutorialTextDrawLoad(playerid, 3, false);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 890, false, "ii", playerid, 3);
			#endif
		}
		case 6:{
			InterpolateCameraPos(playerid, 1656.809326, -810.696044, 61.113971, 1665.754638, -786.025451, 57.093769, 9000);
			InterpolateCameraLookAt(playerid, 1660.348754, -807.624938, 59.370159, 1666.163452, -791.002441, 56.843875, 11000);
		}
		case 7:{  
			if(PlayerInfo[playerid][pSpawnLocation] == 1){
				new randomspawnlocation = random(2);
				new Float:SpawnLocationCoords[3];
				SpawnLocationCoords[0] = SpawnLocations[PlayerInfo[playerid][pSpawnLocation]][randomspawnlocation][0];
				SpawnLocationCoords[1] = SpawnLocations[PlayerInfo[playerid][pSpawnLocation]][randomspawnlocation][0];
				SpawnLocationCoords[2] = SpawnLocations[PlayerInfo[playerid][pSpawnLocation]][randomspawnlocation][0];
				SetSpawnInfo(playerid, 0, PlayerInfo[playerid][pSkin], SpawnLocationCoords[0], SpawnLocationCoords[1], SpawnLocationCoords[2], 0, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}
#define function%0(%1) \
		forward%0(%1); public%0(%1)
#if PawnPlus == 0
function IntroTextDrawsFunc(playerid, stage)
{
	new pTextShow = GetPVarInt(playerid, "pTextShow");
	if(stage == 1){
		if(GetPVarInt(playerid, "pTextShow") == 1){
			PlayerTextDrawHide(playerid, IntroTD2[playerid][36]);
			SetPVarInt(playerid, "pTextShow", 2);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 890, false, "ii", playerid, 1);
		}
		else if(GetPVarInt(playerid, "pTextShow") == 2){
			PlayerTextDrawHide(playerid, IntroTD2[playerid][37]);
			SetPVarInt(playerid, "pTextShow", 3);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 890, false, "ii", playerid, 1);
		}
		else if(GetPVarInt(playerid, "pTextShow") == 3){
			PlayerTextDrawHide(playerid, IntroTD2[playerid][38]);
			SetPVarInt(playerid, "pTextShow", 4);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 389, false, "ii", playerid, 1);
		}
		else if(GetPVarInt(playerid, "pTextShow") == 4){
			PlayerTextDrawShow(playerid, IntroTD2[playerid][42]);
			SetPVarInt(playerid, "pTextShow", 5);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 389, false, "ii", playerid, 1);		
		}
		else if(GetPVarInt(playerid, "pTextShow") == 5){
			PlayerTextDrawShow(playerid, IntroTD2[playerid][43]);
			SetPVarInt(playerid, "pTextShow", 6);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 389, false, "ii", playerid, 1);		
		}
		else if(GetPVarInt(playerid, "pTextShow") == 6){
			PlayerTextDrawShow(playerid, IntroTD2[playerid][44]);
			DeletePVar(playerid, "pTextShow");
			pTutorialTimer[playerid] = SetTimerEx("StartTutorialForPlayer", 389, false, "i", playerid);		
		}
	}
	else if(stage == 2){
		if(GetPVarInt(playerid, "pTextShow") == 1){
			for(new i; i<sizeof(IntroTD3[]); i++){
				switch(i){
					case 38..50: continue;
				}
				PlayerTextDrawBoxColor(playerid, IntroTD3[playerid][i], 0x000000FF);
				PlayerTextDrawColor(playerid, IntroTD3[playerid][i], 0x000000FF);				
				PlayerTextDrawShow(playerid, IntroTD3[playerid][i]);
			}
			TutorialTextDrawLoad(playerid, 2, false);
			InterpolateCameraPos(playerid, 2485.626220, 2132.563964, 38.364555, 2485.626220, 2132.563964, 38.364555, 1000);
			InterpolateCameraLookAt(playerid, 2480.821777, 2132.610839, 36.980831, 2480.821777, 2132.610839, 36.980831, 1000);		
			SetPVarInt(playerid, "pTextShow", 2);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 890, false, "ii", playerid, 2);
		}
		else if(GetPVarInt(playerid, "pTextShow") == 2){
			PlayerTextDrawHide(playerid, IntroTD3[playerid][51]);
			SetPVarInt(playerid, "pTextShow", 3);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 890, false, "ii", playerid, 2);			
		}
		else if(GetPVarInt(playerid, "pTextShow") == 3){
			PlayerTextDrawHide(playerid, IntroTD3[playerid][54]);
			SetPVarInt(playerid, "pTextShow", 4);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 890, false, "ii", playerid, 2);			
		}
		else if(GetPVarInt(playerid, "pTextShow") == 4){
			PlayerTextDrawHide(playerid, IntroTD3[playerid][52]);
			PlayerTextDrawHide(playerid, IntroTD3[playerid][53]);
			SetPVarInt(playerid, "pTextShow", 5);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 389, false, "ii", playerid, 2);			
		}
		else if(GetPVarInt(playerid, "pTextShow") == 5){
			PlayerTextDrawShow(playerid, IntroTD3[playerid][38]);
			SetPVarInt(playerid, "pTextShow", 6);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 389, false, "ii", playerid, 2);
		}
		else if(GetPVarInt(playerid, "pTextShow") == 6){
			for(new i = 46; i<=50; i++){
				PlayerTextDrawShow(playerid, IntroTD3[playerid][i]);
			}
			SetPVarInt(playerid, "pTextShow", 7);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 389, false, "ii", playerid, 2);
		}
		else if(GetPVarInt(playerid, "pTextShow") == 7){
			for(new i = 39; i<=45; i++){
				PlayerTextDrawShow(playerid, IntroTD3[playerid][i]);
			}
			SetPVarInt(playerid, "pTextShow", 1);
			pTutorialTimer[playerid] = SetTimerEx("StartTutorialForPlayer", 389, false, "ii", playerid, 2);
		}
	}
	else if(stage == 3){
		if(pTextShow == 1)
		{
			SetPVarInt(playerid, "pTextShow", 2);
			PlayerTextDrawHide(playerid, IntroTD4[playerid][32]);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 890, false, "ii", playerid, 3);
		}
		if(pTextShow == 2)
		{
			SetPVarInt(playerid, "pTextShow", 3);
			PlayerTextDrawHide(playerid, IntroTD4[playerid][33]);
			PlayerTextDrawHide(playerid, IntroTD4[playerid][34]);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 890, false, "ii", playerid, 3);
		}
		if(pTextShow == 3)
		{
			SetPVarInt(playerid, "pTextShow", 4);
			PlayerTextDrawHide(playerid, IntroTD4[playerid][35]);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 389, false, "ii", playerid, 3);
		}	
		if(pTextShow == 4)
		{
			SetPVarInt(playerid, "pTextShow", 5);
			PlayerTextDrawShow(playerid, IntroTD4[playerid][29]);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 389, false, "ii", playerid, 3);
		}
		if(pTextShow == 5)
		{
			SetPVarInt(playerid, "pTextShow", 6);
			PlayerTextDrawShow(playerid, IntroTD4[playerid][30]);
			pTutorialTimer[playerid] = SetTimerEx("IntroTextDrawsFunc", 389, false, "ii", playerid, 3);
		}	
		if(pTextShow == 6)
		{
			SetPVarInt(playerid, "pTextShow", 1);
			PlayerTextDrawShow(playerid, IntroTD4[playerid][31]);
			pTutorialTimer[playerid] = SetTimerEx("StartTutorialForPlayer", 389, false, "ii", playerid, 3);
		}
	}
	return 1;
}
#endif
IsANumber(const inputtext[])
{
	for(new i; i < strlen(inputtext); i++)
	{
		if(inputtext[i] > '9' || inputtext[i] < '0') return 0;
	}
	return 1;
}
/*IsValidEmailAddress(const email[])
{
    new at_pos = strfind(email, "@", true);
    if(at_pos >= 1)
    {
        new offset = (at_pos + 1), dot_pos = strfind(email, ".", true, offset), domain;
		if(strlen(email) > dot_pos + 1){
			for(new i = dot_pos+1; i<strlen(email); i++){
				if(sscanf(email[i], "c", domain)) return 0;
			}
			if(dot_pos > offset)
			{
				return 1;
			}
		}
    }
    return 0;
}*/
IsValidEmailAddress(const email[]){
	new at_pos = strfind(email, "@");
	if(at_pos >= 1){
		new offset = (at_pos + 1), dot_pos = strfind(email, ".", true ,offset), string[95];
		format(string, sizeof(string), email);
		strdel(string, 0, dot_pos+1);
		if(dot_pos > offset && strlen(string) >= 1){
			for(new i; i<strlen(string); i++){
				switch(string[i]){
					case 'A'..'Z', 'a'..'z':{
						continue;
					}
					case '.':{
						if(i >= 1) continue;
						return 0;
					}
					default:{
						return 0;
					}
				}
			}
			return 1;
		}
		return 0;
	}
	return 0;
}
public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}
