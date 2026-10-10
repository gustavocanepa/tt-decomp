typedef int s32;

struct Loc {
    s32 unk0;
    s32 unk4;
};

extern s32 D_00585C1C;

extern "C" s32 func_0040FFE8(void *, Loc *);
extern "C" char *func_00411D78(s32, s32);
extern "C" char *func_004F7B74(char *, const char *);

extern "C" void func_004100F0(void *self, char *out) {
    Loc loc;
    if (func_0040FFE8(self, &loc))
        func_004F7B74(out, func_00411D78(D_00585C1C, loc.unk4));
}
