/* compiler: ee-gcc2.96-stl */
#include "stl/stl_tree.h"
#include "stl/stl_map.h"
extern "C" void *func_00575E60(int,int);

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

struct Val { short pad; unsigned short cnt; };
typedef pair<const unsigned,Val *> Pair;
typedef _Rb_tree<unsigned,Pair,_Select1st<Pair>,less<unsigned>,GameAlloc<Pair> > Tree;
typedef map<unsigned,Val *,less<unsigned>,GameAlloc<Pair> > Map;
typedef Tree::iterator It;
struct Obj { char pad[4]; char list[8]; Map m; };
extern "C" It func_0056F540(Tree *,const unsigned &);
template <> inline It Tree::find(const unsigned &k) { return func_0056F540(this,k); }
extern "C" void func_0056F490(void *, Val **);
extern "C" Val *func_004877A8(Obj *self, unsigned key) {
 Val *v;
 Map::const_iterator it = self->m.find(key);
 if (it == self->m.end()) return 0;
 v = (*it).second;
 if (v->cnt == 0) func_0056F490(self->list, &v);
 v->cnt = v->cnt + 1;
 return v;
}
