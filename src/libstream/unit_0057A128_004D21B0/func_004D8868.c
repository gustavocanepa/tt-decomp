/* compiler: ee-gcc2.9-991111 */
typedef int (*Callback)();
struct State { int a, b; char *c; int d, which; Callback f14, f18, f1c, f20, f24, f28, f2c; char gap[12]; Callback f3c, f40, f44, f48, f4c; };
struct Obj { char pad[0x30]; char *name; };
struct Lib { char pad[0x38]; void *ent[0x24]; };
extern struct State D_00782940;
extern char D_00613F18[], D_00613F20[], D_00613F40[], D_00613F48[];
extern struct Lib *func_004D9EC0(char *, int);
int __attribute__((register_precision ($16, 128))) func_004D8868(struct Obj *o, int a, int b, char *c) {
    struct State *s = &D_00782940;
    struct Lib *lib;
    s->a = a;
    s->b = b;
    s->c = c;
    lib = func_004D9EC0(D_00613F18, 0x102);
    if (lib && s->which != 1) {
        s->f14 = (Callback)lib->ent[9];
        s->f18 = (Callback)lib->ent[1];
        s->f1c = (Callback)lib->ent[2];
        s->f20 = (Callback)lib->ent[4];
        s->f24 = (Callback)lib->ent[3];
        s->f28 = (Callback)lib->ent[18];
        s->f2c = (Callback)lib->ent[24];
        o->name = D_00613F20;
        return 0;
    }
    lib = func_004D9EC0(D_00613F40, 0x101);
    if (lib && D_00782940.which != 0) {
        D_00782940.f3c = (Callback)lib->ent[0];
        D_00782940.f40 = (Callback)lib->ent[1];
        D_00782940.f44 = (Callback)lib->ent[32];
        D_00782940.f48 = (Callback)lib->ent[30];
        D_00782940.f4c = (Callback)lib->ent[21];
        o->name = D_00613F48;
        return 0;
    }
    return 0x81050053;
}
