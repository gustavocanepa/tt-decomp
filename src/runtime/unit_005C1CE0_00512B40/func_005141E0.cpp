/* compiler: ee-gcc2.96-stl */
/* SGI STL introsort_loop: handle and floating-point score.
   Reproduce with knowledge/recipes/scored_sort.py; public headers: THIRD_PARTY.md. */
#define __introsort_loop func_005141E0
#define __unguarded_partition func_00515F50
#define __partial_sort func_005160A0
#define __insertion_sort func_005C7C48
#define sort_heap func_005C8AA8
#define __make_heap func_005C8BE0
#define __adjust_heap func_005C8C88
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
extern "C" void func_0013BD68(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

struct RefCountedHandle_005C65E0 {
    void *object;
    RefCountedHandle_005C65E0(const RefCountedHandle_005C65E0 &other) {
        func_00128400(this, &other);
    }
    ~RefCountedHandle_005C65E0() { func_0013BD68(this, 2); }
    RefCountedHandle_005C65E0 &operator=(const RefCountedHandle_005C65E0 &other) {
        if (this != &other) {
            /* Retain first: distinct handles may refer to the same object. */
            void *incomingObject = other.object;
            if (incomingObject) func_003285A8(incomingObject);
            if (object) func_003285F8(object);
            object = incomingObject;
        }
        return *this;
    }
};

struct FloatSortEntry_005C65E0 {
    RefCountedHandle_005C65E0 handle;
    float score;
};
struct FloatScoreLess_005C65E0 {
    /* The original ABI forwards this byte; an empty comparator differs. */
    char state;
    bool operator()(const FloatSortEntry_005C65E0 &a,
                    const FloatSortEntry_005C65E0 &b) const {
        return a.score < b.score;
    }
};
template void func_005141E0(FloatSortEntry_005C65E0 *, FloatSortEntry_005C65E0 *, FloatSortEntry_005C65E0 *, int, FloatScoreLess_005C65E0);
