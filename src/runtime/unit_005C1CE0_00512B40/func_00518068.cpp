/* compiler: ee-gcc2.96-stl */
/* SGI STL push_heap: handle and floating-point score.
   Reproduce with knowledge/recipes/scored_sort.py; public headers: THIRD_PARTY.md. */
#define __introsort_loop func_005C65E0
#define __unguarded_partition func_005C7988
#define __partial_sort func_005C7AD8
#define __insertion_sort func_005C7C48
#define sort_heap func_005C8AA8
#define __make_heap func_005C8BE0
#define __adjust_heap func_005C8C88
#define __push_heap func_00518068
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
extern "C" void func_0013BD50(void *, const void *);
extern "C" void func_00128418(void *, int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);

struct RefCountedHandle_005C9550 {
    void *object;
    RefCountedHandle_005C9550(const RefCountedHandle_005C9550 &other) {
        func_0013BD50(this, &other);
    }
    ~RefCountedHandle_005C9550() { func_00128418(this, 2); }
    RefCountedHandle_005C9550 &operator=(const RefCountedHandle_005C9550 &other) {
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

struct FloatSortEntry_005C9550 {
    RefCountedHandle_005C9550 handle;
    float score;
};
struct FloatScoreLess_005C9550 {
    /* The original ABI forwards this byte; an empty comparator differs. */
    char state;
    bool operator()(const FloatSortEntry_005C9550 &a,
                    const FloatSortEntry_005C9550 &b) const {
        return a.score < b.score;
    }
};
template void func_00518068(FloatSortEntry_005C9550 *, int, int, FloatSortEntry_005C9550, FloatScoreLess_005C9550);
