typedef int s32;

struct Self { char pad[0x18]; s32 m18; };
extern char D_005F5870[];
extern char D_005F5880[];
extern "C" void RaceDisplayObjectBase__selectTexture(Self *, char *);
extern "C" s32 func_00357310(char *);

extern "C" void func_00360598(Self *self) {
    RaceDisplayObjectBase__selectTexture(self, D_005F5870);
    self->m18 = func_00357310(D_005F5880);
}
