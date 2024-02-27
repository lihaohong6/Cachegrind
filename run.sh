[ $# -ne 1 ] && echo "Need an argument specifying file name" && exit 1
# use gdwarf-4 since valgrind can't read DWARF 5 debugging symbols
g++ -gdwarf-4 -g -O2 -o $1 $1.cpp -std=c++17 && \
  echo "Compilation done. Running" && \
  chmod 544 $1 && \
  # Cache size on fern: --D1=32768,8,64 --LL=35651584,17,64
  valgrind --tool=cachegrind --cache-sim=yes --cachegrind-out-file=cachegrind-$1.raw ./$1 && \
  # only show data cache data; ignore instructions
  cg_annotate --show=Dr,Dw,D1mr,D1mw,DLmr,DLmw cachegrind-$1.raw > cachegrind-$1.out && \
  code cachegrind-$1.out
