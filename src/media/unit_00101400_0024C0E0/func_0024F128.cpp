/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VObj;
struct VEntryN { s16 delta; s16 index; const char *(*fn)(void *); };
struct VEntryD { s16 delta; s16 index; s32 (*fn)(void *, s32, void *, s32); };
struct VObj { char pad0[4]; char *vtbl; char pad8[8]; s32 f10; s32 f14; };

extern "C" void func_001E4E20(s32, s32);
extern "C" s32 func_0021D610(void) ;
extern "C" s32 func_0022F7B8(void *);
extern "C" VObj *func_0022F7C8(void *);
extern "C" s32 func_0024EA40(void) throw();
extern "C" const char *func_002A39C0(const char *);
extern "C" void func_00526860(const char *, ...);

extern "C" s32 func_0024F128(VObj *self) {
    s32 result = 1;
    func_00526860("{\n");
    VEntryN *n = (VEntryN *)(self->vtbl + 0x58);
    func_00526860("[%s {%d} %010d] ", func_002A39C0(n->fn((char *)self + n->delta)), self->f14, self->f10);
    if (func_0022F7C8(self) != 0) {
        VObj *o = func_0022F7C8(self);
        VEntryD *e = (VEntryD *)(o->vtbl + 0x348);
        void *adj = (char *)o + e->delta;
        result = e->fn(adj, func_0022F7B8(self), self, 0);
        if (result == 2) {
            s32 a = func_0022F7B8(self);
            func_001E4E20(a, func_0024EA40());
            s32 b = func_0022F7B8(self);
            func_001E4E20(b, func_0021D610());
        }
    }
    func_00526860("}\n");
    return result;
}
