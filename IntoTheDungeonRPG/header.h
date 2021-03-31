#pragma once

#include<iostream>
#include <random>
#include<vector>
#include <algorithm>
#include <Windows.h>
#include<iomanip>
#include<fstream>
#include<string>

void Logo() {
	cout << "==============================================================================================================" << endl;
	cout << " _____   _   _   _____   _____   _____   _   _   _____   _____   _   _   _   _   _____   _____   _____   _   _" << endl;
	cout << "|_   _| | \\ | | |_   _| |  _  | |_   _| | | | | |  ___| |  _  \\\ | | | | | \\\ | | |  __ \\\ | ___| |  _  | | \\\ | |" << endl;
	cout << "  | |   |  \\| |   | |   | | | |   | |   | |_| | | |__   | | | | | | | | |  \\\| | | |  \\\/ | |__  | | | | |  \\\| |" << endl;
	cout << "  | |   | . ` |   | |   | | | |   | |   |  _  | |  __|  | | | | | | | | | . ` | | | __  |  __| | | | | | . ` |" << endl;
	cout << "  | |_  | |\\  |   | |   \\ \\_/ /   | |   | | | | | |___  | |/ /  | |_| | | |\\\  | | |_\\\ \\\ | |___ \\\ \\\_/ / | | \\\ |" << endl;
	cout << " \\___/  \\_| \\_/   \\_/    \\___/    \\_/   \\_| |_/ \\____/  |___/    \\___/  \\_| \\_/  \\____/ \\____/  \\___/  \\_| \\_/" << endl;
	cout << endl;
	cout << "==============================================================================================================" << endl;
}

void MainPic() {
	const char pic[] =
		"                    ..                                              \n\r"
		"                      ++`                                            \n\r"
		"                       :ho.        `.-/++/.                          \n\r"
		"                        `/hh+.         ``:sds:                       \n\r"
		"                          `-odds/-`        .MNd/`                    \n\r"
		"                             `.+ydmdyo/:--/yMMMMd/                   \n\r"
		"                                `:+hMMMNNNMMMddNMMh:`                \n\r"
		"                   `-:/+++/:-:ohmNMMMMMMMMMMMm+-+mMNd`               \n\r"
		"                `-+oo+osdMMMNMMMMMMMMMMMMMMMMMMNmNMMM/`              \n\r"
		"                ```   .+mMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmho:.`         \n\r"
		"                    `omMMMMMMMMMMMMMMMMMMNMdydMMdNMMMMMMMMdo+-       \n\r"
		"                .:oymMMMMMMMMMMMMMNdo/hMMd+ds-:h/-yMdydMNdNdNN+      \n\r"
		"              -oosdMMMMMMMMMMMMMMd:`  `yMM+.+h+.-  /y `/m.:mmmN      \n\r"
		"             -:`  dMMMMMMMMMMMMMd.     `mMNo..+y/`  .   .  -/.s      \n\r"
		"             `   -MMMMMMMMMMMMMM-       -mMMmo-./s/.`         `      \n\r"
		"                `+MMMMMMMMMMMMMM-        .smMy:.``-+oo+//:-.`        \n\r"
		"               .yNMMMMMMMMMMMMMMd.         .+dmh+:.  `-::/+:.        \n\r"
		"               y+-mMMMMMMMMMMMMMMm/`          ./o+-`       .         \n\r"
		"              :-  :MMMMMMMMMMMMMMMMmy/.`                             \n\r"
		"              `   `hMMMMMMMMMMMMMMMMMMNds/.`                         \n\r"
		"                  sNhNMMMMMMMMMMMMMMMMMMMMNh+.                       \n\r"
		"                 -d. :mMMMMMMMMMMMMMMMMMMMMMMNh:`                    \n\r"
		"                 /.   .hMMMMMMMMMMMMMMMMMMMMMMMMh.                   \n\r"
		"                 .     `sMMMMMMMMMMMMMMMMMMMMMMMMN.                  \n\r"
		"                         hMMMMMMMMMMMMMMMMMMMMMMMMy                  \n\r"
		"                         +MMMMMMMMMMMMMMMMMMMMMMMMh                      ";

	cout << setw(100) << pic << endl;
}


int Random_Value(int min, int max) {

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> dis(min, max);

	return dis(gen);
}

enum MAIN_MENU {
	MM_NONE = 0,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_STAT,
	MM_EXIT
};

enum MAP_TYPE {
	MT_NONE = 0,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB
{
	JOB_NONE = 0,
	JOB_KNIGHT,
	JOB_WIZARD,
	JOB_ARCHER,
	JOB_ROGUE,
	JOB_END
};

enum BATTLE
{
	BATTLE_NONE = 0,
	BATTLE_FIGHT,
	BATTLE_RUN
};

enum ITEM_TYPE {
	IT_NONE = 0,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK,
};

struct _tagItem {

	string strName;
	string strTypeName;

	ITEM_TYPE eType;
	int iMin;
	int iMax;
	int iPrice;
	int iSell;

	string Description;
};

#define MAX_INVENTORY 20
#define STORE_ARMOR_MAX 3
#define STORE_WEAPON_MAX 3

struct _tagInvcentory
{
	_tagItem tItems[MAX_INVENTORY];
	int iGold;
	int iItemCount = 0;
};

enum STORE_MENU {
	SM_NONE = 0,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK,
};

enum IN_MENU {
	IN_NONE = 0,
	IN_EQUIP,
	IN_BACK,
};

struct _tagPlayer
{
	string strName;
	string JobName;
	JOB ejob;

	int iAttackMin;
	int iAttackMax;

	int iArmorMin;
	int iArmorMax;

	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;

	int iExp;
	int iLevel;

	_tagInvcentory iInventory;
};

struct _tagMonster
{
	string strName;

	int iAttackMin;
	int iAttackMax;

	int iArmorMin;
	int iArmorMax;

	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;

	int iLevel;

	int iExp;

	int iGoldMin;
	int iGoldMax;
};
