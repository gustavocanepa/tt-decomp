/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

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

struct Object {
    char pad0[0x10];
    s32 state;
};

struct Item {
    Object *object;
    char pad4[0x10];
};

struct Owner {
    char pad0[0x80];
    vector<Item, GameAlloc<Item> > items;
    Object *single;
};

extern "C" void func_0013C4B0(Owner *self) {
    unsigned int i = 0;
    while (i < self->items.size()) {
        self->items[i].object->state = 0;
        ++i;
    }
    if (self->single != 0) {
        self->single->state = 0;
    }
}
