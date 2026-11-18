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

extern char D_005E6EE8[];
struct Self { char pad0[0x78]; char name[0x20]; };
struct Src { int a; char *start; char *finish; };
extern "C" long long func_0019CC58(void);
extern "C" void func_004A6500(char *, const char *, ...);
extern "C" s32 func_0019E8E8(Self *, void *);
extern "C" Src *func_002CD168(void *);
extern "C" void *func_004F64C4(void *, const void *, unsigned int);
extern "C" void func_001A34E0(u8 *, s32, s32, s32, float, float);
extern "C" s32 func_0019C308(Self *, void *, u8 *, s32, s32);

extern "C" s32 func_001A1528(Self *self, void *arg1, void *arg2, s32 arg3) {
    long long t = func_0019CC58();
    volatile long long keep;
    keep = t;
    int hi = (int)(t >> 32) & 0x1FFFF;
    func_004A6500(self->name, D_005E6EE8, hi);
    if (!func_0019E8E8(self, arg1)) return 1;
    Src *src = func_002CD168(arg2);
    s32 n = src->finish - src->start;
    vector<u8, PlainAlloc<u8> > v((size_t)((n + 0x47) & -0x40));
    u8 *p = v.begin();
    func_004F64C4(p + 8, src->start, n);
    func_001A34E0(p, n, 0, 0, 0x1.5c9eecp-1f, 0x1.9db22cp-2f);
    return func_0019C308(self, arg1, v.begin(), v.end() - v.begin(), arg3) == 0;
}
