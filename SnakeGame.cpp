#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "accounts.cpp"
using namespace std;
int height = 20, width = 20;
int e, score;
int a, b, xf, yf;
void setup()
{
	e = 0;
	a = height / 2;
	b = width / 2;
c1:
	xf = rand() % 20;
	if (xf == 0)
		goto c1;
c2:
	yf = rand() % 20;
	if (yf == 0)
		goto c2;
	score = 0;
}
void make_board()
{
	int i,j;
	system("cls");
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1
				|| j == 0
				|| j == height - 1) {
				cout << "#";
			}
			else {
				if (i == a && j == b)
					cout << "0";
				else if (i == xf
						&& j == yf)
					cout << "*";
				else
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << "score = " << score;
	cout << endl;
	cout << "press X to quit the game";
}
void key_press()
{
	int flag;
	if (kbhit()) {
		switch (getch()) {
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			e = 1;
			break;
		}
	}
}
void algo()
{
	int flag;
	sleep(0.01);
	switch (flag) {
	case 1:
		b--;
		break;
	case 2:
		a++;
		break;
	case 3:
		b++;
		break;
	case 4:
		a--;
		break;
	default:
		break;
	}
	if (a < 0 || a > height
		|| b < 0 || b > width)
		e = 1;
	if (a == xf && b == yf) {
	n1:
		xf = rand() % 20;
		if (xf == 0)
			goto n1;
	n2:
		yf = rand() % 20;
		if (yf == 0)
			goto n2;
		score += 10;
	}
}
int startSnakeGame()
{
	int m,n;
	setup();
	while (!e) {
		make_board();
		key_press();
		algo();
	}
	return 0;
}
int snkG()
{
	startSnakeGame(); // use this function to start the Snake Game.
	return 0;
}