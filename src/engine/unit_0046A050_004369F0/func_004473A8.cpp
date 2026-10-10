struct Obj {
    char pad0[0x60];
    void *table;
};

extern "C" int func_0043B610(void *table, const char *name);
extern "C" void func_00447398(Obj *self, int index);
extern "C" void func_004A6448(const char *fmt, ...);
extern const char D_00601C98[];

extern "C" void func_004473A8(Obj *self, const char *name)
{
    int index = func_0043B610(self->table, name);
    if (index < 0)
        return func_004A6448(D_00601C98, name);
    func_00447398(self, index);
}
