#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 256 


typedef struct _student {
	char name[MAX];
	char surname[MAX];
	float score;

}Student;

int countRows(FILE *fp);
int readData(Student* st, FILE *fp, int studentNumber);
int printData(Student* st, int studentNumber);

int main(void) {
	Student *st;
	FILE *fp = NULL;
	int studentNumber = countRows(fp);
	st = (Student*)malloc(studentNumber * sizeof(Student));
	readData(st, fp, studentNumber);
	printData(st, studentNumber);
	system("pause");
	return 0;
}

int countRows(FILE *fp) {
	fp = fopen("zadatak1.txt", "r");
	char characterRead;
	int rowNumber = 0;
	characterRead = fgetc(fp);
	while (characterRead != EOF)
	{
		if (characterRead == '\n')
			rowNumber++;
		characterRead = fgetc(fp);
	}
	fclose(fp);
	return rowNumber;
}

int readData(Student* st, FILE *fp, int studentNumber) {
	fp = fopen("zadatak1.txt", "r");
	int i;
	for (i = 0; i < studentNumber; i++)
		fscanf(fp, "%s %s %f", st[i].name, st[i].surname, &st[i].score);
	fclose(fp);
	return 0;
}

int printData(Student* st, int studentNumber) {
	printf("IME\tPREZIME\tBODOVI\tRELATIVNI BROJ BODOVAn");
	int i;
	float maxScore = 0, relativeScore;
	for (i = 0; i < studentNumber; i++)
		if (st[i].score > maxScore)
			maxScore = st[i].score;
	for (i = 0; i < studentNumber; i++) {
		relativeScore = st[i].score / maxScore * 100;
		printf("%s\t%s\t%f\t%f\n", st[i].name, st[i].surname, st[i].score, relativeScore);
	}
	return 0;
}
