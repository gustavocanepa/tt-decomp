/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Obj { char pad[0xC0]; u128 a; u128 b; char padE0[0x4C]; int dirty; };
static inline void copy(u128 *out, const u128 *in) { *out = *in; }
extern "C" void func_003DDDB8(Obj *self, int which, const u128 *in) {
    self->dirty = 1;
    u128 *out = &self->a;
    if (which) out = &self->b;
    copy(out, in);
}
