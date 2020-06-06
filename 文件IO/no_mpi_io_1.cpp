#include <iostream>
#include <mpi.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    int myrank;
    char file[10];
    FILE *fp;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    sprintf(file, "file%d", myrank);

    fp = fopen(file, "w");
    fprintf(fp, "square of myrank = %d\n", myrank*myrank);
    fclose(fp);

    MPI_Finalize();
    return 0;
}


