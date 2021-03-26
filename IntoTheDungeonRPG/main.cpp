#include<iostream>
#include <random>
#include<vector>
#include <algorithm>
#include <Windows.h>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

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

void Show_Status(_tagPlayer tPlayer) {
	while (1) {
		system("cls");
		Logo();
		int iMenu = 0;
		cout << tPlayer.strName << "의 스텟" << endl;
		cout << "HP :" << "[" << tPlayer.iHP << "/" << tPlayer.iHPMax << "]" << endl;
		cout << "MP :" << "[" << tPlayer.iMP << "/" << tPlayer.iMPMax << "]" << endl;
		cout << "공격력 :" << "[" << tPlayer.iAttackMin << "-" << tPlayer.iAttackMax << "]" << endl;
		cout << "방어력 :" << "[" << tPlayer.iArmorMin << "-" << tPlayer.iArmorMax << "]" << endl;
		cout << "EXP :" << "[" << tPlayer.iExp << "]" << endl;
		cout << "0. 뒤로가기" << endl;
		cout << "번호를 입력해주세요 : ";
		cin >> iMenu;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == 0) {
			break;
		}

	}
}

void EnemyMaker(_tagMonster* Monsters) {
	//
	Monsters[0].strName = "고블린";
	Monsters[0].iAttackMin = 20;
	Monsters[0].iAttackMax = 30;
	Monsters[0].iArmorMin = 2;
	Monsters[0].iArmorMax = 5;
	Monsters[0].iHPMax = 100;
	Monsters[0].iHP = Monsters[0].iHPMax;
	Monsters[0].iMPMax = 10;
	Monsters[0].iMP = Monsters[0].iMPMax;
	Monsters[0].iExp = 1000;
	Monsters[0].iGoldMin = 500;
	Monsters[0].iLevel = 1;
	Monsters[0].iGoldMax = 1500;

	//
	Monsters[1].strName = "트롤";
	Monsters[1].iAttackMin = 80;
	Monsters[1].iAttackMax = 130;
	Monsters[1].iArmorMin = 60;
	Monsters[1].iArmorMax = 90;
	Monsters[1].iHPMax = 2000;
	Monsters[1].iHP = Monsters[0].iHPMax;
	Monsters[1].iMPMax = 100;
	Monsters[1].iMP = Monsters[0].iMPMax;
	Monsters[1].iExp = 7000;
	Monsters[1].iGoldMin = 6000;
	Monsters[1].iGoldMax = 8000;
	Monsters[1].iLevel = 5;

	//
	Monsters[2].strName = "드래곤";
	Monsters[2].iAttackMin = 250;
	Monsters[2].iAttackMax = 500;
	Monsters[2].iArmorMin = 200;
	Monsters[2].iArmorMax = 400;
	Monsters[2].iHPMax = 30000;
	Monsters[2].iHP = Monsters[0].iHPMax;
	Monsters[2].iMPMax = 2000;
	Monsters[2].iMP = Monsters[0].iMPMax;
	Monsters[2].iExp = 30000;
	Monsters[2].iGoldMin = 20000;
	Monsters[2].iGoldMax = 50000;
	Monsters[2].iLevel = 10;
}

