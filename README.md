# Configuration

You'll need to have `valgrind` installed and ensure that `cachegrind` is included as a part of your `valgrind` installation. Simply run `./run.sh <example/plain/aware/oblivious>` and the script will automatically compile your program, simulate it with `cachegrind`, and open the resulting file in VS Code. 

Note that `cachegrind` automatically detects the cache size on your machine and run simulations accordingly. The experiments in class were ran on `fern`, a 4-socket NUMA machine with 4 Xeon Platinum 8160 CPUs. Its L1 data cache has 32768 bytes with 64-byte blocks and is 8-way set associative. Its L3 cache (or LL cache) has 35651584 bytes with 64-byte blocks and is 17-way set associative. The L3 cache configuratino is very weird, especially compared with the size of the L2 cache if [wikichip](https://en.wikichip.org/wiki/intel/xeon_platinum/8160) is to be trusted. You can look at `run.sh`, which tells you how to specify the cache size using `--D1` and and `--LL` if you want to repeat the cache configurations in class.

# Compiler explorer

You can go to [godbolt](https://godbolt.org/) to see how your C++ code compiles to assembly. Just copy-paste your code on the left and the assembly will show up on the right. I recommend using the newest version of x86-64 clang or gcc. You can compile it to other assembly languages, but your code is most likely to be ran on a x86 machine (unless you're runing it on a mac or a phone), so the x86 assembly correlates most closely with performance. You also want to add `-O2` to compiler options, since the actual code should at least go through this much optimization. `-O3` tends to produce longer assembly code, making it less readable, and is also prone to produce code with worse performance (e.g. loop unrolling resulting in more instruction cache misses), so it's probably less helpful than `-O2`. 

# Sidenote

Here's [an email from sqlite's author about optimizations with cachegrind](https://www.mail-archive.com/sqlite-users@mailinglists.sqlite.org/msg86235.html). It specifically talks about counting the number of instructions after each optimization. Small optimizations eventually add up and gave a large performance boost. 
