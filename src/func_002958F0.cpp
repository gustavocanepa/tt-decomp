/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Value { int p; };
template<class A,class B,class R> struct BinaryFunction { typedef A first_argument_type; typedef B second_argument_type; typedef R result_type; };
struct Compare: BinaryFunction<Value,Value,int> { void *object; Compare(void *p): object(p) {} };
struct Vector { int alloc; Value *start, *finish, *end; Value *begin() { return start; } Value *last() { return finish; } };
struct Obj { char pad[16]; Vector v; };
extern "C" void func_005487A8(Value *,Value *,Value *,int,Compare);
extern "C" void func_00548A00(Value *,Value *,Compare);
template<class I> inline Value *value_type(const I &) { return 0; }
static inline int lg(int n) { int k=0; for(;n!=1;n>>=1) ++k; return k; }
static inline void sort(Value *first,Value *last,Compare comp) {
 if(first!=last) {
  func_005487A8(first,last,value_type(first),lg(last-first)*2,comp);
  func_00548A00(first,last,comp);
 }
}
static inline bool empty(Value *first, Value *last) { return first == last; }
static inline void outer(Value *first, Value *last, void *c) {
 if(!empty(first,last)) { Compare comp(c); sort(first,last,comp); }
}
extern "C" void func_002958F0(Obj *o,void *c) {
 outer(o->v.begin(),o->v.last(),c);
}
