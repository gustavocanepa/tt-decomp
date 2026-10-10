struct Slot {
    int f0, f4, f8;
    int id;
    char pad[0x48 - 0x10];
};

struct Pool {
    char pad0[0x24];
    struct Slot *slots;
    int count;
};

extern struct Pool D_0077A028;

struct Slot *func_004D3F38(void) {
    int i;
    struct Slot *s = D_0077A028.slots;
    for (i = 0; i < D_0077A028.count; i++, s++) {
        if (s->id == 0) {
            s->id = -1;
            return s;
        }
    }
    return 0;
}
