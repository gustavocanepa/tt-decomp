struct Entry {
    char pad0[8];
    unsigned int id;
    char pad4[0x24];
};

extern "C" int func_003F9D48(Entry *e, unsigned int key) {
    int i;
    for (i = 0; i < 10; i++) {
        if (e[i].id == 0x157529FF || key < e[i].id)
            break;
    }
    return i < 10 ? i : -1;
}
