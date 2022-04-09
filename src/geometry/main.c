#include "libgeometry/geom_string.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_STR 100

float OutputCirclePerim(float r)
{
    return 2 * M_PI * r;
}

float OutputCircleSq(float r)
{
    return M_PI * powf(r, 2);
}

float OutputTriangleSq(
        float x11, float x12, float x21, float x22, float x31, float x32)
{
    float vector_a1 = x21 - x11;
    float vector_a2 = x22 - x12;
    float vector_b1 = x31 - x11;
    float vector_b2 = x32 - x12;
    float length_a = sqrt(powf(vector_a1, 2) + powf(vector_a2, 2));
    float length_b = sqrt(powf(vector_b1, 2) + powf(vector_b2, 2));
    float cos_ab = (vector_a1 * vector_b1 + vector_a2 * vector_b2)
            / (length_a * length_b);
    float sin_ab = sqrt(1 - powf(cos_ab, 2));
    return length_a * length_b * sin_ab / 2;
}

int main()
{
    return ProcessGeomFile();
}

