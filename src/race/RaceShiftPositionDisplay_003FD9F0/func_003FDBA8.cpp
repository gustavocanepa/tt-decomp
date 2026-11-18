extern "C" int func_004A8268(const char *, const char *);
extern const char *D_00585670[];
struct O { char pad[0x1718]; int idx; };
extern "C" void func_003FDBA8(O *self, const char *name) {
    int i = 0;
    do {
        if (func_004A8268(name, D_00585670[i]) == 0) {
            self->idx = i;
        }
        i++;
    } while (i < 4);
}
