#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    float x, y, result;
    char c;

    setlocale(LC_ALL, "RUS");
    
    puts("������� ������ �������� (� ����� �������: 5 + 3): ");
    scanf("%f %c %f", &x, &c, &y);

    
    switch (c) {
    case '+':
        result = x + y;
        printf("=%f\n", result);
        break;
    case '-':
        result = x - y;
        printf("=%f\n", result);
        break;
    case '*':
        result = x * y;
        printf("=%f\n", result);
        break;
    case '/':
        if (y != 0) 
        {
            result = x / y;
            printf("=%f\n", result);
        }
        else 
        {
            printf("������� �� 0 ����������.\n");
        }
        break;
    case '^':
        result = pow(x, y);
        printf("=%f\n", result);
        break;
    default:
        printf("����������� ������\n");
        break;
    }

    return 0;
}