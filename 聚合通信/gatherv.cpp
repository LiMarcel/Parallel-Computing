#include <iostream>
#include <unistd.h>
#include <mpi.h>

const int N = 2;

using namespace std;

int main(int argc, char* argv[])
{
    int myrank, mysize, root{0};
    int recvbuffsize;
    int* sendbuff;
    int* recvbuff;
    int* recvcounts;
    int* displacements;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &mysize);

    int sendcount = myrank+1;
    sendbuff = new int[sendcount];

    sleep(myrank/10);
    for (int i = 0; i < sendcount; i++)
    {
        sendbuff[i] = myrank;
        cout << "Before gatherv, myrank: " << myrank << ", sendbuff[" << i << "] = " << sendbuff[i] << endl;
    }

    root = 2;

    if (myrank == root)
    {
        recvbuffsize = mysize;
        recvbuff = new int[recvbuffsize*mysize];
        for (int i = 0; i < recvbuffsize*mysize; i++)
            recvbuff[i] = -1;

        recvcounts = new int[mysize];
        displacements = new int[mysize];

        for (int i = 0; i < mysize; i++)
        {
            recvcounts[i] = i+1;
            displacements[i] = i*recvbuffsize;
        }
    }

    MPI_Gatherv(sendbuff, sendcount, MPI_INT,
                recvbuff, recvcounts, displacements, MPI_INT,
                root, MPI_COMM_WORLD);
    sleep(2);
    MPI_Barrier(MPI_COMM_WORLD);

    if (myrank == root)
    {
        for (int i = 0; i < recvbuffsize*mysize; i++)
            cout << "After gathering, recvbuff[" << i << "] = " << recvbuff[i] << endl;
        delete recvbuff;
        delete recvcounts;
        delete displacements;
    }
    delete sendbuff;

    MPI_Finalize();

    return 0;
}

