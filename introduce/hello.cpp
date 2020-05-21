#include <unistd.h>
#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char* argv[])
{
    int myrank, size, i;

    // 初始化MPI环境
    MPI_Init(&argc, &argv);

    // 获取通信器MPI_COMM_WORLD中的进程数
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // 获取当前进程在通信器中的进程号
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    for (i = 0; i < 10; i++)
    {
        if (myrank == i)
        {
            sleep(i/10); // 按进程顺序输出
            cout << "Myrank = " << myrank << ": Hello World" << endl;
        }
    }

    MPI_Finalize();
    return 0;
}
