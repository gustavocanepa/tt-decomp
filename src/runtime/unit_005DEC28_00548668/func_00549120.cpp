struct RefObject;
extern "C" void func_002C0FE8(RefObject*),func_002C1050(RefObject*);
struct Value{RefObject*p;Value(const Value&) __asm__("func_002A7590");~Value() __asm__("func_002A75A8");Value&operator=(const Value&other){if(this!=&other){RefObject*next=other.p;if(next)func_002C0FE8(next);if(p)func_002C1050(p);p=next;}return *this;}};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
template<class I>inline Value*value_type(const I&){return 0;}
template<class I>inline int*distance_type(const I&){return 0;}
extern "C" void func_00549358(Value*,int,int,Value,Compare);
static inline void pop_inner(Value*first,Value*last,Value*result,Value value,Compare compare,int*){*result=*first;func_00549358(first,0,last-first,value,compare);}
static inline void pop_aux(Value*first,Value*last,Value*,Compare compare){pop_inner(first,last-1,last-1,Value(*(last-1)),compare,distance_type(first));}
static inline void pop_heap(Value*first,Value*last,Compare compare){pop_aux(first,last,value_type(first),compare);}
extern "C" void func_00549120(Value*first,Value*last,Compare compare){while(last-first>1)pop_heap(first,last--,compare);}
