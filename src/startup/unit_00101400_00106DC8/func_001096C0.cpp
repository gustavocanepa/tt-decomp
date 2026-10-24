/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEnt { short adj; short pad; void (*fn)(void *, ...); };
struct Vt { char pad[0x90]; VEnt e90; VEnt e98; VEnt eA0; };
struct Self {
    char pad[0x64]; Vt *vt; char pad1[0xA0 - 0x68]; s32 fA0; s32 fA4;
};
extern s32 D_005794AC;
extern "C" void func_004A4D68(s32);
extern "C" void func_004A4DD8(s32);

extern "C" void func_001096C0(Self *arg0, s32 arg1) {
    s32 sub = (s32)arg0 + 0x6C;
    func_004A4D68(sub);
    if (arg1 == 0) {
        arg0->fA4 = 0;
        Vt *vt = arg0->vt;
        arg0->fA0 = 0;
        VEnt *e = &vt->e90;
        e->fn((char *)arg0 + e->adj, D_005794AC);
    } else if (arg0->fA4 != 0) {
        Vt *vt = arg0->vt;
        arg0->fA4 = 0;
        VEnt *e = &vt->eA0;
        e->fn((char *)arg0 + e->adj);
    }
    func_004A4DD8(sub);
}
