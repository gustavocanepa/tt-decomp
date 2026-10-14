/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef signed char s8;
extern "C" int func_004A8268(const char *, const char *) throw();
extern "C" s8 func_00403DA8(char *, int) throw();
extern "C" s8 func_00404138(char *, int) throw();
extern "C" s8 func_00404528(char *, int) throw();
extern "C" s8 func_00404980(char *, int) throw();
extern "C" int func_00403198(char *self, const char *name) {
    if (func_004A8268(name, "VIBRATION") == 0) {
        return func_00403DA8(self + 0x18, 0) != 0;
    }
    if (func_004A8268(name, "WHEEL FEEDBACK") == 0) {
        int r = 0;
        if (func_00404138(self + 0x48, 0) || func_00404528(self + 0x64, 0) || func_00404980(self + 0x8C, 0))
            r = 1;
        return r;
    }
    return 0;
}
