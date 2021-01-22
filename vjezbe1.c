#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_SIZE 32
#define MAX_LINE_SIZE 256

typedef struct _student {
	char name[MAX_NAME_SIZE];
	char surname[MAX_NAME_SIZE];
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
	free(st);
	system("pause");
	return 0;
}

int countRows(FILE *fp) {
	fp = fopen("zadatak1.txt", "r"); 
	if (fp == NULL)
		return -1;
	int rowNumber = 0; 
	char buffer[MAX_LINE_SIZE];
	while (fgets(buffer, MAX_LINE_SIZE, fp))
		rowNumber++;
	fclose(fp);
	return rowNumber;
}

int readData(Student* st, FILE *fp, int studentNumber) {
	fp = fopen("zadatak1.txt", "r"); 
	if (fp == NULL)
		return -1;
	for (int i = 0; i < studentNumber; i++)
		fscanf(fp, "%s %s %f", st[i].name, st[i].surname, &st[i].score);
	fclose(fp);
	return 0;
}

int printData(Student* st, int studentNumber) {
	printf("IME\tPREZIME\tBODOVI\tRELATIVNI BROJ BODOVA\n");
	float maxScore = 0, relativeScore;
	for (int i = 0; i < studentNumber; i++)
		if (st[i].score > maxScore)
			maxScore = st[i].score;
	for (int i = 0; i < studentNumber; i++) {
		relativeScore = st[i].score / maxScore * 100;
		printf("%s\t%s\t%f\t%f\n", st[i].name, st[i].surname, st[i].score, relativeScore);
	}
	return 0;
} 

