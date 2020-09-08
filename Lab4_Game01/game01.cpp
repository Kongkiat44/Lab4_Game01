#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
void draw_ship(int , int );
void gotoxy(int , int );
void erase_ship(int , int );
void clean_line(int );
int main() {
	char ch = ' ';
	int x = 0, y = 0;
	printf("Enter your x and y point as your start point\nNote : 0 <= x <= 80\n       0 <= y <= 23\nYour start point: ");
	scanf("%d %d", &x, &y);
	x < 0 ? x = 0 : x = x;
	x > 80 ? x = 80 : x = x;
	y < 0 ? y = 0 : y = y;
	y > 23 ? y = 23 : y = y;
	clean_line(0);
	clean_line(1);
	clean_line(2);
	clean_line(3);
	gotoxy(0, 0);
	printf("Testing...");
	for (int a = 0; a < 80;) {
		draw_ship(a, y);
		a++;
		Sleep(500);
		if (a == 80) {
			for (int b = a; b > 0;) {
				draw_ship(b, y);
				b--;
				Sleep(500);
			}
		}
	}
	clean_line(0);
	clean_line(y);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { 
				if (x <= 0) draw_ship(0, y);
				else draw_ship(--x, y); }
			if (ch == 'd') { 
				if (x >= 80) draw_ship(80, y);
				else draw_ship(++x, y); }
			if (ch == 'w') {
				erase_ship(x, y);
				if (y <= 0) {
					draw_ship(x, 0);
				}
				else {
					draw_ship(x, --y);
				}
			}
			if (ch == 's') {
				erase_ship(x, y);
				if (y >= 23) {
					draw_ship(x, 23);
				}
				else {
					draw_ship(x, ++y);
				}
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("       ");
}
void clean_line(int y)
{
	gotoxy(0, y);
	for (int x = 0; x < 80; x++) {
		printf(" ");
	}
}