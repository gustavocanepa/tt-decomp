struct Obj {
    char pad0[0x14];
    int active;
    int id;
};

extern char D_00598C40[];
extern "C" void func_004F46A0(void *table, int id, int flag);
extern "C" void func_004C1850(Obj *self);
extern "C" void func_004CF028(Obj *self, int a, int b, int c, int d, int e);

extern "C" void func_004CEEC8(Obj *self) {
    func_004F46A0(D_00598C40, self->id, 0);
    func_004C1850(self);
    self->active = 1;
    func_004CF028(self, 0, 0, 0, 0, 1);
}
