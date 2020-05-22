/* 
 * 学习MPI_Scan 和 自定义规约函数 
*/

#include <iostream>
#include <unistd.h>
#include <mpi.h>

using namespace std;

const int N = 3;

void Operator(void* invec, void* inoutvec, int* length, MPI_Datatype* data_type)
{
    int* a = (int*) invec;
    int* b = (int*) inoutvec;
    for (int i = 0; i < *length; i++)
    {
        b[i] += a[i];
    }
}

int main(int argc, char* argv[])
{
    int myrank;
    MPI_Op op;
    int send_buff[N] = {1, 5, 10};
    int recv_buff[N];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    MPI_Op_create(&Operator, 0, &op);

    MPI_Scan(send_buff, recv_buff, N, MPI_INT, op, MPI_COMM_WORLD);

    MPI_Op_free(&op);

    sleep(myrank);
    cout << "myrank: " << myrank << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "recv_buff[" << i << "] = " << recv_buff[i] << endl;
    }

    MPI_Finalize();

    return 0;
}


