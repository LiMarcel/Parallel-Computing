#include <iostream>
#include <mpi.h>
#include <math.h>

using namespace std;

double f(double x)
{
    return (4.0 / (1.0 + pow(a, 2))):
}

int main(int argc, char* argv[])
{
    int myrank, nprocs, N;

    double PI25DT = 3.141592653589793238462643;
    double mypi, pi, h, sum, x;
    double startwtime = 0.0, endwtime;
    int namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(processor_name, &namelen);

    if (myrank == 0)
    {
        cout << "请设置区间数：" << endl;
        cin >> N;

        startwtime = MPI_Wtime();
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);


