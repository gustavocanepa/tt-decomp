/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VObj;
struct VEntry { short delta; short index; void (*fn)(void *); };
struct VObj {
    char pad[0x5C];
    s32 f5C;
    char pad60[4];
    char *vt;
};
extern "C" void func_00100CF8(void) throw();
extern "C" void RaceNetBattle__virtual_87(void);
extern "C" void func_00100EB8(void) throw();
extern "C" void func_00106DC8(void);
extern "C" void func_00106E00(void);
extern "C" void func_00106E20(void);
extern "C" void func_00106E90(void);
extern "C" void func_00106ED8(void);
extern "C" s32 func_00106F10(s32);
extern "C" void func_0046E150(void);
extern "C" void func_0046E1B0(void);
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_004A58A0(s32);
extern char D_0061BC70[];
extern VObj *D_00578EB0;
extern VObj *D_00578EB4;
extern s32 D_00578EB8;
extern volatile s32 D_00578EF4;

extern "C" void func_00100FE8(void) {
    s32 v = 0;
    func_00106DC8();
    func_00106E20();
    if (D_00578EF4 == 0) {
        do {
            func_0046E150();
            func_00106E90();
            if (v != 0) func_004A58A0(1000);
            func_00100CF8();
            func_00106ED8();
            func_0046E1B0();
            RaceNetBattle__virtual_87();
            func_00100EB8();
            func_004A4D68(D_0061BC70);
            if (D_00578EB8 != 0) {
                VObj *a = D_00578EB0;
                if (a != 0 && a->f5C == 0) {
                    VEntry *e = (VEntry *)(a->vt + 0x48);
                    e->fn((char *)a + e->delta);
                }
                VObj *b = D_00578EB4;
                if (b != 0) {
                    VEntry *e = (VEntry *)(b->vt + 0x10);
                    e->fn((char *)b + e->delta);
                }
                D_00578EB0 = D_00578EB4;
                D_00578EB4 = 0;
                D_00578EB8 = 0;
            }
            func_004A4DD8(D_0061BC70);
            v = func_00106F10(D_00578EF4);
        } while (D_00578EF4 == 0);
    }
    func_00106E00();
}
