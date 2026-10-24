/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
struct Rec { char pad[6]; s16 s6; };
struct Obj {
    char pad0[4];
    s32 u4;
    char pad8[0x85C - 8];
    s32 sel;
};
extern "C" s32 func_00481DE8(s32, s32, s32, s32, u16 *) throw();
extern "C" void func_00483570(void *, s32, void *) throw();
extern "C" void func_00483628(Obj *self, Rec *rec, u16 *str, s32 off) {
    s32 n = 0;
    if (*str != 0) {
        u16 *p = str;
        do {
            p += 1;
            n += 1;
        } while (*p != 0);
    }
    if (n > 0) {
        char *bank = (char *)self + (1 - self->sel) * 0x41C;
        s32 base = *(s32 *)(bank + 0x2C);
        func_00483570(self, func_00481DE8(base, self->u4, rec->s6 - off, off, str), rec);
    }
}
