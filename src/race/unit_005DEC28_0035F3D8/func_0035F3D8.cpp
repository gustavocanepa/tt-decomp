typedef int s32;

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad[0x154];
    Vec4 unk154;
};

extern "C" void RacePriusHybridDisplay__virtual_10(Vec4 *arg0);

extern "C" void func_0035F3D8(struct Obj *arg0) {
    RacePriusHybridDisplay__virtual_10(&arg0->unk154);
}
