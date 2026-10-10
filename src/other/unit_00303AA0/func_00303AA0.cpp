typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Obj { char pad[0x30]; u16 f30; u8 f32; u8 f33; };
extern u8 D_005834C3;
extern u8 D_005834C5;

extern "C" s32 func_00303AA0(Obj *o) {
    if (o->f30)
        return 1;
    if (D_005834C3) {
        if (o->f32)
            return 1;
        if (!D_005834C5) {
            if (o->f33)
                return 1;
        }
    }
    return 0;
}
