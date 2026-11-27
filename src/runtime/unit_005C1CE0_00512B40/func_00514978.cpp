/* compiler: ee-gcc2.96-stl */
/* SGI STL introsort_loop: handle and string key.
   Reproduce with knowledge/recipes/scored_sort.py; public headers: THIRD_PARTY.md. */
#define __introsort_loop func_00514978
#define __unguarded_partition func_00516430
#define __partial_sort func_00516560
#define __insertion_sort func_005C80F0
#define sort_heap func_005C8F18
#define __make_heap func_005C9050
#define __adjust_heap func_005C90F8
#define __push_heap func_005C9698
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
extern "C" void func_00128400(void *, const void *);
extern "C" void func_0013BD68(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

struct RefCountedHandle_005C6DA8 {
    void *object;
    RefCountedHandle_005C6DA8(const RefCountedHandle_005C6DA8 &other) {
        func_00128400(this, &other);
    }
    ~RefCountedHandle_005C6DA8() { func_0013BD68(this, 2); }
    RefCountedHandle_005C6DA8 &operator=(const RefCountedHandle_005C6DA8 &other) {
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

extern "C" int func_004A8268(const char *, const char *);

struct StringSortEntry_005C6DA8 {
    RefCountedHandle_005C6DA8 handle;
    const char *key;
};
struct StringKeyLess_005C6DA8 {
    /* The original ABI forwards this byte; an empty comparator differs. */
    char state;
    bool operator()(const StringSortEntry_005C6DA8 &a,
                    const StringSortEntry_005C6DA8 &b) const {
        return func_004A8268(a.key, b.key) < 0;
    }
};
template void func_00514978(StringSortEntry_005C6DA8 *, StringSortEntry_005C6DA8 *, StringSortEntry_005C6DA8 *, int, StringKeyLess_005C6DA8);
