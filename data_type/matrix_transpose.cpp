// 利用自定义的列数据类型实现矩阵转秩
#include <iostream>
#include <mpi.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    int m, n;
    int *matrix, *trans_matrix;
    MPI_Datatype matrix_type, column_type, trans_matrix_type;
    fstream File;
    MPI_Status status;

    MPI_Init(&argc, &argv);

    if(argc != 3)
    {
        cout << "输入出错" << endl;
        MPI_Finalize();
        return 0;
    }

    m = atoi(argv[1]);
    n = atoi(argv[2]);

    matrix = new int[m*n];
    trans_matrix = new int[n*m];

    File.open("matrix.dat", ios::in|ios::out|ios::trunc);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i*n + j] = i*n + j;
            File << matrix[i*n + j] << "\t";
        }
        File << "\n";
    }

    File.close();

    MPI_Type_vector(m, 1, n, MPI_INT, &column_type);
    MPI_Type_commit(&column_type);

    for(int i = 0; i < n; i++)
    {
        MPI_Sendrecv(matrix + i, 1, column_type, 0, 99,
                trans_matrix + i*m, m, MPI_INT, 0, 99,
                MPI_COMM_SELF, &status);
    }

    MPI_Type_free(&column_type);

    File.open("trans_matrix.dat", ios::out|ios::trunc);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            File << trans_matrix[i*m + j] << "\t";
        }
        File << "\n";
    }

    File.close();

    delete matrix;
    delete trans_matrix;

    MPI_Finalize();
    return 0;
}


