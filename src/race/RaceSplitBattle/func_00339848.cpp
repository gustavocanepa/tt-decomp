extern char D_00583E98[];
extern char D_00583EA0[];
extern char D_00583EB0[];
extern char D_00583EB8[];

extern "C" void func_00339D78(void *a, void *b);

static inline void loadA(int id) {
    if (id == 1)
        func_00339D78(D_00583E98, D_00583EA0);
}

static inline void loadB(int id) {
    if (id == 1)
        func_00339D78(D_00583EB0, D_00583EB8);
}

extern "C" void func_00339848(int id, int key) {
    if (key == 0xFFFF) {
        loadA(id);
        loadB(id);
    }
}
