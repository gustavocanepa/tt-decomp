/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int id; signed char v; char pad[0x117]; int set; };
extern unsigned char D_00586918[];
extern "C" int func_00443E88(Obj *) throw();
extern "C" int func_00443F18(Obj *o, signed char c) {
    if (c == 0 || !o->set || o->id < 0) return 0;
    if (c < 20) return o->id == D_00586918[c];
    return func_00443E88(o) == c;
}
