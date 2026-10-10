struct NamedEntry {
    const char *name;
    int value;
};

extern NamedEntry D_0076CE70[];

extern "C" int func_004A8268(const char *a, const char *b);

extern "C" int func_004558C0(const char *name) {
    NamedEntry *e = D_0076CE70;
    for (int i = 0; i < 12; i++, e++) {
        if (func_004A8268(e->name, name) == 0)
            return i;
    }
    return -1;
}
