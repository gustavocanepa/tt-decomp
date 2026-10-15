/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { char pad0[0xA8]; char *unkA8; char padAC[8]; char *unkB4; };
extern "C" s32 func_004A8368(const char *) throw();
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" void func_004811D0(Obj *self, char *dst) {
    s32 a = func_004A8368(self->unkA8);
    s32 b = func_004A8368(self->unkB4);
    func_004F64C4(dst, self->unkA8, a);
    dst += a;
    if (a != 0 && dst[-1] != 0x2F) {
        *dst = 0x2F;
        dst++;
    }
    func_004F64C4(dst, self->unkB4, b);
    dst[b] = 0;
}
