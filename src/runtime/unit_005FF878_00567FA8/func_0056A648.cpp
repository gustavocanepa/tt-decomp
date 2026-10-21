/* compiler: ee-gcc2.96-stl */
/* SGI STL public sorting templates instantiated by tools/stl_algo.py.
   Value: 12 bytes; comparator: external; key: int at 0; member: push_heap. */
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_algo.h>
struct SortValue_005FCB08 { int words[3]; };
extern "C" bool func_0056AF98(const SortValue_005FCB08 *, const SortValue_005FCB08 *);
struct SortCompare_005FCB08 { char state; bool operator()(const SortValue_005FCB08 &a, const SortValue_005FCB08 &b) const { return func_0056AF98(&a, &b); } };
template void __push_heap(SortValue_005FCB08 *, int, int, SortValue_005FCB08, SortCompare_005FCB08);
