typedef int s32;

struct Mgr {
    char pad[0x44C];
    void *items[3];
};

extern Mgr *D_00579774;
extern "C" void GranTurismo4__GetTimeString(void *, s32, s32);

extern "C" void func_001170E0(void *arg0, s32 idx, s32 a, s32 b) {
    Mgr *m = D_00579774;
    if (m != 0 && idx < 3)
        GranTurismo4__GetTimeString(m->items[idx], a, b);
}
