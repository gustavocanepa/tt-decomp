#include "types.h"

struct func_003CA210 {
    char data[0x14C];
    func_003CA210();
};

struct Vec3 {
    f32 x, y, z;
    Vec3() { x = 0.0f; y = 0.0f; z = 0.0f; }
};

struct func_003C8320 {
    int unk0;
    int unk4;
    int unk8;
    f32 scaleC;
    int unk10;
    char pad14[0xC];
    func_003CA210 sub;
    Vec3 vec;
    func_003C8320();
};

func_003C8320::func_003C8320() : unk0(0), unk4(-1), unk8(0), scaleC(1.0f), unk10(0) {
}
