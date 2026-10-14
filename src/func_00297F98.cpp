/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
extern "C" void func_002C1050(void*);
template<class T>struct Alloc {typedef size_t size_type;typedef ptrdiff_t difference_type;typedef T*pointer;typedef const T*const_pointer;typedef T&reference;typedef const T&const_reference;typedef T value_type;template<class U>struct rebind{typedef Alloc<U>other;};Alloc()throw(){} Alloc(const Alloc&)throw(){}template<class U>Alloc(const Alloc<U>&)throw(){}~Alloc()throw(){} T*allocate(size_type n,const void * =0);void deallocate(T*p,size_type n);size_type max_size()const throw(){return size_t(-1)/4;}void construct(T*p,const T&x){new(p)T(x);}void destroy(T*p){p->~T();}};

typedef vector<void*,Alloc<void*> > Vec;
struct Obj{char pad[44];Vec v;};
extern "C" void func_00297F98(Obj*self){
 for(void**p=self->v.begin();p!=self->v.end();p++)func_002C1050(*p);
 self->v.erase(self->v.begin(),self->v.end());
}