int main() {
	system(" mode  con lines=50   cols=110 ");

	//로비 생성

	//const char msgWelcome[] =
	//    "              *******************************************************\n\r"
	//    "              *                                                     *\n\r"
	//    "              *                   IntoTheDungeon                    *\n\r"
	//    "              *                                                     *\n\r"
	//    "              *******************************************************\n\r";

	while (1) {
		system("cls");
		Logo();
		MainPic();
		cout.setf(ios::left);
		cout << "1. 게임 시작" << endl;
		cout << "2. 게임 종료" << endl;
		cout << "메뉴를 입력해주세요 : ";
		int iMenu;

		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == 2) {
			break;
		}

		if (iMenu == 1) {
			//게임 시작시 플레이어 정보 저장
			system("cls");
			Logo();

			_tagPlayer tPlayer = {};
			if (tPlayer.strName.size() == 0) {
				cout << "이름을 입력해주세요 : ";
				/*getline(cin,tPlayer.strName);*/
				cin >> tPlayer.strName;
			}
			int iJob = JOB_NONE;

			while (1) {
				system("cls");
				Logo();

				while (iJob == JOB_NONE) {
					system("cls");
					Logo();
					cout << "1. 기사" << endl;
					cout << "2. 마법사" << endl;
					cout << "3. 궁수" << endl;
					cout << "4. 도적" << endl;

					cout << "직업을 선택하세요 :";
					cin >> iJob;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iJob <= JOB_NONE || iJob >= JOB_END) {
						iJob = JOB_NONE;
					}
					tPlayer.iLevel = 1;
					tPlayer.iExp = 0;
					tPlayer.ejob = (JOB)iJob;
					switch (tPlayer.ejob)
					{
					case JOB_KNIGHT:
						tPlayer.JobName = "기사";

						tPlayer.iAttackMin = 5;
						tPlayer.iAttackMax = 10;

						tPlayer.iArmorMin = 15;
						tPlayer.iArmorMax = 20;

						tPlayer.iHPMax = 500;
						tPlayer.iHP = tPlayer.iHPMax;
						tPlayer.iMPMax = 100;
						tPlayer.iMP = tPlayer.iMPMax;
						break;
					case JOB_WIZARD:
						tPlayer.JobName = "마법사";
						tPlayer.iAttackMin = 15;
						tPlayer.iAttackMax = 20;

						tPlayer.iArmorMin = 5;
						tPlayer.iArmorMax = 10;

						tPlayer.iHPMax = 300;
						tPlayer.iHP = tPlayer.iHPMax;
						tPlayer.iMPMax = 300;
						tPlayer.iMP = tPlayer.iMPMax;
						break;
					case JOB_ARCHER:
						tPlayer.JobName = "궁수";
						tPlayer.iAttackMin = 10;
						tPlayer.iAttackMax = 15;

						tPlayer.iArmorMin = 10;
						tPlayer.iArmorMax = 15;

						tPlayer.iHPMax = 400;
						tPlayer.iHP = tPlayer.iHPMax;
						tPlayer.iMPMax = 200;
						tPlayer.iMP = tPlayer.iMPMax;
						break;
					case JOB_ROGUE:
						tPlayer.JobName = "도적";
						tPlayer.iAttackMin = 20;
						tPlayer.iAttackMax = 25;

						tPlayer.iArmorMin = 5;
						tPlayer.iArmorMax = 10;

						tPlayer.iHPMax = 400;
						tPlayer.iHP = tPlayer.iHPMax;
						tPlayer.iMPMax = 150;
						tPlayer.iMP = tPlayer.iMPMax;
						break;
					default:
						break;
					}
				}

				_tagMonster Monsters[MT_BACK - 1];
				EnemyMaker(Monsters);


				system("cls");
				Logo();

				cout << "0. 튜토리얼" << endl;
				cout << "1. 맵" << endl;
				cout << "2. 상점" << endl;
				cout << "3. 가방" << endl;
				cout << "4. 스텟" << endl;
				cout << "5. 시작메뉴로" << endl;
				cout << "메뉴를 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == MM_EXIT) {
					break;
				}

				switch (iMenu)
				{
				case MM_NONE:
					while (1) {
						system("cls");
						Logo();
						cout << "튜토리얼에 오신걸 환영합니다!" << endl;

						cout << "1. 게임 진행" << endl;
						cout << "2. 전투" << endl;
						cout << "3. 아이템" << endl;
						cout << "4. 뒤로가기" << endl;
						cout << "번호를 선택하세요 : ";

						cin >> iMenu;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						if (iMenu == MT_BACK) {
							break;
						}
					}
					break;
				case MM_MAP:
					while (1) {
						system("cls");
						Logo();
						cout << "1. 쉬움" << endl;
						cout << "2. 보통" << endl;
						cout << "3. 어려움" << endl;
						cout << "4. 뒤로가기" << endl;
						cout << "맵을 선택하세요 : ";
						cin >> iMenu;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						if (iMenu == MT_BACK) {
							break;
						}
					}

					break;
				case MM_STORE:
					break;
				case MM_INVENTORY:
					break;
				case MM_STAT:
					Show_Status(tPlayer);
					break;
				default:
					cout << "잘못 선택하였습니다." << endl;
					break;
				}
			}
		}
	}


	return 0;
}