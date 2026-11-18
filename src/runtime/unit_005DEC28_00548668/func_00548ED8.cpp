struct RefObject;
extern "C" void func_002C0FE8(RefObject*),func_002C1050(RefObject*);
struct Value{RefObject*p;Value(const Value&) __asm__("func_002A7590");~Value() __asm__("func_002A75A8");Value&operator=(const Value&other){if(this!=&other){RefObject*next=other.p;if(next)func_002C0FE8(next);if(p)func_002C1050(p);p=next;}return *this;}};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
template<class I>inline Value*value_type(const I&){return 0;}
template<class I>inline int*distance_type(const I&){return 0;}
extern "C" void func_005494F8(Value*,Value,Compare);
template<class I,class O>static inline O copy_inner(I first,I last,O result){for(int n=last-first;n>0;--n)*--result=*--last;return result;}
template<class I,class O>struct CopyDispatch{static O copy(I first,I last,O result){return copy_inner(first,last,result);}};
template<class I,class O>inline O copy_backward(I first,I last,O result){return CopyDispatch<I,O>::copy(first,last,result);}
static inline void linear_insert(Value*first,Value*last,Value*,Compare compare){Value value=*last;if(compare(value,*first)){copy_backward(first,last,last+1);*first=value;}else func_005494F8(last,value,compare);}
extern "C" void func_00548ED8(Value*first,Value*last,Compare compare){if(first==last)return;for(Value*i=first+1;i!=last;++i)linear_insert(first,i,value_type(first),compare);}
