# Exercise 10

Create a 2-dimensional cartesian grid topology to communicate between processes.

In each task is initialized a variable with the local rank of the cartesian communicator. The exercise is divided in three steps:

**1)** Compare the local rank with the global MPI_COMM_WORLD rank. Are they the same number?

**2)** Calculate on each task the average between its local rank and the local rank from each of its neighbours (north, east, south, west). Notice that in order to do this the cartesian communicator has to be periodic (the bottom rank is neighbour of the top).

**3)** Calculate the average of the local ranks on each row and column. Create a family of sub-cartesian communicators to allow the communications between rows and columns.

## HINTS:

|    | **C** |
|----|-------|
| [MPI_DIMS_CREATE](https://www.open-mpi.org/doc/v3.1/man3/MPI_Dims_create.3.php) | int MPI_Dims_create(int nnodes, int ndims, int \*dims) |
| [MPI_CART_CREATE](https://www.open-mpi.org/doc/v3.1/man3/MPI_Cart_create.3.php) | int MPI_Cart_create(MPI_Comm comm_old, int ndims, int \*dims, int \*periods, int reorder, MPI_Comm \*comm_cart) |
| [MPI_CART_COORDS](https://www.open-mpi.org/doc/v3.1/man3/MPI_Cart_coords.3.php) | int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int \*coords) | MPI_CART_COORDS(COMM, RANK, MAXDIMS, COORDS, IERROR) <br> INTEGER COMM, RANK, MAXDIMS, COORDS(\*), IERROR |
| [MPI_CART_SHIFT](https://www.open-mpi.org/doc/v3.1/man3/MPI_Cart_shift.3.php) | int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int \*rank_source, int \*rank_dest) |
| [MPI_CART_SUB](https://www.open-mpi.org/doc/v3.1/man3/MPI_Cart_sub.3.php) | int MPI_Cart_sub(MPI_Comm comm, int \*remain_dims, MPI_Comm \*newcomm) |
| [MPI_COMM_FREE](https://www.open-mpi.org/doc/v3.1/man3/MPI_Comm_free.3.php) | int MPI_Comm_free(MPI_Comm \*comm) | 
| [MPI_SENDRECV](https://www.open-mpi.org/doc/v3.1/man3/MPI_Sendrecv.3.php) | int MPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status) | 
| [MPI_REDUCE](https://www.open-mpi.org/doc/v3.1/man3/MPI_Reduce.3.php) | int MPI_Reduce(void\* sendbuf, void\* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm) | 
| [MPI_INIT](https://www.open-mpi.org/doc/v3.1/man3/MPI_Init.3.php) | int MPI_Init(int \*argc, char \***argv) | 
| [MPI_COMM_SIZE](https://www.open-mpi.org/doc/v3.1/man3/MPI_Comm_size.3.php) | int MPI_Comm_size(MPI_Comm comm, int \*size) |
| [MPI_COMM_RANK](https://www.open-mpi.org/doc/v3.1/man3/MPI_Comm_rank.3.php) | int MPI_Comm_rank(MPI_Comm comm, int \*rank) |
| [MPI_FINALIZE](https://www.open-mpi.org/doc/v3.1/man3/MPI_Finalize.3.php) | int MPI_Finalize(void) |
