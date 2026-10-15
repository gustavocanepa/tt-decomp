/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_0059834C;
extern "C" int func_004B80F8() throw();
extern "C" int func_004B8630(int, int) throw() __attribute__((const));
extern "C" void func_004B75D8(char *, int, int) throw();
extern "C" int func_004CB6B8(int, int, int);
extern "C" int func_004B8910(int id, int arg1) {
    int status = 1;
    if (func_004B80F8()) {
        int q = id / 4;
        int r = id - q * 4;
        status = 9;
        int result = func_004CB6B8(q, r, arg1);
        if (result == 0) status = 0;
        status = func_004B8630(status, result);
        int off = (q * 111 + r * 27) * 4;
        func_004B75D8((char *)(off + (int)D_0059834C) + 0x78, result, status);
        *(int *)((char *)(off + (int)D_0059834C) + 0xCC) = 1;
        *((char *)(off + (int)D_0059834C) + 0x78) = 0;
    }
    return status;
}
