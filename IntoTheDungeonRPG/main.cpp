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
	int iItemCount;
};

enum STORE_MENU {
	SM_NONE = 0,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK,
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

void Show_Status(_tagPlayer tPlayer) {
	while (1) {
		system("cls");
		Logo();
		int iMenu = 0;
		cout << tPlayer.strName << "�� ����" << endl;
		cout << "HP :" << "[" << tPlayer.iHP << "/" << tPlayer.iHPMax << "]" << endl;
		cout << "MP :" << "[" << tPlayer.iMP << "/" << tPlayer.iMPMax << "]" << endl;
		cout << "���ݷ� :" << "[" << tPlayer.iAttackMin << "-" << tPlayer.iAttackMax << "]" << endl;
		cout << "���� :" << "[" << tPlayer.iArmorMin << "-" << tPlayer.iArmorMax << "]" << endl;
		cout << "EXP :" << "[" << tPlayer.iExp << "]" << endl;
		cout << "Gold : " << tPlayer.iInventory.iGold << "G" << endl;
		cout << "0. �ڷΰ���" << endl;
		cout << "��ȣ�� �Է����ּ��� : ";
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
	Monsters[0].strName = "���";
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
	Monsters[1].strName = "Ʈ��";
	Monsters[1].iAttackMin = 80;
	Monsters[1].iAttackMax = 130;
	Monsters[1].iArmorMin = 60;
	Monsters[1].iArmorMax = 90;
	Monsters[1].iHPMax = 2000;
	Monsters[1].iHP = Monsters[1].iHPMax;
	Monsters[1].iMPMax = 100;
	Monsters[1].iMP = Monsters[1].iMPMax;
	Monsters[1].iExp = 7000;
	Monsters[1].iGoldMin = 6000;
	Monsters[1].iGoldMax = 8000;
	Monsters[1].iLevel = 5;

	//
	Monsters[2].strName = "�巡��";
	Monsters[2].iAttackMin = 250;
	Monsters[2].iAttackMax = 500;
	Monsters[2].iArmorMin = 200;
	Monsters[2].iArmorMax = 400;
	Monsters[2].iHPMax = 30000;
	Monsters[2].iHP = Monsters[2].iHPMax;
	Monsters[2].iMPMax = 2000;
	Monsters[2].iMP = Monsters[2].iMPMax;
	Monsters[2].iExp = 30000;
	Monsters[2].iGoldMin = 20000;
	Monsters[2].iGoldMax = 50000;
	Monsters[2].iLevel = 10;
}

void Menu_Map(_tagPlayer tPlayer) {
	_tagMonster Monsters[MT_BACK - 1];
	EnemyMaker(Monsters);

	int iMenu;

	while (1) {
		system("cls");
		Logo();
		cout << "************************��**************************" << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �����" << endl;
		cout << "4. �ڷΰ���" << endl;
		cout << "���� �����ϼ��� : ";
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MT_BACK) {
			break;
		}

		_tagMonster tEnemy = Monsters[iMenu - 1];

		while (1)
		{
			system("cls");
			switch (iMenu) {
			case MT_EASY:
				cout << "***********************����***************************" << endl;
				break;
			case MT_NORMAL:
				cout << "***********************����***************************" << endl;
				break;
			case MT_HARD:
				cout << "***********************�����***************************" << endl;
				break;
			}
			cout << endl;
			/*�÷��̾��� Stat*/
			cout << "====================== Player ======================" << endl;
			cout << "�̸� : " << tPlayer.strName << "\t" << "���� : " << tPlayer.JobName << endl;
			cout << "���� : " << tPlayer.iLevel << "\t" << "����ġ : " << tPlayer.iExp << endl;
			cout << "���ݷ� : " << tPlayer.iAttackMin << "-" << tPlayer.iAttackMax << "\t" << "���� : " << tPlayer.iArmorMin << "-" << tPlayer.iArmorMax << endl;
			cout << "ü�� : " << tPlayer.iHP << "/" << tPlayer.iHPMax << "\t" << "���� : " << tPlayer.iMP << "/" << tPlayer.iMPMax << endl;
			cout << "������� : " << tPlayer.iInventory.iGold << "G" << endl;

			cout << endl;

			cout << "====================== Monster ======================" << endl;
			cout << "�̸� : " << tEnemy.strName << "\t" << "���� : " << tEnemy.iLevel << endl;
			cout << "���ݷ� : " << tEnemy.iAttackMin << "-" << tEnemy.iAttackMax << "\t" << "���� : " << tEnemy.iArmorMin << "-" << tEnemy.iArmorMax << endl;
			cout << "ü�� : " << tEnemy.iHP << "/" << tEnemy.iHPMax << "\t" << "���� : " << tEnemy.iMP << "/" << tEnemy.iMPMax << endl;
			cout << "ȹ�� ����ġ : " << tEnemy.iExp << "\t" << "ȹ�� ��� : " << tEnemy.iGoldMin << "-" << tEnemy.iGoldMax << endl;


			cout << "1. ����" << endl;
			cout << "2. ��������" << endl;
			cout << "�޴��� �����ϼ��� : ";
			cin >> iMenu;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			else if (iMenu == BATTLE_RUN) {
				break;
			}

			switch (iMenu)
			{
			case BATTLE_FIGHT:
				int iAttack = Random_Value(tPlayer.iAttackMin, tPlayer.iAttackMax);
				int iArmor = Random_Value(tEnemy.iArmorMin, tEnemy.iArmorMax);

				int iDamage = iAttack - iArmor < 1 ? 1 : iAttack - iArmor;

				//������ ����
				tEnemy.iHP -= iDamage;
				cout << tPlayer.strName << "��(��)" << tEnemy.strName << "����" << iDamage << "�� ���ظ� �������ϴ�" << endl;
				if (tEnemy.iHP <= 0) {
					cout << tEnemy.strName << " ���" << endl;

					tPlayer.iExp += tEnemy.iExp;
					int iGold = Random_Value(tEnemy.iGoldMin, tEnemy.iGoldMax);
					tPlayer.iInventory.iGold += iGold;

					cout << tEnemy.iExp << "��ŭ ����ġ�� ȹ���߽��ϴ�!" << endl;
					cout << iGold << "��ŭ ��带 ȹ���߽��ϴ�!" << endl;
					system("pause");

					tEnemy.iHP = tEnemy.iHPMax;
					tEnemy.iMP = tEnemy.iMPMax;

					break;
				}

				//���Ͱ� ���� ���� ��� ����
				iAttack = Random_Value(tEnemy.iAttackMin, tEnemy.iAttackMax);
				iArmor = Random_Value(tPlayer.iArmorMin, tPlayer.iArmorMax);

				iDamage = iAttack - iArmor < 1 ? 1 : iAttack - iArmor;

				//������ ����
				tPlayer.iHP -= iDamage;
				cout << tEnemy.strName << "��(��)" << tPlayer.strName << "����" << iDamage << "�� ���ظ� �������ϴ�" << endl;
				if (tPlayer.iHP <= 0) {
					cout << tPlayer.strName << "�� ����Ͽ����ϴ�." << endl;

					int lGold = tPlayer.iInventory.iGold * 0.1f;
					int lExp = tPlayer.iExp * 0.1f;

					tPlayer.iInventory.iGold -= lGold;
					tPlayer.iExp -= lExp;

					cout << lExp << "��ŭ ����ġ�� �Ҿ����ϴ�!" << endl;
					cout << lGold << "��ŭ ��带 �Ҿ����ϴ�!" << endl;

					tPlayer.iHP = tPlayer.iHPMax;
					tPlayer.iMP = tPlayer.iMPMax;
				}
				system("pause");
				break;
			}


		}
	}

}

void SetStoreItems(_tagItem *tStoreWeapon, _tagItem *tStoreArmor) {
	tStoreWeapon[0].strName = "���̾� �ҵ�";
	tStoreWeapon[0].strTypeName = "����";
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 10;
	tStoreWeapon[0].iMax = 15;
	tStoreWeapon[0].iPrice = 200;

}


void Menu_Store(_tagPlayer tPlayer, _tagItem *tStoreWeapon, _tagItem *tStoreArmor) {
	int iMenu = 0;

	while (1) {
		system("cls");
		Logo();
		cout << "*****************����*******************" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. �� ����" << endl;
		cout << "3. �ڷΰ���" << endl;
		cout << "������ �����ϼ��� : ";
		cin >> iMenu;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iMenu == SM_BACK) {
			break;
		}

		switch (iMenu) {
		case SM_WEAPON:
			while (1) {
				system("cls");
				Logo();
				cout << "****************���� ����*******************" << endl;
				//�Ǹ� ����� �����ش�

			}
			break;
		case SM_ARMOR:
			break;
		}

	}
}

