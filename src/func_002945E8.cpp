/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

extern "C" void func_002A75A8(void *, s32);

struct Elem {
    s32 value;
    ~Elem() { func_002A75A8(this, 2); }
};

template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type, const void * = 0);
    void deallocate(T *, size_type);
    size_type max_size() const throw() { return size_type(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct Owner {
    char pad0[0x10];
    vector<Elem, GameAlloc<Elem> > items;
    int flag;
};

extern "C" void func_002A9980(void *);
extern "C" void hArray__cleanup(Owner *self) {
    func_002A9980(self);
    if (self->flag == 0) {
        self->flag = 1;
        self->items.clear();
    }
}
