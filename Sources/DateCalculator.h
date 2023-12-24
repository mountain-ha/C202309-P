// 날짜를 나타내는 구조체
#ifndef DATE_CALCULATOR_H
#define DATE_CALCULATOR_H

struct Date {
    int year;
    int month;
    int day;

};

// 각 월의 일수 배열
int daysInMonth[2][12];

// 윤년 여부를 판단하는 함수
 int isLeapYear(int year);

// n일 후의 날짜를 계산하는 함수
struct Date calculateDate(struct Date currentDate, int n);

#endif // DATE_CALCULATOR_H