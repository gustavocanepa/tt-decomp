/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x3c]; void *data; };
struct Entry { void (*fn)(); int zero; char pad[0x18]; };
struct Opt { int a,b; char pad[8]; };
extern Obj *D_0058C5A0, *D_0058C5A4;
extern char D_0058C5B0[];
extern "C" void func_0047FB30();
extern "C" void func_0047FB50();
extern "C" Obj *func_004AF398(Entry *, void *);
extern "C" void *func_004A53A0(int);
extern "C" int func_004A5618(Obj *);
extern "C" Obj *func_004A56C8(Entry *, Opt *, void *);
extern "C" int func_004A58E0(unsigned, int);
extern "C" void func_00480028() {
    Entry entry;
    Opt opt;
    if (!D_0058C5A0) {
        Opt *options = &opt;
        entry.fn = func_0047FB30;
        entry.zero = 0;
        options->a = 0;
        options->b = 0x2800;
        Obj *p = func_004A56C8(&entry, options, func_004A53A0(func_004A58E0(1, 1)));
        D_0058C5A0 = p;
        p->data = D_0058C5B0;
        func_004A5618(D_0058C5A0);
    }
    if (!D_0058C5A4) {
        entry.fn = func_0047FB50;
        entry.zero = 0;
        Obj *p = func_004AF398(&entry, func_004A53A0(func_004A58E0(3, -1)));
        D_0058C5A4 = p;
        p->data = D_0058C5B0;
        func_004A5618(D_0058C5A4);
    }
}
