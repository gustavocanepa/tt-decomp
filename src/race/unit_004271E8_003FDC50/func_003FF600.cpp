extern "C" int func_004A8268(const char *, const char *);
extern const char *D_00585708[];
struct O { char pad[0x44]; int idx; };
extern "C" void func_003FF600(O *self, const char *name) {
    int i = 0;
    do {
        if (func_004A8268(D_00585708[i], name) == 0) {
            self->idx = i;
            break;
        }
        i++;
    } while (i < 5);
}
