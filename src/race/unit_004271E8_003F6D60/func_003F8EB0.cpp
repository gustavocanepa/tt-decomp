typedef int s32;
struct Obj { s32 v; };
extern "C" char D_00769558[];
extern "C" char D_00769560[];
extern "C" char D_005F9D08[];
extern "C" char D_005F9DE8[];
extern "C" void func_004AC368(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_003F8EB0(s32 init, s32 prio) {
    if (prio == 0xFFFF && init == 1)
        func_004AC368((Obj *)D_00769558, (s32)D_005F9D08, 0x10);
    if (prio == 0xFFFF && init == 1)
        func_004AC368((Obj *)D_00769560, (s32)D_005F9DE8, 0xF);
}
