/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x34]; int data[400]; int count; };
static inline int get(Obj *o, int i) { if (i < o->count) return *(int *)((char *)o + (i << 2) + 0x34); return 0; }
extern "C" int func_00198B00(Obj *o, int i) { return get(o, i); }
