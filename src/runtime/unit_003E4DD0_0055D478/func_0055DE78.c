typedef int s32;
void func_0038E308(void *, s32);
void func_0034F970(void *, s32);
void func_0050E1A8(void *);
extern char D_005D5958[];
extern char D_005D13A0[];
struct func_0055DE78_temp_a0 {
    char pad0[0x14];
    void *unk14;
};

struct func_0055DE78_arg0 {
    void *unk0;
};

void func_0055DE78(void *arg0, s32 arg1) {
    struct func_0055DE78_temp_a0 *temp_a0;
    temp_a0 = (char *)arg0 + 0x54BC;
    ((struct func_0055DE78_arg0 *)arg0)->unk0 = D_005D5958;
    temp_a0->unk14 = D_005D13A0;
    func_0038E308(temp_a0, 0);
    func_0034F970(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
