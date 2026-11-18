/* compiler: ee-gcc2.9-991111 */
struct Result { char bytes[36]; };
struct Request { struct Result result; char name[256]; void *self; int mode; };
typedef struct { char pad[0x24]; int f24; } Dev;
extern struct Request D_0078A6C0;
extern Dev D_0078A840;
extern int D_0078A800;
extern volatile int D_005A0DA8;
extern int D_005A0D9C, D_005A0DCC, D_005A0D90;
extern char D_00614BA0[], D_00614BC0[], D_00614BD8[], D_00614BE8[], D_00614BF8[];
extern void func_004DEF98(void);
extern int func_004FA870(int);
extern int func_004DF780(int);
extern void func_004FDBA8(int);
extern int func_004FE350(void *, int, int);
extern void func_004FD2D0(const char *, ...);
extern void func_004FDAF8(void *, int);
extern int func_004FE530(void *, int, int, void *, int, void *, int, void *, void *);
extern void func_004FA840(int);
int func_004DF270(struct Result *out, char *name, int mode) {
    int i, d, result;
    func_004DEF98();
    if (D_005A0DA8 != func_004FA870(D_005A0DA8)) return 0;
    D_005A0D9C = 1;
    if (func_004DF780(1)) {
        func_004FA840(D_005A0DA8);
        return 0;
    }
    {
        func_004FDBA8(0);
        if (D_005A0DCC < 0) {
            for (;;) {
                if (func_004FE350(&D_0078A840, 0x80000597, 0) < 0) {
                    if (D_005A0D90 > 0) func_004FD2D0(D_00614BA0);
                    for (d = 0x100000; d != -1; d--) ;
                    continue;
                }
                if (D_0078A840.f24 != 0) { D_005A0DCC = 0; break; }
                for (d = 0x100000; d != -1; d--) ;
            }
        }
        for (i = 0; i < 256; i++) {
            if (!(D_0078A6C0.name[i] = name[i])) break;
        }
        if (i == 256) D_0078A6C0.name[255] = 0;
        if (D_005A0D90 > 0) func_004FD2D0(D_00614BC0, D_0078A6C0.name);
        D_0078A6C0.mode = mode;
        D_0078A6C0.self = &D_0078A6C0;
        func_004FDAF8(&D_0078A6C0, 300);
        if (func_004FE530(&D_0078A840, 0, 0, &D_0078A6C0, 300, &D_0078A800, 4, 0, 0) < 0) {
            func_004FA840(D_005A0DA8);
            return 0;
        }
        {
            *out = *(struct Result *)((unsigned int)&D_0078A6C0 | 0x20000000);
            if (D_005A0D90 > 0) func_004FD2D0(D_00614BD8, out->bytes + 8);
            if (D_005A0D90 > 0) func_004FD2D0(D_00614BE8, *(int *)(out->bytes + 4));
            if (D_005A0D90 > 0) func_004FD2D0(D_00614BF8, *(int *)out->bytes);
            result = *(int *)((unsigned int)&D_0078A800 | 0x20000000);
            func_004FA840(D_005A0DA8);
            return result;
        }
    }
}
