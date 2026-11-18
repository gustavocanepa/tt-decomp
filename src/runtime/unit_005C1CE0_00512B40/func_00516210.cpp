/* compiler: ee-gcc2.96-stl */
/* SGI STL insertion_sort: handle and floating-point score.
   Reproduce with knowledge/recipes/scored_sort.py; public headers: THIRD_PARTY.md. */
#define __introsort_loop func_005C65E0
#define __unguarded_partition func_005C7988
#define __partial_sort func_005C7AD8
#define __insertion_sort func_00516210
#define sort_heap func_005C8AA8
#define __make_heap func_005C8BE0
#define __adjust_heap func_005C8C88
#define __push_heap func_005C9550
#define __unguarded_linear_insert func_00517800
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

struct RefCountedHandle_005C7C48 {
    void *object;
    RefCountedHandle_005C7C48(const RefCountedHandle_005C7C48 &other) {
        func_00128400(this, &other);
    }
    ~RefCountedHandle_005C7C48() { func_00128418(this, 2); }
    RefCountedHandle_005C7C48 &operator=(const RefCountedHandle_005C7C48 &other) {
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

struct FloatSortEntry_005C7C48 {
    RefCountedHandle_005C7C48 handle;
    float score;
};
struct FloatScoreLess_005C7C48 {
    /* The original ABI forwards this byte; an empty comparator differs. */
    char state;
    bool operator()(const FloatSortEntry_005C7C48 &a,
                    const FloatSortEntry_005C7C48 &b) const {
        return a.score < b.score;
    }
};
template void func_00516210(FloatSortEntry_005C7C48 *, FloatSortEntry_005C7C48 *, FloatScoreLess_005C7C48);
