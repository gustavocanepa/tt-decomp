/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_tempbuf.h>
#include <stl_heap.h>
#include <stl_algo.h>
struct Value { long long data; };
extern "C" void func_0051A888(Value *first, Value *last, int unused0) {
    while (true)
        if (first == last || first == --last) return;
        else iter_swap(first++, last);
}
