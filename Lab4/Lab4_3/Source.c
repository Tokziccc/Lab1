#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "RUS");

	int num;
	puts("������� ����������� �����:");
	scanf_s("%d", &num);
	printf("a) ��������� �����: %d \n�) ������ �����: %d \n�) ����� ����: %d\n\n", num % 10, num / 100, num % 10 + num / 100 + (num / 10) % 10);
	printf("����� ��������: %d%d%d\n", num % 10, num / 10 % 10, num / 100 % 10);
}