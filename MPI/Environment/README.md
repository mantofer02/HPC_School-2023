# How to compile and run the exercises on Kabre

- After login, from this folder source the file environment.sh to load the necessary modules:
```
source environment.sh
```
- Copy the Makefile and the run.slurm file to the folder with your solution to the exercise and go there:
```
cp Makefile /path/to/solution
cp run.slurm /path/to/solution
cd /path/to/solution
```
- Edit the Makefile where indicated, specifying the names of the executable to create and the source code to compile. After that, run it with the command:
```
make
```
- Edit the jobscript run.slurm where indicated, with the name of the executable to launch. If required by the exercise, substitute "mpirun -n 4" with "mpirun -n 2". After that, submit the job with the command:
```
sbatch run.slurm
```

- When the job is over, check the .err file for any eventual error during the execution, and the file .out for the standard output, to be compared with your expectations.
