typedef int s32;

struct Obj { char pad[0x6CC]; s32 unk6CC; };

extern "C" char *func_001E4F18(Obj *arg0) {
    return (char *)arg0 + (arg0->unk6CC * 0x10) + 0x8C;
}
