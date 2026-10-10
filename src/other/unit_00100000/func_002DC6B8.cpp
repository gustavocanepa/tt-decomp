typedef int s32;

struct Out {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_00424008(Out *out, s32 arg1, s32 arg2, const char *name);
extern "C" void func_00393900(s32 arg0, s32 arg1);

extern "C" void func_002DC6B8(s32 arg0, s32 arg1, s32 arg2) {
    Out sp;

    func_00424008(&sp, arg1, arg0, "GDGT");
    if (sp.unk4 >= 0) {
        func_00393900(arg2, arg0);
    }
}
