/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot {
    char pad[0x78];
    char name[0x54];
    int fCC;
    char rest[0x6F * 4 - 0xD0];
};
struct Row {
    Slot slot[27 / 27];
};
extern char *D_0059834C;
extern "C" int func_004B80F8() throw();
extern "C" int func_004B8630(int, int) throw() __attribute__((const));
extern "C" void func_004B75D8(char *, int, int) throw();
extern "C" int func_004CB210(int);
extern "C" int func_004CB740(int, int, int, int);
extern "C" int func_004CB8F8(int, int, int);
extern "C" int func_004CBB00(int, int, int);

extern "C" int func_004B8A18(int a0, int a1, int a2, int a3, int a4) {
    int ret = 1;
    int sp0 = a2;
    int sp4 = a4;
    if (func_004B80F8() != 0) {
        int q = a0 / 4;
        int r = a0 - q * 4;
        ret = 0xA;
        int s2 = func_004CB740(q, r, a1, 0x103);
        int s1 = s2;
        if (s2 == -4 && a3 == 0) {
            ret = 5;
            s2 = func_004CB740(q, r, a1, 0x200);
            s1 = s2;
        }
        if (s2 >= 0) {
            ret = 0xD;
            if (a3 != 0) {
                s2 = func_004CB8F8(s2, a3, 0);
            }
            if (a3 == 0 || s2 == a3) {
                ret = 0xF;
                s2 = func_004CBB00(s1, sp0, sp4);
                if (s2 >= 0) {
                    ret = 4;
                    s2 = func_004CB210(s1);
                    if (s2 == 0) ret = 0;
                }
            }
        }
        ret = func_004B8630(ret, s2);
        {
            int q2 = a0 / 4;
            int off = (q2 * 111 + (a0 - q2 * 4) * 27) * 4;
            func_004B75D8((char *)(off + (int)D_0059834C) + 0x78, s2, ret);
            *(int *)((char *)(off + (int)D_0059834C) + 0xCC) = 1;
            *((char *)(off + (int)D_0059834C) + 0x78) = 0;
        }
    }
    return ret;
}
