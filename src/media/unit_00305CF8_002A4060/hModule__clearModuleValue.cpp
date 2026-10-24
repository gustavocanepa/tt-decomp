/* compiler: ee-gcc2.96-stl */
#include <stl_tree.h>
#include <stl_map.h>
template <class T> struct GameAlloc {
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    template<class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template<class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type, const void * = 0);
    void deallocate(T *, size_type);
};
struct Hd {
    int v;
    Hd(const Hd &o) : v(o.v) {}
    Hd &operator=(const Hd &o) { if (this != &o) v = o.v; return *this; }
};
typedef pair<const unsigned int, int> Value;
typedef _Rb_tree_node<Value> Node;
typedef _Rb_tree<unsigned int, Value, _Select1st<Value>, less<unsigned int>, GameAlloc<Value> > Tree;
typedef map<unsigned int, int, less<unsigned int>, GameAlloc<Value> > Map;
extern "C" void func_0054B968(Tree *, Node *);
template <> inline void Tree::_M_erase(Node *x) { func_0054B968(this, x); }
struct M { char pad[0x10]; Hd h; char pad14[4]; Map t; };
extern Hd D_0057C5D0;
extern "C" void func_002A4348(M *, const unsigned int *) throw();
extern "C" void hModule__clearModuleValue(M *self) {
    Hd *h = &self->h;
    if (h->v == D_0057C5D0.v) return;
    Hd saved = *h;
    *h = D_0057C5D0;
    Map::iterator it = self->t.begin();
    Map::iterator end = self->t.end();
    for (; it != end; it++) {
        func_002A4348(self, &(*it).first);
    }
    self->t.clear();
    *h = saved;
}
