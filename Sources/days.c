#include <stdio.h>

// ��¥�� ��Ÿ���� ����ü
struct Date {
    int year;
    int month;
    int day;
};

// �� ���� �ϼ� �迭
int daysInMonth[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  // ���
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}   // ����
};

// ���� ���θ� �Ǵ��ϴ� �Լ�
int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

    }

   
