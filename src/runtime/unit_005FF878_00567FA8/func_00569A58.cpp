/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_function.h>
#include <stl_tempbuf.h>
#include <stl_heap.h>
#include <stl_algo.h>
struct Entry { const char *name; int a; int b; };
extern "C" int func_004A8268(const char *, const char *);
struct NameLess {
    bool operator()(const Entry &e, const char *const &key) const { return func_004A8268(e.name, key) < 0; }
};
static inline void dist(Entry *f, Entry *l, int &n) { n = l - f; }
static inline void adv(Entry *&i, int n) { i += n; }
/* The out-of-line __lower_bound<Entry*, const char*, NameLess, int> of SGI stl_algo.h. */
extern "C" Entry *func_00569A58(Entry *__first, Entry *__last, const char *const *key) {
    const char *const &__val = *key;
    int __len;
    dist(__first, __last, __len);
    int __half;
    Entry *__middle = __first;
    while (__len > 0) {
        __half = __len >> 1;
        __middle = __first;
        adv(__middle, __half);
        if (NameLess()(*__middle, __val)) {
            __first = __middle;
            ++__first;
            __len = __len - __half - 1;
        } else
            __len = __half;
    }
    return __first;
}
