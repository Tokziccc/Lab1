#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "RUS");

	char c = "!";
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;

	printf("c=%c; i=%d; f=%f; d=%e\n", c, i, f, d);

	puts("������� ������:");
	scanf_s("%c", &c);
	puts("������� ����� �����:");
	scanf_s("%d", &i);
	puts("������� ������������ �����:");
	scanf_s("%f", &f);
	puts("������� ������������ ����� � ���������������� �����:");
	scanf_s("%le", &d);

	printf("%c; %d; %f; %lf\n\n", c, i, f, d);

	puts("������ 1�:");
	printf("����� �����: %d; ������� �����: %f\n\n", (int)f, f - (int)f);

	puts("������ 1�:");
	printf("����������������� ���: %x; ���������� ���: %d\n\n", c, c);

	puts("������ 1�:");
	printf("1 / %d ����� %.2f\n", i, 1. / i);
}