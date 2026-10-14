/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef char u8;
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

struct VE { short off; short pad; s32 (*fn)(void *, void *, void *, s32, s32); };
struct VE0 { short off; short pad; s32 (*fn)(void *); };
struct Stream { char *vtbl; };
extern "C" char *func_0019E868(void *, char *);
extern "C" s32 func_0019ECC8(void *);
extern "C" s32 func_001A3628(u8 *, s32, s32, s32, float, float);
extern "C" void func_0019E670(void *, u8 *);
extern "C" void func_0019B8F8(void *, s32);

extern "C" s32 func_0019EB20(void *arg0, Stream *st) {
    char buf[0x50];
    func_0019E868(arg0, buf);
    s32 n = (func_0019ECC8(arg0) + 0x3F) & -0x40;
    vector<u8, PlainAlloc<u8> > v((size_t)n);
    s32 i = 0;
    do {
        VE *e = (VE *)(st->vtbl + 0x90);
        e->fn((char *)st + e->off, buf, v.begin(), n, 0);
        VE0 *e2 = (VE0 *)(st->vtbl + 0x28);
        if (e2->fn((char *)st + e2->off) == 0) break;
        i++;
    } while (i < 3);
    if (i == 3) return 0;
    u8 *p = v.begin();
    if (func_001A3628(p, func_0019ECC8(arg0), 0, 1, 0x1.41b2f2p-2f, 0x1.dfe4p-2f) < 0) return 0;
    func_0019E670(arg0, p + 8);
    func_0019B8F8(arg0, 1);
    return 1;
}
