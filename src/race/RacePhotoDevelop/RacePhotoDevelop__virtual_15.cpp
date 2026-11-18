/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Self {
    char pad[0x447A4];
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
};

extern char D_005794F0[];

extern "C" void func_00104C88(s32);
extern "C" void func_001059B0(void *);
extern "C" void func_00106070(void *, s32, s32, s32);
extern "C" s32 func_002CB2E0(s32, s32);
extern "C" s32 func_002CB7A8(s32, s32);
extern "C" void func_002C88D8(void);
extern "C" void func_00470450(s32);
extern "C" void func_00470B48(s32);
extern "C" void func_00470E60(s32);

extern "C" void RacePhotoDevelop__virtual_15(Self *self, s32 arg1) {
    if (self->f3C == 0) {
        if (self->f40 == 2) {
            func_00106070(D_005794F0, 2, 0x100, 0x180);
            func_002C88D8();
        }
    }
    if (self->f40 != 0) {
        func_00470B48(0);
        func_00470450(-1);
        func_00104C88(arg1);
        func_00470E60(1);
        self->f40 = self->f40 - 1;
        return;
    }
    s32 a = self->f3C;
    if (a >= 0) {
        s32 r;
        if (self->f34 != 0) {
            r = func_002CB7A8(self->f38, a);
        } else {
            r = func_002CB2E0(self->f38, a);
        }
        self->f3C = self->f3C + 1;
        if (r == 0) {
            func_001059B0(D_005794F0);
            func_002C88D8();
            self->f40 = 2;
            self->f3C = -1;
        }
    }
}
