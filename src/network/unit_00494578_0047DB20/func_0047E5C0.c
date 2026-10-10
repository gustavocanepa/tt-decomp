typedef int s32;
void func_004AC770(void *, s32);
void func_0047E9C0(void *, s32);
void func_0050E1A8(void *);
extern char D_005DA640[];
extern char D_005DA5C8[];
struct func_0047E5C0_temp_a0 {
    char pad0[0x8];
    void *unk8;
};

struct func_0047E5C0_arg0 {
    char pad0[0xA8];
    void *unkA8;
};

void func_0047E5C0(void *arg0, s32 arg1) {
    struct func_0047E5C0_temp_a0 *temp_a0;
    temp_a0 = (char *)arg0 + 0xAC;
    ((struct func_0047E5C0_arg0 *)arg0)->unkA8 = D_005DA640;
    temp_a0->unk8 = D_005DA5C8;
    func_004AC770(temp_a0, 0);
    func_0047E9C0(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
