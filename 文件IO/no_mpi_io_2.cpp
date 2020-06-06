#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <mpi.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
    int myrank;

    ifstream input_file;
    ofstream output_file;

    string file;
    string rline;
    istringstream istr;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    sleep(myrank);

    file = "file" + to_string(myrank);

    output_file.open(file);

    output_file << "Myrank = " << myrank << "\n";
    output_file << "Process id = " << getpid() << "\n";

    output_file.close();

    input_file.open(file);

    getline(input_file, rline);
    cout << rline << endl;
    getline(input_file, rline);
    cout << rline << endl;

    input_file.close();

    MPI_Finalize();

    return 0;
}
