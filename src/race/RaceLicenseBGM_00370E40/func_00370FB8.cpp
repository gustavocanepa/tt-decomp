/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_005D2760[];
extern "C" int func_00385EB0(char *self);
extern "C" void RacePause__structor_0(void *);
extern "C" void func_00370E40(void *) throw();
extern "C" void func_00371D18(void *);
extern "C" void func_003A3418(void *);
extern "C" void func_0037FAA0(void *);
extern "C" void LicenseConcourse__structor_0(void *);
extern "C" void func_0033E2F0(void *, void *);
extern "C" void func_00377730(void *, void *);
extern "C" void func_003803A8(void *, void *);
extern "C" void func_003715E0(void *, int);
extern "C" int func_00370FB8(char *self) {
    char *s1 = self + 0xF280;
    func_00385EB0(self);
    *(char **)(self + 0x64) = D_005D2760;
    RacePause__structor_0(s1);
    func_00370E40(self + 0xF2B8);
    func_00371D18(self + 0x104A8);
    func_003A3418(self + 0x15DC0);
    func_0037FAA0(self + 0x39F90);
    LicenseConcourse__structor_0(self + 0x3A8C0);
    *(void **)(self + 0x74) = self + 0xF2B8;
    func_0033E2F0(self, self + 0x104A8);
    *(void **)(self + 0x70) = self + 0x15DC0;
    *(int *)(s1 + 0x28) = 1;
    func_00377730(s1, self + 0xE418);
    func_003803A8(self + 0x39F90, self + 0xE418);
    func_003715E0(self, 0);
    *(int *)(self + 0xE2C) = 3;
    *(int *)(self + 0xCFE0) = 0;
}
