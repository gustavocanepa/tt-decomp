/* compiler: ee-gcc2.96-stl */
/* SGI STL heap adjustment for a 12-byte aggregate and a one-byte comparator. */
#include <stl_algobase.h>
#include <stl_heap.h>
struct Heap12 { int words[3]; };
extern "C" bool func_0056AF98(const Heap12 *,const Heap12 *);
struct Heap12Compare { char state; bool operator()(const Heap12 &a,const Heap12 &b) const { return func_0056AF98(&a,&b); } };
template void __adjust_heap(Heap12 *,int,int,Heap12,Heap12Compare);
