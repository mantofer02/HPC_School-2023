#include <iostream>
#include <mpi.h>

using namespace std;

int main (int argc, char* argv[]){


  int my_id, num_procs, inserted_num,modified_num;
  

  MPI_Init(&argc, &argv);	/* starts MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &my_id);	/* get current process id */
  MPI_Comm_size (MPI_COMM_WORLD, &num_procs);	/* get number of processes */
  

  cout << "my_id is " << my_id << " and modified_num before broadcast is " << modified_num << endl; /* not initialized value!!! */

  if(my_id == 0) {
    /* cout << "Insert an integer value: " << endl;     In case of interactive run */
    /* cin >> inserted_num;  */

    inserted_num=57;
    cout << "Inserted num is : " << inserted_num << endl;
    modified_num = inserted_num*inserted_num ;
  }

  else {
    inserted_num=0;
    modified_num=0;
  }

 MPI_Bcast(&modified_num, 1, MPI_INT, 0, MPI_COMM_WORLD);
  
  cout << "my_id is " << my_id << ",inserted_num is " << inserted_num << " and modified_num is " << modified_num << endl;

  MPI_Finalize();
  return 0;
}
