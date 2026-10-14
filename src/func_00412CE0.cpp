typedef int s32;

extern "C" s32 func_0040F638(s32 arg0, char *arg1);
extern "C" void func_00412D60(s32 arg0, char *arg1);

extern "C" void func_00412CE0(s32 arg0, s32 arg1) {
    char buf[0x20];
    if (func_0040F638(arg1, buf)) {
        func_00412D60(arg0, buf);
    }
}
