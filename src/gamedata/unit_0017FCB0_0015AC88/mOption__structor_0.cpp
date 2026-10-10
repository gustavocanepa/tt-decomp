typedef int s32;

extern "C" void *func_002A7618(void *arg0);
extern "C" void *func_003FC8C8(void *arg0);
extern "C" char D_005A7DC8[];

struct Obj0018FB20 {
    char pad[4];
    void *unk4;
    char pad2[0x10 - 0x8];
    void *unk10;
};

extern "C" void *mOption__structor_0(struct Obj0018FB20 *arg0) {
    struct Obj0018FB20 *s0 = arg0;
    void *temp_a0;

    func_002A7618(s0);
    temp_a0 = (char *)s0 + 0x18;
    s0->unk10 = temp_a0;
    s0->unk4 = D_005A7DC8;
    return func_003FC8C8(temp_a0);
}
