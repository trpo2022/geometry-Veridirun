#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_STR 100

float OutputCirclePerim(float);

float OutputCircleArea(float);

int ProcessGeomFile(const char *);

void SkipSpaces(char C[], int&);

int CountLines(FILE*);

void AllocateMemory(char**&, int);

void ReadLines(FILE*, char**&, int);

int CheckWord(char*&, int&);

float ReadNum();

int CheckNum(char*, int, const char);

int ProcessLine(char*&, double*);

int CheckIntersection(double *(coords)[3], int, int);

void PrintOne(double (*coords)[3], int, int);
