extern "C" void func_004A7C38(void *out, int arg);
extern "C" int func_004A6AA0(void *buf, int a, int b);
extern "C" void func_004A7C78(void *buf, int a);

extern "C" int func_004A6978(int arg, int a, int b) {
    char buf[0x30];
    func_004A7C38(buf, arg);
    int r = func_004A6AA0(buf, a, b);
    func_004A7C78(buf, 2);
    return r;
}
