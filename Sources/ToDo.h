#include <stdio.h>
#include <string.h>
#include "DateCalculator.h"

#define MAX_TODO_ITEMS 10
#define MAX_DATE_LENGTH 20

// ���� ����
char dates[MAX_TODO_ITEMS][MAX_DATE_LENGTH];
int tasks[MAX_TODO_ITEMS];
int itemCount = 0;

// ������ �׸� ���� ���
void removeOldestTodo();


// �� �� �߰� ���
void addTodo();

// ��¥ ��� �� �� �� �˸� ���: ���� �Ϸ�
void calculateDueDate();

// �������� �� �� ��� ���
void printAllTodo();
