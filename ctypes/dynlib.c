
#define FIELD_E 0x7FF0000000000000
#define FIELD_M 0x000FFFFFFFFFFFFF

double m_sqrt(double x)
{
    long long * ix = (long long *) & x;
    long long e;
    double k = x;
    
    e = ((*ix & FIELD_E)>>52) - 1023;
    *ix &= FIELD_M; 

    if( e&1 )
        e = (e-1)/2+1;
    else
        e = e/2;

    *ix += (e + 1023) << 52;

    x = x/2 +  k / (2*x);
    x = x/2 +  k / (2*x);
    x = x/2 +  k / (2*x);
    x = x/2 +  k / (2*x);
    x = x/2 +  k / (2*x);
    

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

