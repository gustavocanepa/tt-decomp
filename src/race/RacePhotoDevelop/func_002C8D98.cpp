/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, float); };
struct Target { char *vtbl; };
struct Obj { char pad[0xD00]; float value; Target *target; };
extern "C" void func_00475780(float);
extern "C" void func_002C8D98(Obj *self, float value) {
    func_00475780(self->value);
    Target *target = self->target;
    VEntry *e = (VEntry *)(target->vtbl + 0x18);
    e->fn((char *)target + e->delta, value);
}
