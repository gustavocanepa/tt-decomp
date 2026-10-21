typedef int s32;

struct Info {
    s32 unk0;
};

extern "C" s32 func_004D9FB0(s32 arg0, s32 arg1, s32 arg2, Info *arg3);

extern "C" s32 func_004A8A88(s32 arg0, s32 arg1, s32 arg2) {
    Info info;

    while (func_004D9FB0(arg0, arg1, arg2, &info) < 0) {
    }
    return info.unk0;
}
