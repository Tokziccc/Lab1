#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M 12
int main()
{
	setlocale(LC_ALL, "rus");

	int n, years, m;

	puts("������� ����� ������� �� 60: ");
	scanf_s("%d", &n);

	m = n % M;
	years = n / M;

	switch (years)
	{
	case 1:
		printf("%d ���\n", years);
		break;
	case 2:
	case 3:
	case 4:
		printf("%d ����\n", years);
		break;
	case 5:
		printf("%d ���\n", years);
		break;
	default:
		puts("");
	}

	switch (m)
	{
	case 1:
		printf("%d �����\n", m);
		break;
	case 2:
	case 3:
	case 4:
		printf("%d ������\n", m);
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		printf("%d �������\n", m);
		break;
	default:
		puts("");
	
	}
	
 }