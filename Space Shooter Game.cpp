#include <iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

void Welcome()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t PF - F i n a l    P r o j e c t\n";
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\t\t _____                    _____ _           _           \n";
	cout << "\t\t\t\t\t\t\t|   __|___ ___ ___ ___   |   __| |_ ___ ___| |_ ___ ___ \n";
	cout << "\t\t\t\t\t\t\t|__   | . | .'|  _| -_|  |__   |   | . | . |  _| -_|  _|\n";
	cout << "\t\t\t\t\t\t\t|_____|  _|__,|___|___|  |_____|_|_|___|___|_| |___|_|  \n";
	cout << "\t\t\t\t\t\t\t      |_|\n";
	system("COLOR 06"); system("COLOR 07"); system("COLOR 08"); system("COLOR 03"); system("COLOR 05"); system("COLOR 04");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
}

void game() {

	int temp = 0;
	system("COLOR 03");
	while (temp == 0) {

		char arr[200][200];
		char level = '1', lives = '3', controls, bulletx = 22, bullety = 24, score = '0', selection;
		int alienscol = 24, aliensrow = 1, alienscollvl2 = alienscol + 5, aliensrowlvl2 = 1;
		;
		int temp = 0, temp1;

		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 70; j++) {
				if (i != 0 && i != 24 && j != 0 && j != 69 && j != 50 && i != 10 && i != 16) {
					arr[i][j] = ' ';
				}
				else {
					arr[i][j] = (char)219;
				}
				if ((i == 10 || i == 16) && j > 0 && j < 50) {
					arr[i][j] = ' ';
				}
			}
		}

		// Info Screen
		arr[4][57] = 'S';
		arr[4][58] = 'P';
		arr[4][59] = 'A';
		arr[4][60] = 'C';
		arr[4][61] = 'E';

		arr[6][56] = 'S';
		arr[6][57] = 'H';
		arr[6][58] = 'O';
		arr[6][59] = 'O';
		arr[6][60] = 'T';
		arr[6][61] = 'E';
		arr[6][62] = 'R';

		arr[13][56] = 'L';
		arr[13][57] = 'e';
		arr[13][58] = 'v';
		arr[13][59] = 'e';
		arr[13][60] = 'l';
		arr[13][61] = ':';

		arr[13][63] = level;

		arr[19][56] = 'S';
		arr[19][57] = 'c';
		arr[19][58] = 'o';
		arr[19][59] = 'r';
		arr[19][60] = 'e';
		arr[19][61] = ':';

		arr[19][63] = score;

		arr[21][56] = 'L';
		arr[21][57] = 'i';
		arr[21][58] = 'v';
		arr[21][59] = 'e';
		arr[21][60] = 's';
		arr[21][61] = ':';

		arr[21][63] = lives;

		arr[23][24] = (char)207;

		for (int shipy = 24; lives != '0' && level != '3';) {

			arr[13][63] = level;
			arr[21][63] = lives;
			arr[19][63] = score;

			for (int i = 0; i < 25; i++) {
				for (int j = 0; j < 70; j++) {
					cout << arr[i][j];
				}
				cout << endl;
			}
			if (level == '1') {

				if (alienscol > 0 && alienscol < 50 && aliensrow <= 23) {
					if (aliensrow != 1) {
						arr[aliensrow - 1][alienscol] = ' ';
					}
					if (aliensrow != 23) {
						arr[aliensrow][alienscol] = (char)254;
					}
					else {
						aliensrow = 1;
						lives = lives - 1;
					}
					aliensrow++;
				}
			}

			if (temp == 1 && level != '1') {
				aliensrow == 1;
				aliensrowlvl2 == 1;
				temp++;
			}

			if (level == '2') {
				if (alienscol > 0 && alienscol < 50 && aliensrow <= 23) {
					if (aliensrow != 1) {
						arr[aliensrow - 1][alienscol] = ' ';
					}
					if (aliensrow != 23) {
						arr[aliensrow][alienscol] = (char)254;
					}
					else {
						aliensrow = 1;
						lives = lives - 1;
					}
					aliensrow++;
				}

				if (alienscollvl2 > 0 && alienscollvl2 < 50 && aliensrowlvl2 <= 23) {
					if (aliensrowlvl2 != 1) {
						arr[aliensrowlvl2 - 1][alienscollvl2] = ' ';
					}
					if (aliensrowlvl2 != 23) {
						arr[aliensrowlvl2][alienscollvl2] = (char)254;
					}
					else {
						aliensrowlvl2 = 1;
						lives = lives - 1;
					}
					aliensrowlvl2++;
				}
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

			if (_kbhit()) {
				controls = _getch();

				bullety = shipy;

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

				if (controls == 'a' && shipy > 1) {
					arr[23][shipy] = ' ';
					shipy--;
					arr[23][shipy] = (char)207;
				}
				else if (controls == 'd' && shipy < 49) {
					arr[23][shipy] = ' ';
					shipy++;
					arr[23][shipy] = (char)207;
				}
				if (controls == ' ') {

					if (alienscol == bullety) {
						aliensrow = 1;
						if (score == '9') {
							score = '0';
							level++;
						}
						else {
							score = score + 1;
						}
					}

					if (alienscollvl2 == bullety) {
						aliensrowlvl2 = 1;
						if (score == '9') {
							score = '0';
							level++;
						}
						else {
							score = score + 1;
						}
					}

					for (int k = bulletx; k >= 0; k--) {

						if (k != 22) {
							arr[k + 1][bullety] = ' ';
						}
						if (k != 0) {
							arr[k][bullety] = (char)167;
						}
						else {
							arr[k][bullety] = (char)219;
						}
						if (_kbhit()) {
							controls = _getch();

							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

							if (controls == 'a' && shipy > 1) {
								arr[23][shipy] = ' ';
								shipy--;
								arr[23][shipy] = (char)207;
							}

							else if (controls == 'd' && shipy < 49) {
								arr[23][shipy] = ' ';
								shipy++;
								arr[23][shipy] = (char)207;
							}
						}
						for (int i = 0; i < 25; i++) {
							for (int j = 0; j < 70; j++) {
								cout << arr[i][j];
							}
							cout << endl;
						}
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
					}
				}
			}
			if (aliensrow == 1) {
				temp1 = 70;
				for (int i = 0; temp1 <= 0 || temp1 >= 50;) {
					temp1 = rand();
					if (temp1 > 0 && temp1 < 50) {
						alienscol = temp1;
					}
				}
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
		}
		if (lives == '0') {
			system("cls");
			for (int i = 0; i < 25; i++) {
				for (int j = 0; j < 70; j++) {
					if (i != 0 && i != 24 && j != 0 && j != 69) {
						arr[i][j] = ' ';
					}
					else {
						arr[i][j] = (char)219;
					}
				}
			}

			arr[11][24] = 'G';
			arr[11][25] = 'a';
			arr[11][26] = 'm';
			arr[11][27] = 'e';
			arr[11][28] = ' ';
			arr[11][29] = 'O';
			arr[11][30] = 'v';
			arr[11][31] = 'e';
			arr[11][32] = 'r';
			arr[11][33] = '!';

			for (int i = 0; i < 25; i++) {
				for (int j = 0; j < 70; j++) {
					cout << arr[i][j];
				}
				cout << endl;
			}
			cout << "Press R to Restart the Game" << endl;
			cout << "Press Q to Quit the Game" << endl;

			cin >> selection;

			system("cls");

			if (selection == 'q') {
				break;
				temp = 1;
			}

		}
		if (level == '3') {
			system("cls");
			for (int i = 0; i < 25; i++) {
				for (int j = 0; j < 70; j++) {
					if (i != 0 && i != 24 && j != 0 && j != 69) {
						arr[i][j] = ' ';
					}
					else {
						arr[i][j] = (char)219;
					}
				}
			}

			arr[11][25] = 'Y';
			arr[11][26] = 'o';
			arr[11][27] = 'u';
			arr[11][28] = ' ';
			arr[11][29] = 'W';
			arr[11][30] = 'i';
			arr[11][31] = 'n';
			arr[11][32] = '!';

			for (int i = 0; i < 25; i++) {
				for (int j = 0; j < 70; j++) {
					cout << arr[i][j];
				}
				cout << endl;
			}
			cout << "High Score is : " << score;
			cout << "Press R to Restart the Game" << endl;
			cout << "Press Q to Quit the Game" << endl;

			cin >> selection;

			system("cls");

			if (selection == 'q') {
				break;
				temp = 1;
			}
			else
			{
				continue;
			}
		}
	}
}



int main() {

	char selection;
	int temp = 0;

	Welcome();

	for (int i = 0;;) {
		if (temp == 0) {

			cout << endl << endl;

			cout << "					S P A C E       S H O O T E R";

			cout << endl << endl << endl << endl;

			cout << "						INSTRUCTIONS" << endl << endl;
			cout << "					use (A or D) to move around" << endl;
			cout << "					press space to fire bullets" << endl;
			cout << "					avoid hitting space debris" << endl;
			cout << endl << endl;
			cout << "					Press Space key to Start Game" << endl;
			cout << "					Press Q to Exit" << endl;
			temp++;
		}

		if (_kbhit()) {
			selection = _getch();

			if (selection == ' ') {
				game();
				system("cls");
				for (int j = 0; j <= 10; j++) {
					cout << " Exiting...";
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
				}
				break;
			}
			else if (selection == 'q') {
				system("cls");
				for (int j = 0; j <= 10; j++) {
					cout << " Exiting...";
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
				}
				break;
			}
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}

}


