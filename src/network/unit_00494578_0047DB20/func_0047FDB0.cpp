typedef int s32;

extern "C" void func_004AEAF8(void *arg0);
extern "C" void func_004AEB30(void *arg0);

struct func_0047FDB0_S8 {
    s32 a;
    s32 b;
};

extern "C" void func_0047FDB0(void *arg0) {
    char *p = (char *)arg0;
    if (*(s32 *)(p + 0x1A84) != 0) {
        struct func_0047FDB0_S8 z;
        z.a = 0;
        z.b = 0;
        *(struct func_0047FDB0_S8 *)(p + 0x1A94) = z;
        func_004AEB30(p + 0x1A20);
        func_004AEAF8(p + 0x1990);
        *(s32 *)(p + 0x1A84) = 0;
    }
}
