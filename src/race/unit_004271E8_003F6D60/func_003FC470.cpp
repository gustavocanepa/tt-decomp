extern "C" int func_004A8268(const char *, const char *);
extern const char *D_00585620[];
struct O { char pad[0x4]; int idx; };
extern "C" void func_003FC470(O *self, const char *name) {
    int i = 0;
    do {
        if (func_004A8268(name, D_00585620[i]) == 0) {
            self->idx = i;
            break;
        }
        i++;
    } while (i < 7);
}
