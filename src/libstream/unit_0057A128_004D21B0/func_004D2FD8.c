/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned int u32;

struct Ctl {
    char pad0[0xC];
    s32 f0C;
    char pad10[0x8];
    u32 f18;
    u32 f1C;
};

extern struct Ctl D_0077A008;

extern s32 func_004D3170(u32, s32, s32);
extern void func_004D3CF8(void);
extern void func_004D9D90(u32 *, u32 *);
extern s32 func_005038D8(void);
extern int func_00503928(void);

s32 func_004D2FD8(u32 arg0, s32 arg1, s32 arg2)
{
    struct Ctl *c = &D_0077A008;
    s32 temp_s4;
    s32 temp_s0;
    u32 sp0;
    u32 sp4;

    if (c->f0C == 0 || arg0 >= 6) {
        return 0;
    }
    temp_s4 = func_005038D8();
    temp_s0 = func_004D3170(arg0, arg1, arg2);
    func_004D3CF8();
    if (c->f18 != 0xFFFFFFFFu) {
        func_004D9D90(&sp0, &sp4);
        if (sp0 < c->f18) {
            c->f18 = sp0;
        }
        if (sp0 < c->f1C) {
            c->f1C = sp4;
        }
    }
    if (temp_s4 != 0) {
        func_00503928();
    }
    return temp_s0;
}
