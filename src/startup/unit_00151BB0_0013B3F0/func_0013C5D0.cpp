/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
extern "C" void func_001CE638(void *, const void *);
extern "C" void func_001CE650(void *, s32);

struct Elem {
    s32 value;
    Elem(const Elem &other) { func_001CE638(this, &other); }
    ~Elem() { func_001CE650(this, 2); }
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

typedef vector<Elem, GameAlloc<Elem> > BaseVector;
extern "C" void func_00518668(void *, Elem *, const Elem *);

struct Items : BaseVector {
    void push_back_native(const Elem &value) {
        if (_M_finish != _M_end_of_storage) {
            if (_M_finish != 0)
                construct(_M_finish, value);
            ++_M_finish;
        } else {
            func_00518668(this, _M_finish, &value);
        }
    }
};

struct Owner {
    char pad0[0x70];
    Items items;
};

extern "C" void func_0013C5D0(Owner *self, Elem *value) {
    self->items.push_back_native(*value);
    value->~Elem();
}
