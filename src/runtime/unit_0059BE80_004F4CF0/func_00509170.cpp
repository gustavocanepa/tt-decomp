typedef void (*Handler)(void) __attribute__((noreturn));

extern "C" Handler D_005A4794;
extern "C" int func_004A8268(const char *a, const char *b);

extern "C" void func_00509170(void) {
    D_005A4794();
}

extern "C" void *func_005BC608(const char *a, const char *b, void *value) {
    void *r = value;
    if (func_004A8268(a, b) != 0) {
        r = 0;
    }
    return r;
}
