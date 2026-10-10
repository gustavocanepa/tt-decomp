extern "C" void *func_004AE6D8(int size);
extern "C" void *func_004F6678(void *p, int c, int n);

extern void *D_00582D40;
extern int D_00582D44;
extern int D_00582D48;

extern "C" void func_002E8628(int w, int h) {
    int size = w * h;
    void *p = func_004AE6D8(size);
    D_00582D40 = p;
    D_00582D44 = w;
    D_00582D48 = h;
    func_004F6678(p, 0, size);
}
