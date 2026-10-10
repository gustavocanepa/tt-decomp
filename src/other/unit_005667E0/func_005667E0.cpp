typedef unsigned short u16;

struct Obj00603F38 {
    char pad0[0x8];
    u16 unk8;
};

extern "C" struct Obj00603F38 *func_00418AB8(void);

extern "C" u16 func_005667E0(void) {
    return func_00418AB8()->unk8;
}
