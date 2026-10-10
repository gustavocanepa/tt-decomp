typedef int s32;

extern "C" void func_004B4EB0(void *, const char *, s32);
extern "C" void func_00128A30(s32, void *);

extern "C" void func_00128AF8(s32 arg0, const char *arg1) {
    short buf[0x80];
    if (*arg1 != 0) {
        func_004B4EB0(buf, arg1, 0x80);
        func_00128A30(arg0, buf);
    }
}
