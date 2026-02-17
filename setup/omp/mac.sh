brew insall gcc
#check if gcc has omp support or not
gcc-15 -fopenmp -dM -E - < /dev/null | grep -i openmp
