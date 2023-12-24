#include <stdio.h>
#include <string.h>
#include "DateCalculator.h"

#define MAX_TODO_ITEMS 10
#define MAX_DATE_LENGTH 20


// 오래된 항목 삭제 기능
void removeOldestTodo();


// 한 일 추가 기능
void addTodo();

// 날짜 계산 및 할 일 알림 기능: 수정 완료
void calculateDueDate();

// 이전까지 한 일 출력 기능
void printAllTodo();
