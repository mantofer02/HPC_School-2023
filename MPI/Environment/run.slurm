#!/bin/sh

#SBATCH --job-name=my_test
#SBATCH --partition=nu-wide
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=4
#SBATCH --time=03:00:00

#SBATCH --output=output_%j.out
#SBATCH --error=output_%j.err

PROGRAM=solution_01    ### EDIT THIS with the name of your compiled executable!! Have you compiled it first?


mpirun -n 4 ./${PROGRAM}
