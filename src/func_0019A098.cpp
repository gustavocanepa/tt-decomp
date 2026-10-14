/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef unsigned int u32;
typedef char u8;
extern "C" void func_00575DA0(int p) throw();
extern "C" void *func_00575E60(int heap, int size);

template <class T>
class PlainAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc<U> other; };
    PlainAlloc() throw() {}
    PlainAlloc(const PlainAlloc &) throw() {}
    template <class U> PlainAlloc(const PlainAlloc<U> &) throw() {}
    ~PlainAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x40, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        func_00575DA0((int)p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct Vec { int a; char *start; char *finish; char *eos; };
struct VE1 { short off; short pad; s32 (*fn)(void *, char *); };
struct VE2 { short off; short pad; s32 (*fn)(void *, char *, char *, s32, s32); };
struct VE0 { short off; short pad; s32 (*fn)(void *); };
struct Strm { char *vtbl; };
extern "C" int func_004A6500(char *, const char *, ...);
extern "C" void func_005203E8(Vec *, char *, u32, const char *);
extern char D_005E67A0[];

extern "C" s32 func_0019A098(Vec *vec, Strm *st, s32 name) {
    char path[0x50];
    s32 bad = 0;
    s32 nm = name;
    func_004A6500(path, D_005E67A0, name, nm);
    VE1 *e1 = (VE1 *)(st->vtbl + 0x98);
    s32 n = e1->fn((char *)st + e1->off, path);
    VE0 *e2 = (VE0 *)(st->vtbl + 0x28);
    if (e2->fn((char *)st + e2->off) != 0 || n < 0) bad = 1;
    if (bad) return ((n ^ -2) == 0) ? 3 : 1;
    n = (n + 0x3F) & ~0x3F;
    char val = 0;
    const char *pv = &val;
    char *fin = vec->finish;
    u32 size = fin - vec->start;
    if ((u32)n < size) {
        char *first = vec->start + n;
        memmove(first, fin, 0);
        vec->finish = vec->finish - (fin - first);
    } else {
        func_005203E8(vec, fin, n - size, pv);
    }
    VE2 *e3 = (VE2 *)(st->vtbl + 0x90);
    e3->fn((char *)st + e3->off, path, vec->start, n, 0);
    VE0 *e4 = (VE0 *)(st->vtbl + 0x28);
    return e4->fn((char *)st + e4->off) != 0;
}
