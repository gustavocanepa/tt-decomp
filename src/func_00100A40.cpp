typedef int s32;
typedef short s16;

extern char D_00579534[];

struct VE78 {
    s16 delta;
    s16 index;
    void (*fn)(char *, char *);
};

struct Frame78 {
    s32 r0[0xF];
    s32 r1[0xF];
    s32 r2[0xF];
    s32 spare[3];
    s32 r3[0xF];
};

extern "C" void func_00104838(char *arg0);
extern "C" void func_00104868(char *arg0, int arg1);
extern "C" char *func_00104960(char *d, const char *s);

extern "C" void GranTurismo4__GameObjectPS2__render(char *arg0) {
    struct Frame78 f;
    char *g = D_00579534;
    char *s3;
    char *s2;
    char *s0;
    s32 k;
    char *temp;
    VE78 *e;

    func_00104838((char *)f.r0);
    s3 = (char *)f.r1;
    func_00104838(s3);
    s2 = (char *)f.r2;
    func_00104838(s2);

    k = (*(s32 *)(g + 0x78)) * 0x3C;
    s0 = (char *)f.r3;
    func_00104960(s0, g + k);
    func_00104960((char *)f.r0, s0);
    func_00104868(s0, 0);

    func_00104960(s0, g + 0xF8);
    func_00104960(s3, s0);
    func_00104868(s0, 0);

    k = (1 - *(s32 *)(g + 0x78)) * 0x3C;
    func_00104960(s0, g + k);
    func_00104960(s2, s0);
    func_00104868(s0, 0);

    temp = *(char **)(arg0 + 0x64);
    e = (VE78 *)(temp + 0x78);
    e->fn(arg0 + e->delta, (char *)f.r0);

    func_00104868(s2, 0);
    func_00104868(s3, 0);
    func_00104868((char *)f.r0, 0);
}
