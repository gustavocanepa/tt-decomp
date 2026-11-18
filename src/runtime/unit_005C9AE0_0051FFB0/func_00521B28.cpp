/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
extern "C" void func_004A45D0(int p) throw();
extern "C" void *func_004A4690(int heap, int size);

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
        return n == 0 ? 0 : (T *)func_004A4690(0x40, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        func_004A45D0((int)p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

extern "C" u16 *func_005151C8(u16 *, unsigned int, const u16 &) throw();
template <> inline u16 *fill_n(u16 *p, unsigned int n, const u16 &v) throw() { return func_005151C8(p, n, v); }
typedef vector<u16, PlainAlloc<u16> > Vec;
struct Desc { u32 cap; u32 off; };
extern "C" float func_004B28D8(void *);
static inline void shuffle(void *ctx, u32 n, void *rng, void (*cb)(void *,u32,u32), char c) {
    (void)&c;
    Vec v((Vec::size_type)(n - 1));
    for (u32 k=n-1; k != 0; --k) {
        v[k-1] = (u16)(int)(func_004B28D8(rng) * (float)(k+1));
    }
    for (u32 i=1; i<n; ++i) cb(ctx,i,v[i-1]);
}

extern "C" void func_00521B28(void *ctx, u32 n, void *rng, void (*cb)(void *,u32,u32), char c) { shuffle(ctx,n,rng,cb,c); }
