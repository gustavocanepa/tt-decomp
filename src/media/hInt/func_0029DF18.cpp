typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline s32 vcall(char *o) {
    VEntry *e = (VEntry *)(((VObj *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);

struct Self {
    char pad0[0x10];
    s32 value;
};

extern "C" void func_0029DF18(Self *self, s32 *result, s32 a2, s32 a3, char **other) {
    s32 buf[4];
    s32 v = vcall(*other);
    func_0029EA18(buf, self->value >> v);
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
    func_0029CEF0(buf, 2);
}
