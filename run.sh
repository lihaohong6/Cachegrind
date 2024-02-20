[ $# -ne 1 ] && echo "Need an argument specifying file name" && exit 1
./clean.sh
g++ -O2 -g -o $1 $1.cpp -std=c++17 && \
  echo "Compilation done. Running" && \
  chmod 544 $1 && \
  valgrind --tool=cachegrind --cache-sim=yes --cachegrind-out-file=cachegrind-$1.raw ./$1 && \
  cg_annotate --show=D1mr,D1mw,DLmr,DLmw cachegrind-$1.raw > cachegrind-$1.out && \
  code cachegrind-$1.out