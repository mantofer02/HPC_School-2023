#!/bin/bash
#SBATCH --job-name=test
#SBATCH -N 1
#SBATCH --ntasks-per-node=4   ###Edit that to decide the number of MPI tasks of your job
#SBATCH --cpus-per-task=4     ###Edit that to decide the number of OpenMP threads for any task
#SBATCH -p nu-wide
#SBATCH -t 1:00:00

module load mpich/3.3.2-gcc-9.3.0
module load gcc/9.3.0

#export OMP_PLACES=cores
#export OMP_NUM_THREADS=4
time mpirun -n 4 ./jacobi-mpi.x 300 300
