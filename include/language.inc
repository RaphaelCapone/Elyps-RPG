/*  language.inc
 *
 *  (c) Copyright 2012, Emilijo "Correlli" Lovrich
 *
 *  Credits: - Incognito for GVar plugin,
			 - whoever created StripNewLine (DracoBlue?) & SplitChar functions.
*/

#if !defined MAX_LANGUAGES
	#define MAX_LANGUAGES (3)
#endif

new
		FALSE = 0;

#define SendLanguageMessageEx(%0,%1,%2,%3) \
do \
{ \
	new \
			_string[128]; \
	if(strlen(%2) > 0) \
	{ \
		format(_string, 128, "%s", GetLanguageKey(GetPlayerLanguage(%0), %2)); \
		format(_string, 128, _string, %3); \
		SendClientMessage(%0, %1, _string); \
	} \
} \
while(FALSE)

#define SendLanguageMessageToAllEx(%0,%1,%2) \
do \
{ \
	new \
			_string[128]; \
	if(strlen(%1) > 0) \
	{ \
		foreach(new x : Player) \
		{ \
			format(_string, 128, "%s", GetLanguageKey(GetPlayerLanguage(x), %1)); \
			format(_string, 128, _string, %2); \
			SendClientMessage(x, %0, _string); \
		} \
	} \
} \
while(FALSE)

#define LoadLanguage(%0) LoadLanguageTexts(%0)

new
		languageID = -1;

/* ----- */

stock SetPlayerLanguage(playerid, langname[])
{
	new
			File:langFile = fopen(LanguageFile(langname), io_read);
	if(!langFile)
	{
		SetPVarString(playerid, "Player_Language", "English");
		return printf("Error: File for language \"%s\" doesn't exist, setting the default language (English)!", langname);
	}
	fclose(langFile);
	new
			string[24];
	format(string, 24, "%s", langname);
	return SetPVarString(playerid, "Player_Language", string);
}

stock GetPlayerLanguage(playerid)
{
	new
			langname[24];
	GetPVarString(playerid, "Player_Language", langname, 24);
	return langname;
}

stock SendLanguageMessage(playerid, color, langkey[])
	return SendClientMessage(playerid, color, GetLanguageKey(GetPlayerLanguage(playerid), langkey));

stock SendLanguageMessageToAll(color, langkey[])
{
	foreach(new u : Player)
		SendLanguageMessage(u, color, langkey);
	return true;
}

stock LoadLanguageTexts(langname[])
{
	languageID++;
	if(languageID == MAX_LANGUAGES)
	{
		languageID--;
		return printf("Error: Limit of languages exceeded. Open the language.inc and change the \"MAX_LANGUAGES\" define to bigger value if you want to have more languages.");
	}
	if(strlen(langname) > 24)
	{
		languageID--;
		return printf("Error: Name of language \"%s\" is too long, name limit is 24 characters!", langname);
	}
	new
			File:langFile = fopen(LanguageFile(langname), io_read);
	if(!langFile)
	{
		languageID--;
		return printf("Error: File for language \"%s\" doesn't exist!", langname);
	}
	new
			string[128 + 24 + 2], data[2][128];
	while(fread(langFile, string))
	{
		StripNewLine(string);
		if(strlen(string) != 0)
		{
			SplitChar(string, data, '=');
			format(data[0], 50, "%s_%s", langname, data[0]);
			SetGVarString(data[0], data[1]);
		}
	}
	fclose(langFile);
	return true;
}

stock GetLanguageKey(langname[], langkey[])
{
	new
			string[128];
	format(string, 50, "%s_%s", langname, langkey);
	GetGVarString(string, string, 128);
	return string;
}

stock LanguageFile(langname[])
{
	new
			path[42];
	format(path, 42, "languages/%s.lng", langname);
	return path;
}

/* ----- */

stock StripNewLine(string[])
{
	new
			strLength = strlen(string);
	if(!string[0]) return;
	if(string[strLength - 1] == '\n' || string[strLength - 1] == '\r')
	{
		string[strLength - 1] = 0;
		if(!string[0]) return;
		if(string[strLength - 2] == '\n' || string[strLength - 2] == '\r') string[strLength - 2] = 0;
	}
}

stock SplitChar(const strsrc[], strdest[][], delimiter)
{
	new
			i, li, aNum, len;
	while(i <= strlen(strsrc))
	{
		if(strsrc[i] == delimiter || i == strlen(strsrc))
		{
			len = strmid(strdest[aNum], strsrc, li, i, 128);
			strdest[aNum][len] = 0;
			li = i + 1;
			aNum++;
		}
		i++;
	}
	return true;
}
