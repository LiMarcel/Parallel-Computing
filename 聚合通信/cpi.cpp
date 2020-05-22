#include <iostream>
#include <mpi.h>
#include <math.h>

using namespace std;

double f(double x)
{
    return (4.0 / (1.0 + pow(x, 2)));
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
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Get_processor_name(processor_name, &namelen);

    if (myrank == 0)
    {
        cout << "请设置区间数：" << endl;
        cin >> N;
        cout << "总进程数：" << nprocs << endl;

        startwtime = MPI_Wtime();
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (N > 0)
    {
        h = 1.0 / (double)N;
        sum = 0.0;

        int n = N / nprocs + 1;
        int end = ((myrank + 1)*n) > N ? N : ((myrank + 1)*n);

        for (int i = myrank*n + 1; i <= end; i++)
        {
            x = h * ((double)i - 0.5);
            sum += f(x);
        }
        mypi = sum * h;

        MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

        if (myrank == 0)
        {
            cout << "pi is approximately: " << pi << endl;
            cout << "Error is: " << fabs(pi - PI25DT) << endl;
            endwtime = MPI_Wtime();
            cout << "用时：" << endwtime - startwtime << endl;
        }

    }

    MPI_Finalize();

    return 0;
}


