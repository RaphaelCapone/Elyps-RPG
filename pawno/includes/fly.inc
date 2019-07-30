// =======================================================================================
// fly.inc
//
// Author: Norck
//
// msn:         paul_norck@hotmail.com
// icq:         44-055-21
// skype:       paul_norck
//
// Credits: Creator of SetPlayerLookAt function. Sorry, I can't remember their name
//
// you are allowed to edit this script
// you are not allowed to sell this script
//
// Please, don't remove the credits
// =======================================================================================
 
static bool:OnFly[MAX_PLAYERS];
static Float:flySpeed[MAX_PLAYERS];
static Float:flyZAngle[MAX_PLAYERS];
static playerIsInVehicle[MAX_PLAYERS];
forward InitFly(playerid);
forward bool:StartFly(playerid);
forward Fly(playerid);
forward bool:StopFly(playerid);
 
InitFly(playerid)
{
    OnFly[playerid] = false;
    flySpeed[playerid] = 1.024;
    return true;
}
bool:StartFly(playerid)
{
    if(OnFly[playerid]) return false;
 
    if(IsPlayerInAnyVehicle(playerid))
        playerIsInVehicle[playerid] = true;
    else
        ApplyAnimation(playerid,"PARACHUTE","FALL_SkyDive_Accel",6.1,1,1,1,1,0,1);
    OnFly[playerid] = true;
    Fly(playerid);
    return true;
}
bool:StopFly(playerid)
{
    if(!OnFly[playerid]) return false;
 
    OnFly[playerid] = false;
    SetPlayerHealth(playerid,100.0);
    if(playerIsInVehicle[playerid])
        SetVehicleHealth(GetPlayerVehicleID(playerid),1000.0);
    else
        ClearAnimations(playerid);
    playerIsInVehicle[playerid] = false;
    return true;
}
public Fly(playerid)
{
    if(!IsPlayerConnected(playerid)) return 1;
    if(!OnFly[playerid]) return 1;
    if(IsPlayerInAnyVehicle(playerid) ^ playerIsInVehicle[playerid]) return StopFly(playerid);
 
    new k,ud,lr;
    new Float:v_x,Float:v_y,Float:v_z;
    GetPlayerKeys(playerid,k,ud,lr);
    if(ud < 0)
    {
        GetPlayerCameraFrontVector(playerid,v_x,v_y,v_z);
        v_x = v_x*flySpeed[playerid];
        v_y = v_y*flySpeed[playerid];
        if(v_x == 0.0)
            v_x = v_x+0.001;
        flyZAngle[playerid] = atan(v_y/v_x)-90.0;
        if(v_x < 0)
            flyZAngle[playerid] = flyZAngle[playerid]+180.0;
        if(playerIsInVehicle[playerid])
            SetVehicleHealth(GetPlayerVehicleID(playerid),99999.0);
        else
        {
            SetPlayerHealth(playerid,99999.0);
            SetPlayerFacingAngle(playerid,flyZAngle[playerid]);
            if(GetPlayerAnimationIndex(playerid) != 959)
                ApplyAnimation(playerid,"PARACHUTE","FALL_SkyDive_Accel",6.1,1,1,1,1,0,1);
        }
    }
    if(k & KEY_ANALOG_LEFT)
        flySpeed[playerid] = flySpeed[playerid]/2;
    else if(k & KEY_ANALOG_RIGHT)
        flySpeed[playerid] = flySpeed[playerid]*2;
    if(flySpeed[playerid] > 20.0)
        flySpeed[playerid] = 20.0;
    if(lr < 0)     // down
        v_z = -0.5*flySpeed[playerid];
    else if(lr > 0)   // up
        v_z = 0.5*flySpeed[playerid];
    else
        v_z = 0.025;
    if(playerIsInVehicle[playerid])
    {
        SetVehicleVelocity(GetPlayerVehicleID(playerid),v_x,v_y,v_z);
        SetVehicleZAngle(GetPlayerVehicleID(playerid),flyZAngle[playerid]);
    }
    else
    {
        SetPlayerVelocity(playerid,v_x,v_y,v_z);
        if(v_x == 0 && v_y == 0)
            if(GetPlayerAnimationIndex(playerid) == 959)
                ApplyAnimation(playerid,"PARACHUTE","PARA_steerR",6.1,1,1,1,1,0,1);
    }
    SetTimerEx("Fly",100,false,"i",playerid);
    return 1;
}