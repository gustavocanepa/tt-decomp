extern "C" int func_004A8268(const char *a, const char *b);
extern const char *D_00585608[];

extern "C" void func_003FABB8(int *out, const char *name) {
    for (int i = 0; i < 5; i++) {
        if (func_004A8268(name, D_00585608[i]) == 0) {
            *out = i;
            return;
        }
    }
    *out = 0;
}
