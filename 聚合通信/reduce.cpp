#include <iostream>
#include <unistd.h>
#include <mpi.h>

using namespace std;

const int N = 3;

int main(int argc, char* argv[])
{
    int myrank, mysize;
    int recv_buff[N];
    int send_buff[N];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_rank(MPI_COMM_WORLD, &mysize);

    for (int i = 0; i < N; i++)
    {
        send_buff[i] = myrank;
    }

    int root = 1;

    MPI_Reduce(send_buff, recv_buff, N, MPI_INT, MPI_MAX, root, MPI_COMM_WORLD);

    if (myrank == root)
    {
        for (int i = 0; i < N; i++)
        {
            cout << "recv_buff[" << i << "] = " << recv_buff[i] << endl;
        }
    }

    MPI_Finalize();

    return 0;
}


