#include "bolha.h"
#include "countingsort.h"
#include "heapsort.h"
#include "insercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selecao.h"
#include "shellsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>

double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess( ), &info, sizeof(info));
    return (double)info.PeakWorkingSetSize/ (1024*1024);
}

int main(int argc, char **argv)
{

    int n=0;

    for (n=2000; n<=128000; n=n*2)
    {

        double *v = malloc(n * sizeof(double));

        clock_t inicio, fim;
        double total;

        decrescente(v,n);
        inicio = clock();

        selecao(v,n);

        fim = clock();
        total = ((fim - inicio) / (double)CLOCKS_PER_SEC);

        double memory_used = get_memory_used_MB();

        printf("\n%.3lfs|%.3lfkb",total,memory_used);

    }

    printf("\n");

    return 0;
}
