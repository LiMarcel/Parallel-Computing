#include <iostream>
#include <unistd.h>
#include <mpi.h>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    int myrank, mysize;
    int size[4], pack_size[3];
    vector<string> name = {"MPI_CHAR", "MPI_INT", "MPI_FLOAT", "MPI_DOUBLE"};
    MPI_Aint extent[4], lb_disp[4], ub_disp[4];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &mysize);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    sleep(myrank);

#if 1
    MPI_Type_size(MPI_CHAR, &size[0]);
    MPI_Type_size(MPI_INT, &size[1]);
    MPI_Type_size(MPI_FLOAT, &size[2]);
    MPI_Type_size(MPI_DOUBLE, &size[3]);

    for (int i = 0; i < 4; i++)
    {
        cout << "size of " << name[i] << " is: " << size[i] << endl;
    }

#endif

#if 1
    MPI_Type_extent(MPI_CHAR, &extent[0]);
    MPI_Type_extent(MPI_INT, &extent[1]);
    MPI_Type_extent(MPI_FLOAT, &extent[2]);
    MPI_Type_extent(MPI_DOUBLE, &extent[3]);

    for (int i = 0; i < 4; i++)
    {
        cout << "extent of " << name[i] << " is: " << extent[i] << endl;
    }
#endif

#if 1
    MPI_Type_lb(MPI_CHAR, &lb_disp[0]);
    MPI_Type_lb(MPI_INT, &lb_disp[1]);
    MPI_Type_lb(MPI_FLOAT, &lb_disp[2]);
    MPI_Type_lb(MPI_DOUBLE, &lb_disp[3]);

    for (int i = 0; i < 4; i++)
    {
        cout << "lb_disp of " << name[i] << " is: " << lb_disp[i] << endl;
    }
#endif

#if 1
    MPI_Type_ub(MPI_CHAR, &ub_disp[0]);
    MPI_Type_ub(MPI_INT, &ub_disp[1]);
    MPI_Type_ub(MPI_FLOAT, &ub_disp[2]);
    MPI_Type_ub(MPI_DOUBLE, &ub_disp[3]);

    for (int i = 0; i < 4; i++)
    {
        cout << "ub_disp of " << name[i] << " is: " << ub_disp[i] << endl;
    }
#endif

#if 1
    for (int i = 0; i < 3; i++)
    {
        MPI_Pack_size(i+1, MPI_INT, MPI_COMM_WORLD, &pack_size[i]);
        cout << "pack_size[" << i << "] = " << pack_size[i] << endl;
    }
#endif

    MPI_Finalize();
    return 0;
}

