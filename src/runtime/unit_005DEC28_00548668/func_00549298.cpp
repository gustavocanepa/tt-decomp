struct RefObject;
extern "C" void func_003285A8(RefObject*),func_003285F8(RefObject*);
struct Value{RefObject*p;Value(const Value&) __asm__("func_002A7590");~Value() __asm__("func_00309378");Value&operator=(const Value&other){if(this!=&other){RefObject*next=other.p;if(next)func_003285A8(next);if(p)func_003285F8(p);p=next;}return *this;}};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
extern "C" void func_00549358(Value*,int,int,Value,Compare);
extern "C" void func_00549298(Value*first,Value*last,Compare compare,Value*,int*){if(last-first<2)return;int length=last-first;int parent=(length-2)/2;while(true){func_00549358(first,parent,length,Value(first[parent]),compare);if(parent==0)return;--parent;}}
