typedef int s32;

struct Inner003337D8 {
    char pad[0x10];
    s32 unk10;
    s32 unk14;
};

extern "C" void func_0051D200(struct Inner003337D8 *arg0);

extern "C" void func_002CB0B0(void *arg0) {
    struct Inner003337D8 *temp_s0 = (struct Inner003337D8 *)((char *)arg0 + 0x1C);

    func_0051D200(temp_s0);
    temp_s0->unk10 = 0;
    temp_s0->unk14 = 0;
}
