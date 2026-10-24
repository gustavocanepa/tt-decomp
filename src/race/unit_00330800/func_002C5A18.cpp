/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_005F2530[];
extern "C" void func_002C52C0(int, int, unsigned int) throw();
extern "C" void func_004A6500(void *, const char *, ...);
extern "C" int func_004A8368(const char *) throw();
extern "C" int func_004FF970(const char *, int);
extern "C" int func_004FFC00(int);
extern "C" int func_00500228(int, void *, int);
extern "C" int func_002C5A18(const char *arg0, int arg1, int arg2, int arg3, int arg4) {
    char sp[0x20];
    int fd = func_004FF970(arg0, 0x602);
    int result = 0;
    if (fd >= 0) {
        func_004A6500(sp, D_005F2530, arg2, arg3);
        func_00500228(fd, sp, func_004A8368(sp));
        func_002C52C0(fd, arg1, arg2 * arg3 * arg4);
        func_004FFC00(fd);
        result = 1;
    }
    return result;
}
