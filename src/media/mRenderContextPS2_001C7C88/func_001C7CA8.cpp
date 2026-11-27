/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x, y, z, w; };
struct Entry { short delta, index; void (*fn)(void *, Vec4 *, int); };
struct Obj { int first; Entry *vtbl; };
extern "C" void func_0046F0F8(int);
extern "C" void func_004708C8(float, float, float, float);
extern "C" void func_001C7CA8(Obj *self, int arg) {
    Vec4 v;
    float zero = 0.0f;
    v.x = zero;
    v.y = zero;
    v.z = zero;
    v.w = zero;
    Entry *e = (Entry *)((char *)self->vtbl + 0x218);
    e->fn((char *)self + e->delta, &v, arg);
    func_0046F0F8(0x12);
    func_004708C8(v.x, v.y, v.z, v.w);
}
