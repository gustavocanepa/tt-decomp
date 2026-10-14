/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
template<class I,class T> class _Temporary_buffer;
#include <stl_algo.h>
#include <stl_list.h>
struct Str { char *p; };
struct Item { char pad[0x54]; Str name; };
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
extern "C" int func_0056B960(Str *, Str *, unsigned, unsigned);
struct Pred { int a; Str *key; Pred(Str *p):key(p) {} bool operator()(const Val &v) const { return func_0056B960(&v.item->name,key,0,-1)==0; } };
static inline It search_impl(It first, It last, Pred pred) {
 for(;first != last;++first) {
  if(pred(*first)) break;
 }
 return first;
}
static inline It search(It first, It last, Pred pred) { return search_impl(first,last,pred); }
extern "C" Item *func_004475D8(Owner *o, Str *key) {
 List::const_iterator first=search(o->items.begin(),o->items.end(),Pred(key));
 Item *result=0;
 if(first!=List::const_iterator(o->items.end())) result=first->item;
 return result;
}
