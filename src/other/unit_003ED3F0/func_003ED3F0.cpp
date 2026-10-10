typedef int s32;

struct Obj {
    char pad0[0xAC];
    s32 unkAC;
};

extern "C" void *func_003ED3F0(Obj *arg0)
{
    return (char *)arg0 + arg0->unkAC * 0x54;
}
