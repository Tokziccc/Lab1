#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int  m, t, S;
	puts("������� ����� � �������: ");
	scanf_s("%d", &m);
	puts("������� ���-�� �������, ������� ����� �������� �� ������� �����: ");
	scanf_s("%d", &t);
	puts("������� ��������� ����� �������� � ������: ");
	scanf_s("%d", &S);
	float v = t * S / (float)m / 60.f;
	printf("�������� ������ ����� �����: %.3f �/�", v);
}