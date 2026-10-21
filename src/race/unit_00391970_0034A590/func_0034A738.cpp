typedef int s32;

extern "C" void RaceCourse__clearData(char *arg0);
extern "C" void PitmenData__structor_1(char *arg0, s32 arg1);
extern "C" void func_003C7880(char *arg0, s32 arg1);
extern "C" void func_00422818(void *arg0, s32 arg1);
extern "C" void func_0050E1A8(char *arg0);

extern char D_005CF628[];
extern char D_005CF640[];

struct func_0034A738_a {
    char pad0[0xD4];
    s32 unkB8;
};

struct func_0034A738_b {
    s32 unk0;
};

void func_0034A738(char *arg0, s32 arg1) {
    struct func_0034A738_b *temp;

    ((struct func_0034A738_a *)arg0)->unkB8 = (s32)D_005CF628;
    RaceCourse__clearData(arg0);
    temp = (struct func_0034A738_b *)(arg0 + 0x9C);
    temp->unk0 = (s32)D_005CF640;
    func_00422818(temp, 0);
    func_003C7880(arg0 + 0x94, 2);
    PitmenData__structor_1(arg0 + 0x1C, 2);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
