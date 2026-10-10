typedef int s32;

struct Obj003EE788 {
    char pad0[0x178];
    s32 unk170;
};

extern "C" void func_003494A8(struct Obj003EE788 *arg0);
extern "C" void func_003495C8(void);

extern "C" void func_00348E18(struct Obj003EE788 *arg0) {
    if (arg0->unk170 == 0) {
        return func_003494A8(arg0);
    }
    func_003495C8();
}
