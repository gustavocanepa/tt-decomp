typedef float f32;
typedef unsigned char u8;

struct Obj {
    char pad[0x81];
    u8 unk81;
};

extern "C" f32 D_00582D08[];

extern "C" f32 func_002E4530(Obj *arg0) {
    return D_00582D08[arg0->unk81];
}
