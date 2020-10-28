#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 256

typedef struct _student{
    char name[MAX];
    char surname[MAX];
    int score;

}Student;

int countRows(FILE *fp);
int readData(Student* st, FILE *fp, int studentNumber);
int printData(Student* st, int studentNumber);

int main(void) {
    Student *st;
	FILE *fp;
	int studentNumber;
	studentNumber = countRows(fp);
	st = (Student*)malloc(studentNumber * sizeof(Student));
	readData(st, fp, studentNumber);
	printData(st, studentNumber);
	printf("%d", studentNumber);
}

int countRows( FILE *fp){
    fp = fopen("zadatak1.txt", "r");
    char characterRead;
    int rowNumber = 0;
    characterRead = fgetc(fp);
	while(characterRead != EOF)
	{
		if(characterRead == '\n')
			rowNumber++;
        characterRead = fgetc(fp);
	}
	fclose(fp);
	return rowNumber;
}

int readData(Student* st, FILE *fp, int studentNumber){
    fp = fopen("zadatak1.txt", "r");
    int i;
    for(i = 0; i < studentNumber; i++)
        fscanf(fp, "%s %s %d", st[i].name, st[i].surname, st[i].score);
    fclose(fp);
    return 0;
}

int printData(Student* st, int studentNumber){
    int i, maxScore = 0;
    float relativeScore;
    for(i = 0; i < studentNumber; i++)
        if(st[i].score > maxScore)
            maxScore = st[i].score;
    for(i = 0; i < studentNumber; i++){
        relativeScore = (float)(st[i].score / maxScore * 100);
        printf("%s %s %d %f", st[i].name, st[i].surname, st[i].score, relativeScore);
    }
    return 0;
}
