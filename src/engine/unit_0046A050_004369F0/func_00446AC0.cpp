/* compiler: ee-gcc2.96-stl */

#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_list.h>

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

struct ItemData { char pad[0x5C]; };
struct Item : ItemData {
    virtual void v0();
    virtual void update(int a, int b);
};

struct Count { char pad[0x20]; int n; };
struct Owner {
    char pad[0x60];
    Count *c60;
    int f64;
    int f68;
    int f6C;
    int f70;
    char pad2[0xA4 - 0x74];
    list<Item *, Alloc<Item *> > items;
};

extern "C" void func_00444128(void);
extern "C" void func_00447118(Owner *);
extern "C" void func_00446E60(Owner *, int);
extern "C" void func_00446A40(Owner *);
extern "C" void func_00446C20(Owner *, int);

extern "C" void func_00446AC0(Owner *o, int a) {
    func_00444128();
    func_00447118(o);
    func_00446E60(o, a);
    int upd = 0;
    if (o->f68 >= 0) {
        func_00446A40(o);
        o->f6C = 0;
        upd = 1;
    } else if (o->f70 == 0) {
        upd = 1;
        o->f64 = o->f64 + 1;
    }
    if (o->f64 >= o->c60->n) {
        o->f64 = 0;
        o->f6C = 0;
    }
    if (upd != 0)
        func_00446C20(o, a);
    for (list<Item *, Alloc<Item *> >::reverse_iterator it = o->items.rbegin(); it != o->items.rend(); ++it) {
        (*it)->update(a, o->f64);
    }
}
