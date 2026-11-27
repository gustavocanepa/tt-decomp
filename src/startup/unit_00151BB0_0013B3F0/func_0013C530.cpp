/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
struct Target { char pad[0x20]; s32 flag; };
struct Elem { Target *target; char pad[16]; };

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
    char pad0[0x80];
    vector<Elem, GameAlloc<Elem> > items;
    Target *current;
};

extern "C" void func_0013C530(Owner *self, s32 flag) {
    unsigned int i = 0;
    while (i < self->items.size()) {
        self->items[i].target->flag = flag;
        ++i;
    }
    if (self->current != 0)
        self->current->flag = flag;
}
