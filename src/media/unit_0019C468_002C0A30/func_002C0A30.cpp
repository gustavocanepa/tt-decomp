typedef int s32;

extern "C" void func_004AACA0(void *arg0, void *arg1);
extern "C" char D_005F2330[];

extern "C" void func_002C0A30(void *arg0, void **arg1) {
    void *obj = *arg1;
    s32 off = *(s32 *)((char *)obj - 0x10);
    void *a1v;
    if (off == 0) {
        a1v = D_005F2330;
    } else {
        char *p = (char *)obj + off;
        *p = 0;
        a1v = *arg1;
    }
    func_004AACA0((char *)arg0 + 0x10, a1v);
}
