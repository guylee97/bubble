#include <stdio.h>
#include <string.h>

void sort_name(int n);
void sort_birth(int n);

struct birth
{
	int year;
	int month;
	int day;
};


struct individual
{
	char name[20];
	struct birth mybirth;
	char gender[10];
	char location[30];
	char phonenumber[30];
};

struct individual id[10];
struct individual temp;

int main()
{

	int i;
	int n = 4;
	while (n < 5&&n>10)
	{
		printf("\n몇명의 정보를 입력하십니까?(5~10) :  ");
		scanf_s("%d", &n, 4);
		getchar();
		if(n<5&&n>10)
			printf("\n다시 입력해주세요");
	}

	for (i = 0; i < n; i++)
	{
		printf("\n%d번째 정보 입력", i);
		printf("\n이름 :  ", i);
		scanf_s("%s", &id[i].name, 20);
		printf("\n생년 : ", i);
		scanf_s("%d", &id[i].mybirth.year, sizeof(id[i].mybirth.year));
		printf("\n생월 : ", i);
		scanf_s("%d", &id[i].mybirth.month, sizeof(id[i].mybirth.month));
		printf("\n생일 : ", i);
		scanf_s("%d", &id[i].mybirth.day, sizeof(id[i].mybirth.day));
		printf("\n성별(남/여) : ", i);
		scanf_s("%s", &id[i].gender, 10);
		getchar();
		printf("\n주소 : ", i);
		gets(&id[i].location);
		printf("\n전화번호(띄어쓰지 않고 입력) : ", i);
		scanf_s("%s", &id[i].phonenumber, 20);
		printf("\n");
	}

	printf("이름\t생년월일\t성별\t주소\t전화번호\t \n");

	for (i = 0; i < n; i++)
	{
		printf("%s\t %d,%d,%d\t %s\t %s\t %s\t \n", id[i].name, id[i].mybirth.year, id[i].mybirth.month, id[i].mybirth.day, id[i].gender, id[i].location, id[i].phonenumber);
	}

	sort_name(n);

	printf("\n\n");
	printf("이름\t생년월일\t성별\t주소\t전화번호\t \n");

	for (i = 0; i < n; i++)
	{
		printf("%s\t %d,%d,%d\t %s\t %s\t %s\t \n", id[i].name, id[i].mybirth.year, id[i].mybirth.month, id[i].mybirth.day, id[i].gender, id[i].location, id[i].phonenumber);
	}

	sort_birth(n);

	printf("\n\n");
	printf("이름\t생년월일\t성별\t주소\t전화번호\t \n");

	for (i = 0; i < n; i++)
	{
		printf("%s\t %d,%d,%d\t %s\t %s\t %s\t \n", id[i].name, id[i].mybirth.year, id[i].mybirth.month, id[i].mybirth.day, id[i].gender, id[i].location, id[i].phonenumber);
	}


	system("pause");
	return 0;
}




void sort_name(int n)
{
	int i, j;

	for (i = 0; i < n-1; i++)
	{

		for (j = 0; j < n-1; j++)
		{
			if (strcmp(id[j].name, id[j+1].name) < 0)
			{
					temp = id[j];
					id[j] = id[j+1];
					id[j+1] = temp;
			}

		}

	}

}

void sort_birth(int n)
{
	int i, j;

	for (i = 0; i < n-1; i++)
	{

		for (j = 0; j < n-1; j++)
		{
			if (id[j].mybirth.year>id[j+1].mybirth.year)
			{
					temp = id[j];
					id[j] = id[j+1];
					id[j+1] = temp;
			}

			else if (id[j].mybirth.month>id[j+1].mybirth.month&&id[j].mybirth.year == id[j+1].mybirth.year)
			{
					temp = id[j];
					id[j] = id[j+1];
					id[j+1] = temp;	
			}

			else if (id[j].mybirth.day>id[j+1].mybirth.day&&id[j].mybirth.month == id[j+1].mybirth.month&&id[j].mybirth.year == id[j+1].mybirth.year)
			{
					temp = id[i];
					id[i] = id[j+1];
					id[j+1] = temp;
			}

		}

	}
}