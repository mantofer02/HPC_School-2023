#!/bin/sh

#SBATCH --job-name=solution
#SBATCH --partition=nu-wide
#SBATCH --ntasks=4
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=4
#SBATCH --cpus-per-task=64
#SBATCH --time=03:00:00

#SBATCH --output=output_%j.out
#SBATCH --error=output_%j.err

PROGRAM=solution


mpirun -n 2 ./${PROGRAM}
