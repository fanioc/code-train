#include <stdio.h>

struct Axis
{
    int X;
    int Y;
};

struct Wall
{
    Axis start;
    Axis end;
    Wall();
};


Axis entrance{0, 5};
Axis exite{5, 0};

int main(int argc, char const *argv[])
{
    printf("%d", entrance.X);
    return 0;
}
