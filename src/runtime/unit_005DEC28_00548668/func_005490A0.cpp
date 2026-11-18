struct RefObject;
struct Value{RefObject*p;Value(const Value&) __asm__("func_002A7590");~Value() __asm__("func_00309378");};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
extern "C" void func_005494F8(Value*,Value,Compare);
extern "C" void func_005490A0(Value*first,Value*last,Value*,Compare compare){for(Value*i=first;i!=last;++i)func_005494F8(i,Value(*i),compare);}
