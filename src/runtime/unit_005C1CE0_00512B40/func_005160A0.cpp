/* compiler: ee-gcc2.96-stl */
/* SGI STL partial_sort: handle and floating-point score.
   Reproduce with knowledge/recipes/scored_sort.py; public headers: THIRD_PARTY.md. */
#define __introsort_loop func_005C65E0
#define __unguarded_partition func_005C7988
#define __partial_sort func_005160A0
#define __insertion_sort func_005C7C48
#define sort_heap func_00517488
#define __make_heap func_005175C0
#define __adjust_heap func_00517668
#define __push_heap func_005C9550
#define __unguarded_linear_insert func_005C8E20
#define __unguarded_insertion_sort_aux func_005C7DF0
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_algo.h>

/* Existing game helpers: copy/destroy a handle, then retain/release an object. */
extern "C" void func_00128400(void *, const void *);
extern "C" void func_00128418(void *, int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);

struct RefCountedHandle_005C7AD8 {
    void *object;
    RefCountedHandle_005C7AD8(const RefCountedHandle_005C7AD8 &other) {
        func_00128400(this, &other);
    }
    ~RefCountedHandle_005C7AD8() { func_00128418(this, 2); }
    RefCountedHandle_005C7AD8 &operator=(const RefCountedHandle_005C7AD8 &other) {
        if (this != &other) {
            /* Retain first: distinct handles may refer to the same object. */
            void *incomingObject = other.object;
            if (incomingObject) func_002C0FE8(incomingObject);
            if (object) func_002C1050(object);
            object = incomingObject;
        }
        return *this;
    }
};

struct FloatSortEntry_005C7AD8 {
    RefCountedHandle_005C7AD8 handle;
    float score;
};
struct FloatScoreLess_005C7AD8 {
    /* The original ABI forwards this byte; an empty comparator differs. */
    char state;
    bool operator()(const FloatSortEntry_005C7AD8 &a,
                    const FloatSortEntry_005C7AD8 &b) const {
        return a.score < b.score;
    }
};
template void func_005160A0(FloatSortEntry_005C7AD8 *, FloatSortEntry_005C7AD8 *, FloatSortEntry_005C7AD8 *, FloatSortEntry_005C7AD8 *, FloatScoreLess_005C7AD8);
