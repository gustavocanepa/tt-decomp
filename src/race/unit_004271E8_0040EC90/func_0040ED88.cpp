extern char D_00585A30[];
extern "C" int func_0040B840(void *db, int key, int type);
extern "C" int func_0040EDE0(void *self, int id);

extern "C" int func_0040ED88(void *self, int key) {
    int id = func_0040B840(D_00585A30, key, 0x22);
    if (id == -1)
        return 0;
    return func_0040EDE0(self, id);
}
