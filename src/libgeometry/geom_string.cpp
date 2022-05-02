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

void SkipSpaces(int C[], int* i)
{
    for (; C[*i] == ' '; ++*i)
        ;
}

int ProcessGeomFile()
{
    FILE* file;
    char fname[] = "lab_input.txt";
    file = fopen(fname, "r");

    int C[SIZE_STR];
    char circleName[] = "circle";
    int i = 0;
    int iL, iD = 0, iR;
    float x_circle = 0, y_circle = 0, radius = 0;

    if (file == NULL) {
        printf("unable to open file '%s'", fname);
        return 10;
    }

    C[i] = fgetc(file);

    while (C[i] != EOF) {
        i++;
        C[i] = fgetc(file);
    }
    i = 0;

    SkipSpaces(C, &i);

    if ((C[i] == 'c' || C[i] == 'C') && (C[i + 1] == 'i' || C[i + 1] == 'I')
        && (C[i + 2] == 'r' || C[i + 2] == 'R')
        && (C[i + 3] == 'c' || C[i + 3] == 'C')
        && (C[i + 4] == 'l' || C[i + 4] == 'L')
        && (C[i + 5] == 'e' || C[i + 5] == 'E')
        && (C[i + 6] == ' ' || C[i + 6] == '(')) {
        i += 6;
    } else {
        printf("word circle is not correct\n");
        return 1;
    }

    SkipSpaces(C, &i);

    if ((C[i] == '(')) {
        i++;
    } else {
        printf("opening brackets are not correct\n");
        return 4;
    }

    SkipSpaces(C, &i);

    iL = i;
    for (; C[i] != ' '; i++) { // start reading x_circle
        if (C[i + 1] == '.') {
            iD = i + 1;
        }
    }
    iR = i;
    i--;

    for (; (i != iD) && iD != 0; i--) {
        x_circle += powf(10, -(i - iD)) * (C[i] - 48);
    }
    for (i--; i != iL - 1; i--) {
        x_circle += pow(10, (iD - i - 1)) * (C[i] - 48);
    }

    i = iR;
    iD = 0;

    SkipSpaces(C, &i);

    iL = i;
    for (; (C[i] != ' ') && (C[i] != ',') && (C[i] != ')');
         i++) { // start reading y_circle
        if (C[i + 1] == '.') {
            iD = i + 1;
        }
    }
    iR = i;
    i--;

    for (; (i != iD) && iD != 0; i--) {
        y_circle += powf(10, -(i - iD)) * (C[i] - 48);
    }
    for (i--; i != iL - 1; i--) {
        y_circle += pow(10, (iD - i - 1)) * (C[i] - 48);
    }
    i = iR;
    iD = 0;

    for (; C[i] == ' '; i++)
        ;
    if (C[i] == ',')
        i++;
    else {
        printf("expected comma");
        return 2;
    }
    for (; C[i] == ' '; i++)
        ;
    iL = i;
    for (; (C[i] != ' ') && (C[i] != ',') && (C[i] != ')');
         i++) { // start reading radius
        if (C[i + 1] == '.') {
            iD = i + 1;
        }
    }
    iR = i;
    i--;

    for (; (i != iD) && iD != 0; i--) {
        radius += powf(10, -(i - iD)) * (C[i] - 48);
    }
    for (i--; i != iL - 1; i--) {
        radius += pow(10, (iD - i - 1)) * (C[i] - 48);
    }

    i = iR;

    for (; C[i] == ' '; i++)
        ;

    if (C[i] == ')') {
        i++;
    } else {
        printf("closing brackets are not correct");
        return 3;
    }

    while (C[i] != EOF) {
        printf("%c", C[i]);
        i++;
    }

    printf("%s(%f %f, %f)\n", circleName, x_circle, y_circle, radius);
    printf("Circle perimeter - %f, Area - %f",
           OutputCirclePerim(radius),
           OutputCircleArea(radius));

    return 0;
}
