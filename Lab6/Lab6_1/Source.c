#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{	
	setlocale(LC_ALL, "RUS");
	int yeas, ost;
	puts("������� ���:");
	scanf_s("%d", &yeas);
	ost = yeas % 4;
	printf("������� �� ������� %d �� 4 �����: %d\n", yeas, ost);
	if ((ost == 0 && yeas % 100 != 0) || (yeas % 400 == 0))
		printf("��� %d �������� ����������.", yeas);
	else
		printf("��� %d �� �������� ����������.", yeas);
		
	
}