/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
template<class I,class T> class _Temporary_buffer;
#include <stl_algo.h>
#include <stl_list.h>
struct Item { char pad[0x50]; int pos; };
struct Val { Item *item; int b,c; };
template <class T>
class Alloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() throw() {}
    Alloc(const Alloc &) throw() {}
    template <class U> Alloc(const Alloc<U> &) throw() {}
    ~Alloc() throw() {}
    T *allocate(size_type n, const void * = 0);
    void deallocate(T *p, size_type n);
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef list<Val, Alloc<Val> > List;
typedef List::iterator It;
struct Owner { char pad[0xA4]; List items; };
struct Pred {int a; Item *key; Pred(Item *p):key(p) {} bool operator()(const Val &v) const {return v.item==key;} };
static inline void swapval(Val &a,Val &b) { swap(a.item,b.item);swap(a.b,b.b);swap(a.c,b.c); }
extern "C" void func_004478B8(Owner *o,Item *a,Item *b) {
 It first=find_if(o->items.begin(),o->items.end(),Pred(a));
 if(first==o->items.end()) return;
  It second=find_if(o->items.begin(),o->items.end(),Pred(b));
  if(second==o->items.end()) return;
   swapval(*first,*second);
   int t=(*first).item->pos;
   (*first).item->pos=(*second).item->pos;
   (*second).item->pos=t;
}
