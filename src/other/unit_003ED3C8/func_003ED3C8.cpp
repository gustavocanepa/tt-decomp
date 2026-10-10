typedef int s32;

struct Obj {
    char pad0[0xA8];
    s32 unkA8;
};

extern "C" void *func_003ED3C8(Obj *arg0)
{
    return (char *)arg0 + arg0->unkA8 * 0x54;
}
