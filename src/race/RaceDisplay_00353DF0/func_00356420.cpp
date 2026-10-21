typedef int s32;
typedef float f32;

extern "C" void func_0038F960(void *a0);
extern "C" s32 func_004391C8(void *a0);
extern "C" s32 func_004F7A30(void *a0, s32 a1);
extern "C" void func_0035A5F0(void *a0, const char *a1, s32 a2);
extern "C" void RaceEventDisplay__addEvent(char *self, const char *text, f32 delta, f32 value, f32 a, f32 b);

extern char D_005865D0[];
extern char D_005F41D0[];

extern "C" void func_00356420(void *arg0) {
    char buf[0x20];
    char *s0;

    func_0038F960(buf);
    s0 = (char *)arg0 + 0x177C;
    func_004F7A30(buf, func_004391C8(D_005865D0));
    *(s32 *)(s0 + 0x20) = (s32)0x80C8C8C8;
    func_0035A5F0(s0, D_005F41D0, 0);
    RaceEventDisplay__addEvent(s0, buf, 3.0f, 0.0f, 0.1499999910593033f, 0.1499999910593033f);
}
