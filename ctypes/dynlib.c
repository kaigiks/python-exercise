#include<stdlib.h>

double sqrt(double k)
{
    int i;
    double x = k;

    for( i=0; i<5; i++ )
        x = x - (x*x-k)/(2*x);

    return x;
}

typedef struct {
    float x;
    float y;
} Point;

void reflect_over_yaxis( Point* p )
{
    p->x = -(p->x);
}

