#include <iostream>
#include <mpi.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
    int myrank, size, selfrank;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Comm_rank(MPI_COMM_SELF, &selfrank);

    sleep(myrank);
    cout << "线程序号: " << getpid() << "  世界进程号：" << myrank << "  私人进程号：" << selfrank << "  总进程数：" << size << endl;

    MPI_Finalize();

    return 0;
}
