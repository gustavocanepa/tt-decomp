typedef int s32;

extern "C" void func_0021F318(s32 *buf, s32 a, s32 b);
extern "C" void func_002C0FE8(s32 obj);
extern "C" void func_002C1050(s32 obj);
extern "C" void func_0021EEF0(s32 *buf, s32 flags);

extern "C" void func_0021F020(s32 *ret)
{
    s32 buf[4];

    func_0021F318(buf, 0, 0);
    if (ret != buf) {
        s32 obj = buf[0];
        if (obj != 0)
            func_002C0FE8(obj);
        s32 old = *ret;
        if (old != 0)
            func_002C1050(old);
        *ret = obj;
    }
    func_0021EEF0(buf, 2);
}
