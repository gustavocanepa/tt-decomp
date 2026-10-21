typedef int s32;
struct VEntry { short delta; short index; float (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline float vcall(char *o) {
    VEntry *e = (VEntry *)(((VObj *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}
extern "C" void func_0029B380(void *, float);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00299AB0(void *, s32);

struct Self { char pad0[0x10]; float value; };

extern "C" void func_00299C90(Self *self, s32 *result, s32 a2, s32 a3, char **other) {
    s32 buf[4];
    func_0029B380(buf, self->value + vcall(*other));
    if (result != buf) {
        s32 newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        s32 oldVal = *result;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *result = newVal;
    }
    func_00299AB0(buf, 2);
}
