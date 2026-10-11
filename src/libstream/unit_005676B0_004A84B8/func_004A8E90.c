/* compiler: ee-gcc2.96-no-strict-aliasing */
unsigned int func_004A8368(const char *s);
char *func_004A9548(char *dst, const char *src);
int func_00503298(const char *path, int mode, int arg);
void func_004A59F0(void);

int func_004A8E90(const char *path, int mode, int arg) {
    char *buf = __builtin_alloca(func_004A8368(path) + 1);
    int r;
    func_004A9548(buf, path);
    while ((r = func_00503298(buf, mode, arg)) < 0)
        func_004A59F0();
    return r;
}
