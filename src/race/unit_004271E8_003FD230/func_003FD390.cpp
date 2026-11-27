extern "C" int func_004A8268(const char *, const char *);
extern const char *D_00585660[];
struct O { char pad[0x1160]; int idx; };
extern "C" void func_003FD390(O *self, const char *name) {
    int i = 0;
    do {
        if (func_004A8268(name, D_00585660[i]) == 0) {
            self->idx = i;
            break;
        }
        i++;
    } while (i < 3);
}
