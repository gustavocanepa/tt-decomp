typedef int s32;

extern "C" void RaceDisplayObjectBase__selectTexture(void *arg0, const char *arg1);

extern "C" s32 D_005865D0[];
extern "C" char D_005F5720[];
extern "C" char D_005F5738[];
extern "C" char D_005F5750[];
extern "C" char D_005F5760[];
extern "C" char D_005F5770[];

extern "C" void func_0035D400(char *arg0) {
    const char *name;
    s32 v = *(s32 *)D_005865D0;

    if (v == 0) {
        name = D_005F5738;
    } else if (v == 1) {
        name = D_005F5720;
    } else {
        name = D_005F5738;
    }
    RaceDisplayObjectBase__selectTexture(arg0 + 0x30, name);
    RaceDisplayObjectBase__selectTexture(arg0 + 0x328, D_005F5750);
    RaceDisplayObjectBase__selectTexture(arg0 + 0x2A0, D_005F5760);
    RaceDisplayObjectBase__selectTexture(arg0 + 0x2E4, D_005F5770);
}
