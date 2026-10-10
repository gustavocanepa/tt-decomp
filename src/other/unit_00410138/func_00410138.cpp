typedef int s32;

struct Info {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern s32 D_00585C1C;

extern "C" s32 func_0040FFE8(s32 id, Info *info);
extern "C" const char *func_00411D78(s32 a, s32 b);
extern "C" char *func_004F7B74(char *dst, const char *src);

extern "C" void func_00410138(s32 id, char *out) {
    Info info;
    if (func_0040FFE8(id, &info)) {
        func_004F7B74(out, func_00411D78(D_00585C1C, info.unk8));
    }
}
