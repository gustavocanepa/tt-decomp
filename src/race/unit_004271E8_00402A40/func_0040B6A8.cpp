extern char D_005FBD40[];

extern "C" int exception__structor_0(int n);
extern "C" void func_00412538(int a0);
extern "C" void func_004125C0(int a0, void *a1);
extern "C" void func_004F7A30(void *a0, char *a1);
extern "C" void func_004F7B74(void *a0, void *a1);

extern "C" void func_0040B6A8(char *arg0) {
    char buf[0x100];
    int s0 = exception__structor_0(8);
    func_00412538(s0);
    *(int *)(arg0 + 0x1F0) = s0;
    func_004F7B74(buf, arg0 + 8);
    func_004F7A30(buf, D_005FBD40);
    func_004125C0(*(int *)(arg0 + 0x1F0), buf);
}
