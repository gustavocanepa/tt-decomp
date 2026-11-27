struct RefObject;
extern "C" void func_002C0FE8(RefObject*),func_002C1050(RefObject*);
struct Value{RefObject*p;Value(const Value&) __asm__("func_002A7590");~Value() __asm__("func_002A75A8");Value&operator=(const Value&other){if(this!=&other){RefObject*next=other.p;if(next)func_002C0FE8(next);if(p)func_002C1050(p);p=next;}return *this;}};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
template<class I>inline Value*value_type(const I&){return 0;}
template<class I,class J,class T>inline void iter_swap_inner(I a,J b,T*){T temp=*a;*a=*b;*b=temp;}
template<class I,class J>inline void iter_swap(I a,J b){iter_swap_inner(a,b,value_type(a));}
extern "C" Value*func_00548BC0(Value*first,Value*last,Value pivot,Compare compare){while(true){while(compare(*first,pivot))++first;--last;while(compare(pivot,*last))--last;if(!(first<last))return first;iter_swap(first,last);++first;}}
