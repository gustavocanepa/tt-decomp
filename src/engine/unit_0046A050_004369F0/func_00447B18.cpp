/* compiler: ee-gcc2.96-stl */
/* vector<Val>::clear() (SGI STL include/stl/stl_vector.h, erase(begin(), end()) inlined) on a list of script values. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

struct Val;
extern "C" void func_0043D510(Val *) throw();
extern "C" Val *func_00476768(Val *, const Val *);

struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_00476768(this, &o); }
    ~Val() { func_0043D510(this); }
};

extern "C" void *func_004A4690(int align, int size);

template <class T>
class ValAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef ValAlloc<U> other; };
    ValAlloc() throw() {}
    ValAlloc(const ValAlloc &) throw() {}
    template <class U> ValAlloc(const ValAlloc<U> &) throw() {}
    ~ValAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) { return n ? (T *)func_004A4690(16, n * sizeof(T)) : 0; }
    void deallocate(T *p, size_type) { free(p); }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct S {
    vector<Val, ValAlloc<Val> > v;
    unsigned n;
    S(unsigned bytes) __asm__("func_00447B18");
};
S::S(unsigned bytes) : n(bytes >> 3) {
    v.reserve(n);
}
