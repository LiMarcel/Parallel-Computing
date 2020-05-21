#include <unistd.h>
#include <iostream>
#include <mpi.h>

using namespace std;

int main (int argc, char *argv[])
{
    int myrank, nprocs, name_len, flag;
    double start_time, end_time;
    char host_name[10];

    MPI_Initialized (&flag);
    cout << "flag: " << flag << endl;

    #if !flag
    MPI_Init (&argc, &argv);
    #endif

    MPI_Comm_rank (MPI_COMM_WORLD, &myrank);


    MPI_Comm_size (MPI_COMM_WORLD, &nprocs);


    MPI_Get_processor_name(host_name, &name_len);
    if (myrank == 0)
    {
        cout << "host name: " << host_name << endl;
        cout << "precision of MPI_Wtime(): " << MPI_Wtick() << endl;
    }

    start_time = MPI_Wtime();
    sleep(myrank * 3);


    end_time = MPI_Wtime();
    cout << "myrank: " << myrank << "  I have slept: " << end_time - start_time << " seconds" << endl;

    MPI_Finalize ();
    return 0;
}
