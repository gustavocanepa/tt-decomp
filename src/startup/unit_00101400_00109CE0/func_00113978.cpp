typedef int s32;
struct VEnt { short adj; short pad; s32 (*fn)(void *); };
struct Vt { char pad[0x98]; VEnt e98; };
struct Self { char pad[0x134]; Vt *vt; char pad2[0x130 - 0x130]; };
extern char D_005857DC_[];
extern s32 D_005857DC;
extern "C" void func_00370368(void *, s32);
extern "C" void RacePlayerSpec__createEquipments(void *, long, int, int);
extern "C" s32 func_0040EFA8(void *, s32);
extern "C" long func_0040F000(void *, s32);

extern "C" void func_00113978(Self *arg0) {
    func_00370368(arg0, D_005857DC + 0x44);
    VEnt *e = &arg0->vt->e98;
    void *o = (void *)e->fn((char *)arg0 + e->adj);
    s32 a = func_0040EFA8(o, 0);
    long b = func_0040F000(o, 0);
    long r = b - 1;
    if (~b == 0) r = 0;
    RacePlayerSpec__createEquipments((char *)arg0 + 0x138, a, (int)r, 1);
}
