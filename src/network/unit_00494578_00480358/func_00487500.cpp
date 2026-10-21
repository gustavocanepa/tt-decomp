/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_pair.h>
#define protected public
#define private public
#include <stl_list.h>
#include <stl_tree.h>
#undef protected
#undef private
extern "C" void *func_00575E60(int,int);
extern "C" void *func_00578CF0(int,int);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" void *func_005C1498(unsigned);
template<class T> struct A {
 typedef unsigned size_type; typedef int difference_type;
 typedef T* pointer; typedef const T* const_pointer;
 typedef T& reference; typedef const T& const_reference; typedef T value_type;
 template<class U> struct rebind { typedef A<U> other; };
 A() throw() {} A(const A&) throw() {} template<class U> A(const A<U>&) throw() {}
 T *allocate(unsigned n,const void * =0) { return n ? (T*)func_00575E60(16,n*sizeof(T)) : 0; }
 void deallocate(T*,unsigned);
 void construct(T*p,const T&v) { new(p) T(v); }
 void destroy(T*p) { p->~T(); }
};
struct Node { Node *next; Node *prev; void *data; Node *right; };
typedef list<void *, A<void *> > List;
struct Tree { int pad; Node *head; int count; int extra; };
struct Obj { int pad; List list; Tree tree; void *data; };
extern "C" void func_004A45D0(void *) throw();
extern "C" void func_0050E1A8(void *) throw();
extern "C" void func_0056F248(List *);
extern "C" void func_0056F2A8(Tree *, Node *);
static inline void clear(Tree *t) {
    if (t->count) {
        func_0056F2A8(t, t->head->prev);
        t->head->data = t->head;
        t->head->prev = 0;
        t->head->right = t->head;
        t->count = 0;
    }
}
extern "C" void func_00487500(Obj *self, int flags) {
    List *l = &self->list;
    for (List::const_iterator i = l->begin(); i != l->end(); i++) {
        func_0050E1A8(*i);
    }
    func_0056F248(l);
    Tree *t = &self->tree;
    clear(t);
    func_004A45D0(self->data);
    clear(t);
    func_004A45D0(t->head);
    func_0056F248(l);
    func_004A45D0(l->_M_node);
    if (flags & 1) func_0050E1A8(self);
}
