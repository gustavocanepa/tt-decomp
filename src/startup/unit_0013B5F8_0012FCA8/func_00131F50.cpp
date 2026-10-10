struct Text5 { char c[5]; };
struct Owner { char pad[0x14]; int id; };

extern void *D_00586EF8;
extern "C" const Text5 D_005E0FD8;
extern "C" const char D_005E0FE0[];
extern "C" int func_00408B58(int id);
extern "C" int func_0040DC70(int x);
extern "C" void func_0045F468(void *mgr, char *buf, int size, int value, const char *fmt);

extern "C" void func_00131F50(Owner *o, int size, char *buf) {
    int r = func_0040DC70(func_00408B58(o->id));
    if (r == 0) {
        *(Text5 *)buf = D_005E0FD8;
        return;
    }
    func_0045F468(D_00586EF8, buf, size, r, D_005E0FE0);
}
