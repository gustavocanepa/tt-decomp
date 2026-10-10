struct D_LocalBuf {
    char pad[0x11];
    unsigned char bF;
    unsigned char b10;
};

extern "C" int func_004109F8(void *arg0, D_LocalBuf *arg1);

extern "C" int func_00410710(void *arg0, int *arg1, int *arg2) {
    D_LocalBuf buf;
    if (func_004109F8(arg0, &buf)) {
        *arg1 = buf.bF;
        *arg2 = buf.b10;
        return 1;
    }
    return 0;
}
