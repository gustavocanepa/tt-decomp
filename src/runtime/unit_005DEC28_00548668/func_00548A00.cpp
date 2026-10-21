/* compiler: ee-gcc2.96-no-strict-aliasing */
struct RefObject;
struct Value{RefObject*p;Value(const Value&) __asm__("func_00309360");~Value() __asm__("func_00309378");};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
extern "C" void func_00548ED8(Value*first,Value*last,Compare compare);
extern "C" void func_005490A0(Value*first,Value*last,Value*,Compare compare);
/* SGI __value_type: takes the iterator by reference, which is what puts `first + 16` in memory. */
static inline Value *value_type(Value *const &) { return (Value *)0; }
static inline void unguarded_insertion_sort(Value *first, Value *last, Compare compare) {
    func_005490A0(first, last, value_type(first), compare);
}
/* SGI __final_insertion_sort: sort the first 16 elements, then insert the rest unguarded. */
extern "C" void func_00548A00(Value *first, Value *last, Compare compare) {
    if (last - first > 16) {
        func_00548ED8(first, first + 16, compare);
        unguarded_insertion_sort(first + 16, last, compare);
    } else
        func_00548ED8(first, last, compare);
}

