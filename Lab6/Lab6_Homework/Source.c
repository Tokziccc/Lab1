#include<stdio.h>
#include<locale.h>
#include<math.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int x, ed, des, s;
	puts("������� ���������� �����:\n ");
	scanf_s("%d", &x);
	ed = x % 10;
	des = (x / 10) % 10;
	s = x / 100;
	if (ed == des && ed == s)
		puts("��� ������� �����.");
	else
		if (ed == des)
			puts("����� ������ � �������� �����.");
		else
			if (des == s)
				puts("����� �������� � ����� �����.");
			else
				if (ed == s)
					puts("����� ������ � ����� �����.");
				else
					puts("��� ������ ��������.");


}