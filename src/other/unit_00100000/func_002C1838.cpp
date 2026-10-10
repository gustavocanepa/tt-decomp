typedef int s32;

struct Obj0032B860 {
    char *str0;
};

extern "C" void func_004A6500(void *dst, const char *fmt, s32 arg2);
extern "C" s32 func_004A8368(void *buf);
extern "C" void *func_0050F1B0(void *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);

extern "C" Obj0032B860 *func_002C1838(Obj0032B860 *arg0, s32 arg1) {
    char buf[0x20];

    func_004A6500(buf, "%p", arg1);
    s32 len = func_004A8368(buf);
    s32 strlen0 = *(s32 *)(arg0->str0 - 0x10);
    func_0050F1B0(arg0, strlen0, 0, buf, len);
    return arg0;
}
