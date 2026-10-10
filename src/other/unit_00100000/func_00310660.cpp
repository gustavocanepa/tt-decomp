typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

struct Obj003684E8 {
    u8 pad0[4];
    s32 unk4;
};

extern u8 D_00023925[];

extern "C" s32 func_002F8A38(void *arg0);
extern "C" s32 func_002F8A40(struct Obj003684E8 *arg0);

extern "C" s32 func_00310660(struct Obj003684E8 *arg0) {
    if (D_00023925[arg0->unk4] != 0) {
        return func_002F8A40(arg0);
    }
    return func_002F8A38(arg0);
}
