struct func_00319228_arg0 {
    char pad0[0x80];
    int unk80;
};

extern "C" void func_00318ED8(void *arg0, void *arg1, int arg2);

extern "C" void func_00319228(struct func_00319228_arg0 *arg0) {
    char *p = (char *)arg0 + 0x44;

    p[1] = 0x18;
    p[0] = 0;
    func_00318ED8(arg0, (char *)arg0 + 0x60, arg0->unk80);
}
