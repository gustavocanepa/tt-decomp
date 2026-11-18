extern "C" {
void func_003FF4C0(void *arg0, int arg1);
void func_003FF8A8(void *arg0, int arg1);
void func_003FFF78(void *arg0, int arg1);
void func_004000F0(void *arg0, int arg1);
void func_00400D78(void *arg0, int arg1);
void func_004034A8(void *arg0, int arg1);
int func_0050E1A8(void *arg0);
}

extern char D_005D8CC8[];
extern char D_005D8C88[];

extern "C" int func_003FC930(void *arg0, int arg1) {
    *(int *)arg0 = (int)D_005D8CC8;
    func_003FF8A8((char *)arg0 + 0x170C, 2);
    func_004000F0((char *)arg0 + 0x16B8, 2);
    func_003FFF78((char *)arg0 + 0x145C, 2);
    func_003FF4C0((char *)arg0 + 0x13AC, 2);
    func_004034A8((char *)arg0 + 0x1238, 2);
    {
        char *p = (char *)arg0 + 0x1230;
        *(int *)p = (int)D_005D8C88;
        func_00400D78(p, 0);
    }
    func_00400D78(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
