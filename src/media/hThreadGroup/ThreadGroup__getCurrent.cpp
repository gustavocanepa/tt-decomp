typedef int s32;

extern "C" void func_002BB560(s32 *buf);
extern "C" s32 *func_002BBB48(s32 h);
extern "C" void func_002C0FE8(s32 obj);
extern "C" void func_002C1050(s32 obj);
extern "C" void func_002BB508(s32 *buf, s32 flags);

extern "C" void ThreadGroup__getCurrent(s32 *ret)
{
    s32 buf[4];

    func_002BB560(buf);
    s32 *src = func_002BBB48(buf[0]);
    if (ret != src) {
        s32 obj = *src;
        if (obj != 0)
            func_002C0FE8(obj);
        s32 old = *ret;
        if (old != 0)
            func_002C1050(old);
        *ret = obj;
    }
    func_002BB508(buf, 2);
}
