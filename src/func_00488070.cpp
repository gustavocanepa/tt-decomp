/* compiler: ee-gcc2.96-stl */
/* Constructor of a network object that owns a map<int, int> (SGI STL, memalign allocator): the
   map's default constructor is inlined, with its _Compare() and allocator_type() temporaries. */
#include <stl_tree.h>
#include <stl_map.h>

typedef unsigned char u8;

extern "C" void *func_00575E60(int heap, int size);
extern "C" void *func_005C1498(int);

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
    T *allocate(size_type n, const void * = 0) {
        return n != 0 ? (T *)func_00575E60(0x10, n * sizeof(T)) : 0;
    }
    void deallocate(T *p, size_type n) {
        func_00575DA0(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct Item { unsigned short flags; };
typedef pair<const int, Item *> Value;
typedef map<int, Item *, less<int>, GameAlloc<Value> > Map;
struct S { char pad[0xc]; Map m; };
extern "C" int func_00487640(void *, Item *, void *) throw();
extern "C" void func_00488070(S *self) {
    for (Map::const_iterator it = self->m.begin(); it != self->m.end(); it++) {
        Item *item = (*it).second;
        if ((unsigned short)(item->flags & 1)) func_00487640(self, item, 0);
    }
}
