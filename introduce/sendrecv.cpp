#include <iostream>
#include <mpi.h>

using namespace std;

#define N 100

int main(int argc, char* argv[])
{
    int myrank;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = -1;
    }

    MPI_Status status;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0)
    {
        for (int i = 0; i < N; i++)
        {
            a[i] = 100;
        }
        MPI_Send(&a, N, MPI_INT, 1, 99, MPI_COMM_WORLD);
    }
    else if (myrank == 1)
    {
        cout << "接受前a[0] = " << a[0] << endl;
        MPI_Recv(&a, N, MPI_INT, 0, 99, MPI_COMM_WORLD, &status);
        cout << "接受后a[0] = " << a[0] << endl;
    }

    MPI_Finalize();

    return 0;
}
