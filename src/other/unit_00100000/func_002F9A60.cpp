typedef float f32;

struct Obj {
    char pad[0x7E4];
    f32 unk788;
};

extern f32 D_0076739C;

extern "C" void func_002F9A60(Obj *arg0, f32 fparg0) {
    arg0->unk788 = fparg0 * D_0076739C;
}
