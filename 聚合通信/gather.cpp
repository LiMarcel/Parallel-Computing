#include <iostream>
#include <mpi.h>

const int N = 2;

using namespace std;

int main(int argc, char* argv[])
{
    int myrank, mysize, root{0};
    int* sendbuff;
    int* recvbuff;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &mysize);

    sendbuff = new int[N];

    for (int i = 0; i < N; i++)
    {
        sendbuff[i] = myrank + i;
    }

    root = 0;

    if (myrank == 0)
    {
        recvbuff = new int[N*mysize];
        for (int i = 0; i < N*mysize; i++)
            cout << "Before gathering, recvbuff[" << i << "] = " << recvbuff[i] << endl;
    }
    cout << endl;

    MPI_Gather(sendbuff, N, MPI_INT, recvbuff, N, MPI_INT, root, MPI_COMM_WORLD);

    if (myrank == 0)
    {
        for (int i = 0; i < N*mysize; i++)
            cout << "After gathering, recvbuff[" << i << "] = " << recvbuff[i] << endl;
        delete recvbuff;
    }
    delete sendbuff;

    MPI_Finalize();

    return 0;
}

