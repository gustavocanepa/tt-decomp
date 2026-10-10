struct Inner { char pad[0x4E8]; char f4a0[1]; };
struct Outer { char pad[0x14]; struct Inner *inner; };
extern int func_002E4630(void *);
extern int func_004393E0(void *);
extern void func_0045F468(int, int, int, int, int);
extern char D_005865D0[];
extern int D_00586EF8;
void func_00132120(struct Outer *o, int a, int b)
{
    int r = func_002E4630(o->inner->f4a0);
    int s = func_004393E0(D_005865D0);
    func_0045F468(D_00586EF8, b, a, r, s);
}
