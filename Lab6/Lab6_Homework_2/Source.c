#include<stdio.h>
#include<locale.h>
#include<math.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	float x, y;
	puts("������� x:\n ");
	scanf_s("%f", &x);
	puts("������� y:\n ");
	scanf_s("%f", &y);
	if (((x <= 3 && x >= -2) && (y <= 5 && y >= 2)) || ((x <= 5 && x >= 2) && (y <= 3 && y >= 2)))
		puts("�������� ����� ����������� �������������� �������.");
	else
		puts("�������� ����� �� ����������� �������������� �������.");	
}