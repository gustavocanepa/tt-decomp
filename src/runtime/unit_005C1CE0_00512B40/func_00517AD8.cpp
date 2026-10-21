/* compiler: ee-gcc2.96-stl */
/* SGI STL adjust_heap: handle and string key.
   Reproduce with knowledge/recipes/scored_sort.py; public headers: THIRD_PARTY.md. */
#define __introsort_loop func_005C6DA8
#define __unguarded_partition func_005C7E68
#define __partial_sort func_005C7F98
#define __insertion_sort func_005C80F0
#define sort_heap func_005C8F18
#define __make_heap func_005C9050
#define __adjust_heap func_00517AD8
#define __push_heap func_005181B0
#define __unguarded_linear_insert func_005C9288
#define __unguarded_insertion_sort_aux func_005C8288
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_algo.h>

/* Existing game helpers: copy/destroy a handle, then retain/release an object. */
extern "C" void *func_00128400(void *, const void *);
extern "C" void func_00128418(void *, int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);

struct RefCountedHandle_005C90F8 {
    void *object;
    RefCountedHandle_005C90F8(const RefCountedHandle_005C90F8 &other) {
        func_00128400(this, &other);
    }
    ~RefCountedHandle_005C90F8() { func_00128418(this, 2); }
    RefCountedHandle_005C90F8 &operator=(const RefCountedHandle_005C90F8 &other) {
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

extern "C" int func_004A8268(const char *, const char *);

struct StringSortEntry_005C90F8 {
    RefCountedHandle_005C90F8 handle;
    const char *key;
};
struct StringKeyLess_005C90F8 {
    /* The original ABI forwards this byte; an empty comparator differs. */
    char state;
    bool operator()(const StringSortEntry_005C90F8 &a,
                    const StringSortEntry_005C90F8 &b) const {
        return func_004A8268(a.key, b.key) < 0;
    }
};
template void func_00517AD8(StringSortEntry_005C90F8 *, int, int, StringSortEntry_005C90F8, StringKeyLess_005C90F8);
