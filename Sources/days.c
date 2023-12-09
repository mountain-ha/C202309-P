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

// n�� ���� ��¥�� ����ϴ� �Լ�
struct Date calculateDate(struct Date currentDate, int n) {
    // ���� ���� Ȯ��
    int isLeap = isLeapYear(currentDate.year);

    // ���� ��¥�� n���� ����
    currentDate.day += n;

    //  ���� ���� �ϼ��� �ʰ��� ��ŭ ��¥�� ���ҽ�Ű��, ���� ���� �޷� �̵�
    while (currentDate.day > daysInMonth[isLeap][currentDate.month - 1]) {
        currentDate.day -= daysInMonth[isLeap][currentDate.month - 1];
        currentDate.month++;

        if (currentDate.month > 12) {
            currentDate.month = 1;
            currentDate.year++;
            isLeap = isLeapYear(currentDate.year);
        }
    }

    
    return currentDate;
}

int main() {
    printf("a");
    return;
}

   
