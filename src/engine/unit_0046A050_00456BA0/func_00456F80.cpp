typedef int s32;

struct Encoder;
struct func_00457568_arg1;

extern s32 D_00602874;
extern s32 D_00602878;
extern char D_00602880[];
extern char D_006028A0[];
extern char D_006028C0[];
extern char D_00602978[];
extern char D_00586A70[];

extern "C" void func_00457310(s32 arg0, s32 arg1);
extern "C" void func_00457448(Encoder *e, const int *table, int id);
extern "C" void func_004574E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" void func_00457568(s32 *arg0, struct func_00457568_arg1 *arg1, s32 arg2, char **arg3);
extern "C" void func_00457688(s32 *arg0);

extern "C" void func_00456F80(Encoder *arg0) {
    s32 n = *(s32 *)((char *)arg0 + 0x8A8);
    if (n > 0) {
        func_00457310((s32)arg0, n);
    }
    func_00457448(arg0, (const int *)((char *)arg0 + 0x140), 0);
    func_00457448(arg0, (const int *)((char *)arg0 + 0x240), 1);
    {
        char *p1 = D_00602880;
        s32 v = D_00602874;
        func_004574E0((s32)arg0, (s32)p1, v, 0, 0);
        func_004574E0((s32)arg0, (s32)D_006028A0, v, 0, 1);
    }
    {
        char *p2 = D_006028C0;
        s32 w = D_00602878;
        func_004574E0((s32)arg0, (s32)p2, w, 1, 0);
        func_004574E0((s32)arg0, (s32)D_00602978, w, 1, 1);
    }
    func_00457568((s32 *)arg0,
                  (struct func_00457568_arg1 *)((char *)arg0 + 0x888),
                  (s32)((char *)arg0 + 0x8C4),
                  (char **)D_00586A70);
    func_00457688((s32 *)arg0);
}
