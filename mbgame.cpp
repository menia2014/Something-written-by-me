#include <iostream>
#include <ctime>
#include <vector>
#include <conio.h>

using namespace std;

int main() {
	srand(time(NULL));
	const string wall = "@", floor = "-", player = "o", coin = "*";
	int h = (rand() % 14) + 8, w = (rand() % 12) + 8, allc = 0, c = 0, floornumber = 1;
	vector<vector<string>> a(h, vector<string>(w));
	
	for (int i = 0; i < h; i++) {
		for (int b = 0; b < w; b++) {
			if (i == 0 or i == h - 1 or b == 0 or b == w - 1) {
				a[i][b] = wall;
			}
			else {
				if (rand() % 32 + 1 == 1) {//коины
					a[i][b] = coin;
					allc++;
				}
				else {
					a[i][b] = floor;
				}
			}
		}
		
	}
	int ph = h / 2, pw = w / 2;
	if (a[ph][pw] == coin) {
		a[ph][pw] = player;
		allc--;
	}
	else {
		a[ph][pw] = player;
	}
	

	for (int i = 0; i < h; i++) { //первый вывод
		for (int b = 0; b < w; b++) {
			cout << a[i][b];
		}
		cout << endl;
	}
	cout << c << "/" << allc << endl;
	cout << "Floor: " << floornumber << endl;

	while (1) {
		int g = _getch();
		if (g == 72) { //up
			if (a[ph - 1][pw] == coin) {
				c++;
			}
			else if (a[ph - 1][pw] == wall) {
				cout << "Wall!!!";
				continue;
			}
			a[ph][pw] = floor; ph = ph - 1; a[ph][pw] = player;
			
		}
		else if (g == 80) { //down
			if (a[ph + 1][pw] == coin) {
				c++;
			}
			else if (a[ph + 1][pw] == wall) {
				cout << "Wall!!!";
				continue;
			}
			a[ph][pw] = floor; ph = ph + 1; a[ph][pw] = player;
			
		}
		else if (g == 75) { //left
			if (a[ph ][pw- 1] == coin) {
				c++;
			}
			else if (a[ph][pw - 1] == wall) {
				cout << "Wall!!!";
				continue;
			}
			a[ph][pw] = floor; pw = pw - 1; a[ph][pw] = player;
			
		}
		else if (g == 77) { //right
			if (a[ph][pw + 1] == coin) {
				c++;
			}
			else if (a[ph][pw + 1] == wall) {
				cout << "Wall!!!";
				continue;
			}
			a[ph][pw] = floor; pw = pw + 1; a[ph][pw] = player;
			
		}
		else { continue; }
		system("cls");
		for (int i = 0; i < h; i++) { //следующие выводы.
			for (int b = 0; b < w; b++) {
				cout << a[i][b];
			}
			cout << endl;
		}
		cout << c << "/" << allc << endl;
		cout << "Floor: " << floornumber << endl;

		if (c == allc) {
			cout << "Floor passed! Press Enter to continue or Esc to exit the game." << endl;
			while (1) {
				int gg = _getch();//27esc 13enter
				if (gg == 27) {
					exit(0);
				}
				else if (gg == 13) { //новая конмата
					floornumber++;
					a.clear();
					h = (rand() % 14) + 8, w = (rand() % 12) + 8, allc = 0, c = 0;
					a.assign(h, vector<string>(w));

					for (int i = 0; i < h; i++) {
						for (int b = 0; b < w; b++) {
							if (i == 0 or i == h - 1 or b == 0 or b == w - 1) {
								a[i][b] = wall;
							}
							else {
								if (rand() % 32 + 1 == 1) {
									a[i][b] = coin;
									allc++;
								}
								else {
									a[i][b] = floor;
								}
							}
						}

					}
					ph = h / 2, pw = w / 2;
					if (a[ph][pw] == coin) {
						a[ph][pw] = player;
						allc--;
					}
					else {
						a[ph][pw] = player;
					}

					system("cls");
					for (int i = 0; i < h; i++) { 
						for (int b = 0; b < w; b++) {
							cout << a[i][b];
						}
						cout << endl;
					}
					cout << c << "/" << allc << endl;
					cout << "Floor: " << floornumber << endl;

				}
				break;
			}
		}
	}

}