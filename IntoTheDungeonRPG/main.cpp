#include<iostream>
#include <random>
#include<vector>
#include <algorithm>
#include <Windows.h>
#include<iomanip>

using namespace std;

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
	MM_EXIT
};

enum MAP_TYPE {
	MT_NONE = 0,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

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

	cout <<setw(100)<<pic << endl;
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
			while (1) {

				system("cls");
				Logo();

				cout << "0. Ʃ�丮��" << endl;
				cout << "1. ��" << endl;
				cout << "2. ����" << endl;
				cout << "3. ����" << endl;
				cout << "4. ���۸޴���" << endl;
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
					while (1) {
						system("cls");
						Logo();
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
					}

					break;
				case MM_STORE:
					break;
				case MM_INVENTORY:
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