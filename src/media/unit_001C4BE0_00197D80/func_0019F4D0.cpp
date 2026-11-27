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

struct VE0 { short off; short pad; s32 (*fn)(void *); };
struct Self { char pad0[0x4C]; char *vtbl; };
extern "C" s32 func_0019E8E8(Self *, void *);
extern "C" s32 func_0042F830(s32);
extern "C" s32 func_0042F4F8(s32);
extern "C" s32 func_0042F758(s32, void *);
extern "C" void func_0042F870(s32);
extern "C" void func_001A34E0(u8 *, s32, s32, s32, float, float);
extern "C" s32 func_0019C308(Self *, void *, u8 *, s32, s32);

extern "C" s32 func_0019F4D0(Self *self, void *arg1, s32 arg2, s32 arg3) {
    if (!func_0019E8E8(self, arg1)) return 1;
    VE0 *e = (VE0 *)(self->vtbl + 0x150);
    s32 id = func_0042F830(e->fn((char *)self + e->off));
    s32 len = func_0042F4F8(id);
    vector<u8, PlainAlloc<u8> > v((size_t)((len + 0x47) & -0x40));
    u8 *p = v.begin();
    func_0042F758(id, p + 8);
    func_0042F870(id);
    func_001A34E0(p, len, 0, 0, 0x1.d67dfp-3f, 0x1.644622p-1f);
    return func_0019C308(self, arg1, p, v.end() - v.begin(), arg3) == 0;
}
