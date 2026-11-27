/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Slot request id (func_004CB740 on id/4, id%4 with flag 1): a non-negative
   handle goes through func_004CB210 (status 0 or 4), else status 10; records the
   status in the slot record like its siblings func_0054AB88 and func_0054B4F8. */
extern char *D_0059834C;
extern "C" int func_004B80F8(int) throw();
extern "C" int func_004B8630(int, int) throw() __attribute__((const));
extern "C" void func_004B75D8(char *, int, int) throw();
extern "C" int func_004CB740(int, int, int, int);
extern "C" int func_004CB210(int);
extern "C" int func_004B87F8(int id, int arg1) {
    int status;
    if (!func_004B80F8(id)) return 1;
    {
        int q = id / 4;
        int r = id % 4;
        status = 10;
        int result = func_004CB740(q, r, arg1, 1);
        if (result >= 0) {
            status = 4;
            result = func_004CB210(result);
            if (result == 0) status = 0;
        }
        status = func_004B8630(status, result);
        int off = (q * 111 + r * 27) * 4;
        func_004B75D8((char *)(off + (int)D_0059834C) + 0x78, result, status);
        *((char *)(off + (int)D_0059834C) + 0x78) = 0;
    }
    return status;
}
