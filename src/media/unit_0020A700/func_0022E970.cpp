struct Elem {
 int value;
 Elem(const Elem &) throw() __asm__("func_0022C0D0");
};
inline void *operator new(unsigned int, void *p) throw() { return p; }
template<class T> inline void construct(T *p, const T &v) { new(p) T(v); }
struct Items {
 int alloc;
 Elem *start, *finish, *end;
 void push(const Elem &value);
};
extern "C" void func_00539000(Items *, Elem *, const Elem *);
inline void Items::push(const Elem &value) {
 if (finish != end) {
  if (finish) construct(finish, value);
  ++finish;
 } else func_00539000(this, finish, &value);
}
struct Owner { char pad[0x10]; Items items; };
extern "C" void func_0022E970(Owner *o, const Elem *value) { o->items.push(*value); }
