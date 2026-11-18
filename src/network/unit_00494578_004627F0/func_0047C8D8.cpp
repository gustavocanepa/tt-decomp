/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VI { short adj; short pad; void *ti; };
struct X { char pad[0x20]; VI *vi; };
struct Y { char pad[0x30]; void *f30; void *f34; int f38; };
struct Z { char pad[0x4C]; X *f4C; char pad50[0x34]; int f84; char pad88[4]; void *f8C; };
extern char D_0056E9E8[], D_0056E9A8[];
extern "C" Y *GT4MC__FileGT4GameData__loadInstance(void *, void *, int, void *, void *, void *);
extern "C" void *func_0047A078(void *, int);
extern "C" void func_0047C8D8(int a0, Z *z) {
    Y *y = 0;
    X *x = z->f4C;
    if (x != 0) {
        VI *vi = x->vi;
        y = GT4MC__FileGT4GameData__loadInstance(vi->ti, D_0056E9E8, 0, (char *)x + vi->adj, D_0056E9A8, x);
    }
    if (y == 0) {
        z->f84 = 2;
    } else {
        void *a = y->f34;
        if (a == 0) {
            a = z->f8C;
            y->f34 = a;
        }
        void *r = y->f30;
        if (r == 0) {
            r = func_0047A078(a, 1);
            if (r == 0) {
                z->f84 = 3;
            } else {
                y->f30 = r;
                y->f38 = 1;
            }
        }
    }
}
