/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_function.h>
#include <stl_tempbuf.h>
#include <stl_heap.h>
#include <stl_algo.h>
/* a 16-byte polymorphic element; the functor is a pointer to one of its member functions */
struct Elem {
    virtual void method();
    int pad[3];
};
struct Call {
    int unused;
    void (Elem::*pmf)();
    void operator()(Elem &e) const { (e.*pmf)(); }
};
/* func_00567FA8: for_each(first, last, Call) of SGI stl_algo.h */
template Call for_each(Elem *, Elem *, Call);