int main() {
	system(" mode  con lines=50   cols=110 ");

	//�κ� ����

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
		cout << "1. ���� ����" << endl;
		cout << "2. ���� ����" << endl;
		cout << "�޴��� �Է����ּ��� : ";
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
			//���� ���۽� �÷��̾� ���� ����
			system("cls");
			Logo();

			_tagPlayer tPlayer = {};
			if (tPlayer.strName.size() == 0) {
				cout << "�̸��� �Է����ּ��� : ";
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
					cout << "1. ���" << endl;
					cout << "2. ������" << endl;
					cout << "3. �ü�" << endl;
					cout << "4. ����" << endl;

					cout << "������ �����ϼ��� :";
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
					tPlayer.iInventory.iGold = 100;

					switch (tPlayer.ejob)
					{
					case JOB_KNIGHT:
						tPlayer.JobName = "���";

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
						tPlayer.JobName = "������";
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
						tPlayer.JobName = "�ü�";
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
						tPlayer.JobName = "����";
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


				system("cls");
				Logo();

				/*������ ����*/
				_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
				_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

				SetStoreItems(tStoreWeapon, tStoreArmor);
				

				//�κ�
				cout << "0. Ʃ�丮��" << endl;
				cout << "1. ��" << endl;
				cout << "2. ����" << endl;
				cout << "3. ����" << endl;
				cout << "4. ����" << endl;
				cout << "5. ���۸޴���" << endl;
				cout << "�޴��� �����ϼ��� : ";
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
						cout << "Ʃ�丮�� ���Ű� ȯ���մϴ�!" << endl;

						cout << "1. ���� ����" << endl;
						cout << "2. ����" << endl;
						cout << "3. ������" << endl;
						cout << "4. �ڷΰ���" << endl;
						cout << "��ȣ�� �����ϼ��� : ";

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
					Menu_Map(tPlayer);
					break;
				case MM_STORE:
					Menu_Store(tPlayer, tStoreWeapon, tStoreArmor);
					break;
				case MM_INVENTORY:
					break;
				case MM_STAT:
					Show_Status(tPlayer);
					break;
				default:
					cout << "�߸� �����Ͽ����ϴ�." << endl;
					break;
				}
			}
		}
	}


	return 0;
}