/* compiler: ee-gcc2.96-stl */
#define __introsort_loop func_005487A8
#define __unguarded_partition func_00548BC0
#define __partial_sort func_00548D10
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_alloc.h>
#include <stl_vector.h>
#include <stl_algo.h>

struct RefObject;
extern "C" void func_003285A8(RefObject*),func_003285F8(RefObject*);
struct Value{RefObject*p;Value(const Value&) __asm__("func_002A7590");~Value() __asm__("func_00309378");Value&operator=(const Value&other){if(this!=&other){RefObject*next=other.p;if(next)func_003285A8(next);if(p)func_003285F8(p);p=next;}return *this;}};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
template void func_005487A8(Value*,Value*,Value*,int,Compare);
