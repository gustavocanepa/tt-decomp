extern "C" int func_00410540(void);
extern "C" void func_00410558(int index, char *name, int size);
extern "C" int func_003FA6A0(void *o, char *name);

extern "C" void func_003FA630(void *o) {
    char name[32];
    int n = func_00410540();
    for (int i = 0; i < n; i++) {
        func_00410558(i, name, sizeof(name));
        func_003FA6A0(o, name);
    }
}
