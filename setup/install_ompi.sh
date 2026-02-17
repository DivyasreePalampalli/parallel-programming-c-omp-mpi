PREFIX=
CC=
CXX=
FC=
FLAGS="-O3 -march=znver4 -fopenmp -fPIC -ffast-math"

wget hhttps://download.open-mpi.org/release/open-mpi/v4.1/openmpi-4.1.0.tar.gz
tar -xzf openmpi-4.1.0.tar.gz
cd openmpi-4.1.0
./configure --prefix=$PREFIX CC=${CC} CXX=${CXX} FC=${FC} CFLAGS="$FLAGS" CXXFLAGS="$FLAGS" FCFLAGS="$FLAGS"
make -j
make install
export PATH=$HOME$PREFIX/bin:$PATH

