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

// n일 후의 날짜를 계산하는 함수
struct Date calculateDate(struct Date currentDate, int n) {
    // 윤년 여부 확인
    int isLeap = isLeapYear(currentDate.year);

    // 현재 날짜에 n일을 더함
    currentDate.day += n;

    //  현재 달의 일수를 초과한 만큼 날짜를 감소시키고, 이제 다음 달로 이동
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

   
