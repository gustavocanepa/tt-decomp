struct RefObject;
extern "C" void func_002C0FE8(RefObject*),func_002C1050(RefObject*);
struct Value{RefObject*p;Value(const Value&) __asm__("func_00309360");~Value() __asm__("func_002A75A8");Value&operator=(const Value&other){if(this!=&other){RefObject*next=other.p;if(next)func_002C0FE8(next);if(p)func_002C1050(p);p=next;}return *this;}};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
extern "C" void func_005495F0(Value*first,int hole,int top,Value value,Compare compare){int parent=(hole-1)/2;while(hole>top&&compare(first[parent],value)){first[hole]=first[parent];hole=parent;parent=(hole-1)/2;}first[hole]=value;}
