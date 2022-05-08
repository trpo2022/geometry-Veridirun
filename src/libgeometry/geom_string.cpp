#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_STR 100

float OutputCirclePerim(float r)
{
    return ((2 * (float)M_PI) * r);
}

float OutputCircleArea(float r)
{
    return ((float)M_PI * powf(r, 2));
}

void SkipSpaces(char C[], int &i)
{
    for (; C[i] == ' '; ++i)
        ;
}

int CountLines(FILE* file){
	char c;
	int lineAmount=1;
	
	c=getc(file);
	if(c==EOF) 
		return 0;
	while(c!=EOF){
		if(c=='\n')
			lineAmount++;
		c=getc(file);
	}
	return lineAmount;
}

void AllocateMemory(char **&C, int lineAmount){ //allocate memory to array of chars for every line
	C=new char*[lineAmount]; 
	int i;
	for(i=0;i<lineAmount;i++){
		C[i]=new char[SIZE_STR];
	}
}

void ReadLines(FILE *file, char **&C, int lineAmount){
	int i,j;
	rewind(file);
	char ch=getc(file);
	for(i=0;i<lineAmount;i++){
		for(j=0;ch!='\n'&&ch!=EOF;j++){
			C[i][j]=ch;
			ch=getc(file);
		}
		ch=getc(file);
		C[i][j]=0;
	}
}

int CheckWord(char *&C, int &i){
    if ((C[i] == 'c' || C[i] == 'C') 
		&& (C[i + 1] == 'i' || C[i + 1] == 'I')
        && (C[i + 2] == 'r' || C[i + 2] == 'R')
        && (C[i + 3] == 'c' || C[i + 3] == 'C')
        && (C[i + 4] == 'l' || C[i + 4] == 'L')
        && (C[i + 5] == 'e' || C[i + 5] == 'E')
        && (C[i + 6] == ' ' || C[i + 6] == '(')) {
        i += 6;
        return 0;
    } else {
        return 1;
    }	
}

float ReadNum(char *&C, char *temp, int &i){
	
}

int ProcessLine(char *&C, float *coords, int lineAmount){
	int i=0;
	
	char temp[20];
	int j;
	SkipSpaces(C,i);
	
	if(CheckWord(C,i)){
		return 1;
	}
	
	SkipSpaces(C,i);
	
	if(C[i]!='(')
		return 2;
	
	SkipSpaces(C,i);
	
	coords[0]=ReadNum(C, temp, i);
	
	printf("C[%d]=%c",i, C[i]);
	
	return 0;
}

//'0'=48 '9'=57
int ProcessGeomFile()
{
	int i;
	FILE* file;
	char fname[] = "lab_input.txt";
	file = fopen(fname, "r");
	
	char **C;
	
	int lineAmount = CountLines(file);

	AllocateMemory(C, lineAmount);
	
	ReadLines(file, C, lineAmount);
	
	float coords[lineAmount][3]; //every line of this array contains x,y,radius of every circle
	
	for(i=0;i<lineAmount;i++){
		switch(ProcessLine(C[i], coords[i], lineAmount)){
			case 1:
				printf("word circle is not correct\n");
				return 1;
			case 2:
				printf("expected opening bracket\n");
				return 2;
			default:
				break;
		}
	}
	return 0;
}

