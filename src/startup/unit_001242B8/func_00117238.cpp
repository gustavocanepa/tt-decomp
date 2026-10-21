typedef int s32;
typedef signed char s8;

struct Text5 { char c[5]; };
struct func_00439200_Obj;
struct func_00439300_p;

extern char *D_00579774;
extern void *D_00586EF8;
extern "C" const Text5 D_005DFCC8;
extern char D_005865D0[];
extern "C" const char *func_00439200(struct func_00439200_Obj *p);
extern "C" char *func_00439300(struct func_00439300_p *p);
extern "C" void func_0045F468(void *a, void *b, s32 c, s32 d, const char *e, char *f, char *g);

extern "C" void func_00117238(s32 dummy, s32 size, char *buf) {
    char *v = D_00579774;
    char *s3 = v + 0x4C4;
    s32 s4 = *(s32 *)(v + 0x4C0);
    if (*s3 == 0x2D) {
        *(Text5 *)buf = D_005DFCC8;
        return;
    }
    const char *s1 = func_00439200((struct func_00439200_Obj *)D_005865D0);
    char *b = func_00439300((struct func_00439300_p *)D_005865D0);
    func_0045F468(D_00586EF8, buf, size, s4, s1, s3, b);
}
