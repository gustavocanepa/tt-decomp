/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void RaceDisplayObjectBase__selectTexture(void *, const char *);
extern "C" int func_00357310(const char *);
extern "C" int D_005865D0;
extern "C" char D_005F5780[], D_005F5760[], D_005F5770[], D_005F5750[];
extern "C" char D_005F5790[], D_005F5798[], D_005F57A0[];
extern "C" char D_005F57B0[], D_005F57B8[], D_005F57C0[], D_005F57C8[];
extern "C" void func_0035E098(char *self) {
    RaceDisplayObjectBase__selectTexture(self + 0x54, D_005F5780);
    RaceDisplayObjectBase__selectTexture(self + 0xB08, D_005F5760);
    RaceDisplayObjectBase__selectTexture(self + 0xB4C, D_005F5770);
    RaceDisplayObjectBase__selectTexture(self + 0xB90, D_005F5750);
    const char *name = D_005F5790;
    switch (D_005865D0) {
    case 0: break;
    case 1: name = D_005F5798; break;
    default: break;
    }
    RaceDisplayObjectBase__selectTexture(self + 0xBD4, name);
    RaceDisplayObjectBase__selectTexture(self, D_005F57A0);
    *(int *)(self + 0x44) = func_00357310(D_005F57B0);
    *(int *)(self + 0x48) = func_00357310(D_005F57B8);
    *(int *)(self + 0x4C) = func_00357310(D_005F57C0);
    *(int *)(self + 0x50) = func_00357310(D_005F57C8);
}
