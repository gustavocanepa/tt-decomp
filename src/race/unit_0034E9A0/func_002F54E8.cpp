typedef float f32;
typedef unsigned char u8;
typedef int s32;

struct Sub {
    char pad[0x20A26];
    u8 unkCBDE;
};

struct Obj_00350CE8 {
    char pad0[4];
    Sub *unk4;
};

struct Cam_00350CE8 {
    char pad[0x638];
    f32 unk61C;
    f32 unk620;
    f32 unk624;
    s32 unk628;
};

struct V3_00350CE8 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" s32 func_002F54E8(Obj_00350CE8 *arg0, V3_00350CE8 *arg1) {
    Cam_00350CE8 *c = (Cam_00350CE8 *)((char *)arg0 + 0x104);

    if (arg0->unk4->unkCBDE == 2) {
        return 0;
    }
    if (c->unk628 < 0) {
        return 0;
    }
    arg1->x = c->unk61C;
    arg1->y = c->unk624;
    arg1->z = -c->unk620;
    return 1;
}
