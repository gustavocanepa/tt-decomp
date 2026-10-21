typedef int s32;

extern "C" int func_001DCC18(void *arg0, s32 *arg1);
extern "C" void func_001DCC48(void *arg0, s32 arg1);
extern "C" void func_001DCCA0(void *arg0, s32 *arg1);
extern "C" void func_002C0FE8(s32 obj);
extern "C" void func_002C1050(s32 obj);

extern "C" void func_0026DC40(void *arg0, s32 *arg1)
{
    s32 buf[4];
    s32 tmp;
    s32 *ret = (s32 *)((char *)arg0 + 0x178);

    if (*arg1 == 0) {
        tmp = 0;
        func_001DCC18(buf, &tmp);
    } else {
        func_001DCCA0(buf, arg1);
    }
    if (ret != buf) {
        s32 obj = buf[0];
        if (obj != 0)
            func_002C0FE8(obj);
        s32 old = *ret;
        if (old != 0)
            func_002C1050(old);
        *ret = obj;
    }
    func_001DCC48(buf, 2);
}
