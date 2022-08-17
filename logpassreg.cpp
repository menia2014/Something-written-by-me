#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string path = "myFile.txt";
	ifstream fin;
	ofstream fout;
	string log, str;
	cout << "Для входа нажмите 1" << endl;
	cout << "Для регистрации нажмите 2" << endl;
	int g = _getch();

	if (g == 49) {

		while (1) {
			system("cls");
			cout << "Введите логин: ";
			cin >> log;
			fin.open(path);
			int lt = 0;
			while (!fin.eof()) {
				fin >> str;
				if (str == log) {
					lt = 1;
					cout << "Введите пароль: ";
					string pass;
					cin >> pass;
					fin >> str;
					if (pass == str) {
						cout << "Вход выполнен";
						_getch();
						exit(0);
					}
					else {
						cout << "Неверный пароль";
						_getch();
						break;
					}

				}
				else {
					fin >> str;
				}
			}
			if (lt == 0) {
				cout << endl << "Логина не существует!" << endl;
				_getch();
			}
			fin.close();
		}
	}
	else if (g == 50) {
		while (1) {
			system("cls");
			fout.open(path, ofstream::app);
			fin.open(path);
			cout << "Введите логин: ";
			cin >> log;
			int ex = 0;
			while (!fin.eof()) {
				str = "";
				fin >> str;
				if (str == log) {
					cout << "Такой логин существует!";
					_getch();
					ex = 1;
					fout.close();
					fin.close();
				}
				fin >> str;
			}
			if (ex == 1) {
				continue;
			}
			cout << "Введите пароль: ";
			string pass;
			cin >> pass;
			fout << log << " " << pass << "\n";
			cout << "Регистрация прошла успешно!";
			_getch();
			fout.close();
			fin.close();
			break;
		}
	}
}