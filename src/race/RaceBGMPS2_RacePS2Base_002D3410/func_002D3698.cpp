/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEntry { short delta; short index; void *fn; };
struct Obj { char pad[0x70]; s32 m70; };
struct O2 { char pad0[8]; char *vt; };
extern "C" s32 func_0039C8B8(void *, s32, s32, s32, s32);
extern "C" void func_0039CA30(void *, s32, s32, s32, s32);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_002D3698(Obj *self, s32 a1, O2 *o2) {
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 2; j++) {
            if (func_0039C8B8((char *)self + 0x36C0, a1, self->m70, i, j)) {
                func_00473050();
                func_0039CA30((char *)self + 0x36C0, a1, self->m70, i, j);
                VEntry *e = (VEntry *)(o2->vt + 0x100);
                ((void (*)(void *, s32))e->fn)((char *)o2 + e->delta, i);
                func_004730A8();
            }
        }
    }
}
