// ��¥�� ��Ÿ���� ����ü
struct Date {
    int year;
    int month;
    int day;
};

// �� ���� �ϼ� �迭
int daysInMonth[2][12];

// ���� ���θ� �Ǵ��ϴ� �Լ�
 int isLeapYear(int year);

// n�� ���� ��¥�� ����ϴ� �Լ�
struct Date calculateDate(struct Date currentDate, int n);