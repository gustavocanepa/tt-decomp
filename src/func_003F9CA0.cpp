struct Rec { long w[6]; };
struct Obj { long pad; Rec r[10]; };
extern "C" void func_003F9A10(Rec *);
extern "C" void func_003F9A50(Rec *);
extern "C" void func_003F9CA0(Obj *o, unsigned idx, int flag) {
    if (idx < 10) {
        int i = idx;
        if (i < 9) {
            do {
                o->r[i] = o->r[i + 1];
                i++;
            } while (i < 9);
        }
        if (flag) func_003F9A50(&o->r[9]);
        else func_003F9A10(&o->r[9]);
    }
}
