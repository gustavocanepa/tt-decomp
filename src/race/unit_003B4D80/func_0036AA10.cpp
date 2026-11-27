/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { char data[8]; };
extern Blob D_005F6AE0;
extern "C" int func_0040E9E8(void *);
extern "C" void func_0040EA80(void *, char *);
extern "C" void func_004F7B74(char *, const char *);
extern "C" char *func_0036AA10(char *self, char *dst) {
    char *name = self + 0x5584;
    if (*name) {
        func_004F7B74(dst, name);
    } else if (func_0040E9E8(self + 0xFD8)) {
        *(Blob *)dst = D_005F6AE0;
    } else {
        func_0040EA80(self + 0xFD8, dst);
    }
    return dst;
}
