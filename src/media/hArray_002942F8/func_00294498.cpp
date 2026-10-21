/* compiler: ee-gcc2.96-stl */
struct Value { int p; };
struct BidirectionalTag {};
extern "C" Value *func_00548668(Value *, Value *, Value *, int *, BidirectionalTag);
static inline int *distance_type(Value *const &) { return 0; }
static inline BidirectionalTag iterator_category(Value *const &) { return BidirectionalTag(); }
static inline Value *rotate(Value *first, Value *middle, Value *last) {
 return func_00548668(first, middle, last, distance_type(first), iterator_category(first));
}
struct Vector { int alloc; Value *start, *finish, *end; Value *begin() { return start; } Value *end_it() { return finish; } };
struct Obj { char pad[16]; Vector v; };
extern "C" void func_00294498(Obj *o, int n) { Vector *v = &o->v; rotate(v->begin(), v->begin()+n, v->end_it()); }
