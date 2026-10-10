extern char D_00584728[];
extern char D_00584730[];
extern char D_00584740[];
extern char D_00584748[];

extern "C" void func_00339D78(void *a, void *b);

static inline void loadA(int id) {
    if (id == 1)
        func_00339D78(D_00584728, D_00584730);
}

static inline void loadB(int id) {
    if (id == 1)
        func_00339D78(D_00584740, D_00584748);
}

extern "C" void func_00388B48(int id, int key) {
    if (key == 0xFFFF) {
        loadA(id);
        loadB(id);
    }
}
