typedef int s32;
void *func_001B8120(void *);
void func_002A7578(char *, void *);
void func_0020D780(void *, s32);
extern char D_005B4FF8[];
extern char D_005B53B0[];

struct func_0021BA18_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x24];
    void *unk2C;
};

void func_0021BA18(struct func_0021BA18_arg0 *arg0) {
    s32 sp[4];

    func_001B8120(arg0);
    arg0->unk4 = D_005B4FF8;
    arg0->unk2C = D_005B53B0;
    sp[0] = 0;
    func_002A7578((char *)arg0 + 0xD4, sp);
    func_0020D780(arg0, 1);
}
