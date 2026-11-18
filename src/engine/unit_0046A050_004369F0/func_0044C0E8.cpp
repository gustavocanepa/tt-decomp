/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
typedef unsigned char u8;
template<class T> class GameAlloc {
public:
 typedef size_t size_type; typedef ptrdiff_t difference_type;
 typedef T* pointer; typedef const T* const_pointer; typedef T& reference; typedef const T& const_reference; typedef T value_type;
 template<class U> struct rebind {typedef GameAlloc<U> other;};
 GameAlloc() throw() {} GameAlloc(const GameAlloc&) throw() {}
 template<class U> GameAlloc(const GameAlloc<U>&) throw() {}
 ~GameAlloc() throw() {}
 T* allocate(size_type n,const void * = 0);
 void deallocate(T*,size_type);
 size_type max_size() const throw(){return size_t(-1)/sizeof(T);}
 void construct(T*p,const T&v){new(p) T(v);} void destroy(T*p){p->~T();}
};
typedef vector<const u8 *, GameAlloc<const u8 *> > Vec;
template <> void Vec::insert(const u8 **, unsigned int, const u8 *const &) __asm__("func_0056CB90");
struct Obj { Vec v; const u8 *src; };

extern "C" void func_0044C0E8(Obj *o, const u8 *s) {
    o->src = s;
    if (s == 0) {
        o->v.clear();
        return;
    }
    const u8 *p = s + 2;
    unsigned n = s[0] + (s[1] << 8);
    o->v.resize(n);
    const u8 **out = o->v.begin();
    while (n-- > 0) {
        *out++ = p;
        while (*p++ != 0) {}
    }
}
