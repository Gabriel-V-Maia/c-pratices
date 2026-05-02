#include <omp.h>
#include <stdio.h>

int main() 
{

    #pragma omp parallel for
    for(int i = 0; i < 10; i++) 
    {
        printf("FUCK YOU MICROSOFT");
    }
    return 0;
}
