/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Mgr { char pad[0x3C]; f32 f24; f32 f28; };
struct Ent { f32 x; f32 y; f32 z; f32 w; };
struct Self { char pad[0x2F4]; f32 f2F4; };
extern s32 D_00586EF4;
extern Ent D_00579848[];
extern char D_005E0110[];
extern char D_005E0118[];
extern char D_005E0120[];
extern "C" void func_0045EC58(void *, void *);
extern "C" void func_0045EEE0(void *, f32, f32, f32, f32);
extern "C" void func_0045F2B8(void *, f32, f32);
extern "C" void func_0045F378(void *, const char *, ...);

extern "C" void func_0011BB80(Self *arg0, s32 arg1, f32 fparg0) {
    fparg0 += 12.5f;
    Ent *e = &D_00579848[arg1];
    f32 v = arg0->f2F4;
    v -= fparg0;
    func_0045EC58((void *)D_00586EF4, D_005E0110);
    Mgr *m = (Mgr *)D_00586EF4;
    m->f28 = 2.0f;
    m->f24 = 2.0f;
    func_0045F2B8((void *)D_00586EF4, 64.0f, v);
    func_0045EEE0((void *)D_00586EF4, e->x, e->y, e->z, 0x1.999998p-2f);
    func_0045F378((void *)D_00586EF4, D_005E0118, D_005E0120[arg1]);
}
