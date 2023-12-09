#include <stdio.h>

// 날짜를 나타내는 구조체
struct Date {
    int year;
    int month;
    int day;
};

// 각 월의 일수 배열
int daysInMonth[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  // 평년
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}   // 윤년
};

// 윤년 여부를 판단하는 함수
int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

    }

   
