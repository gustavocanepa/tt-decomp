/* compiler: ee-gcc2.96-stl */
/* SGI STL public sorting templates instantiated by tools/stl_algo.py.
   Value: 8 bytes, alignment 4; comparator: pointer; key: int at 0; member: adjust_heap. */
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_algo.h>
struct SortValue_005F45E0 { int words[2]; };
typedef bool (*SortCompare_005F45E0)(const SortValue_005F45E0 &, const SortValue_005F45E0 &);
template void __adjust_heap(SortValue_005F45E0 *, int, int, SortValue_005F45E0, SortCompare_005F45E0);
