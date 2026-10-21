/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEntry { s16 delta; s16 index; s32 *(*fn)(void *, s32); };
struct VObj { char pad[4]; VEntry *vtbl; };
struct ArrayElement { char pad[0x10]; VObj *object; s32 index; };
static inline s32 *vcall(char *o, s32 index) {
    VEntry *e = (VEntry *)((char *)((VObj *)o)->vtbl + 0x78);
    return e->fn(o + e->delta, index);
}
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00295EF0(ArrayElement *arg0, s32 *arg1) {
    s32 *value = vcall((char *)arg0->object, arg0->index);
    if (arg1 != value) {
        s32 newVal = *value;
        if (newVal != 0) func_002C0FE8(newVal);
        s32 oldVal = *arg1;
        if (oldVal != 0) func_002C1050(oldVal);
        *arg1 = newVal;
    }
}
