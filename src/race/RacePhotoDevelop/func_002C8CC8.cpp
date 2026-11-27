/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, float); };
struct Target { char *vtbl; };
struct Obj { char pad[0xD00]; float value; Target *target; };
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_004752F8(void *);
extern "C" void func_00475638(float, float, float);
static inline void call(Obj *self, float value) {
    Target *target = self->target;
    VEntry *e = (VEntry *)(target->vtbl + 0x10);
    e->fn((char *)target + e->delta, value);
}
extern "C" void func_002C8CC8(Obj *self, float value) {
    float matrix[16];
    if (self->value != 0.0f) {
        func_00473050();
        func_004751FC();
        call(self, value);
        func_004752F8(matrix);
        func_004730A8();
        float scale = matrix[5] / matrix[0];
        func_00475638(scale, 1.0f / scale, 1.0f);
    }
    call(self, value);
}
