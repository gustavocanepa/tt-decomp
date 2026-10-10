typedef int s32;
typedef unsigned char u8;

struct Obj { char pad[0x1E]; u8 unk1E; };

extern "C" s32 func_0042FD70(Obj *arg0) {
    return arg0->unk1E == 0;
}
