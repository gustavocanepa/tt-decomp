/* compiler: ee-gcc2.96-stl */
/* Constructor of a network object that owns a map<int, int> (SGI STL, memalign allocator): the
   map's default constructor is inlined, with its _Compare() and allocator_type() temporaries. */
extern "C" void free(void*) throw();
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
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};


struct Item;
typedef pair<const unsigned, Item*> Value;
typedef GameAlloc<Value> Alloc;
typedef _Rb_tree<unsigned, Value, _Select1st<Value>, less<unsigned>, Alloc> Tree;
typedef map<unsigned, Item*, less<unsigned>, Alloc> Map;
extern "C" Tree::iterator func_0056F540(Tree*,const unsigned&);
template<> inline Tree::iterator Tree::find(const unsigned &k) { return func_0056F540(this,k); }
struct Owner { char pad[12]; Map map; };
extern "C" void func_00487AB8(Owner *s, unsigned key) {
 Map::iterator it = s->map.find(key);
 if (it != s->map.end()) s->map.erase(it);
}
