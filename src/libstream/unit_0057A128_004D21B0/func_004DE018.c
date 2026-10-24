/* compiler: ee-gcc2.9-991111 */
struct P64 { char a[64]; };
struct Rq { int v0; int v4; };
extern struct P64 D_0078A540;
extern struct P64 D_0078A5C0;
extern int D_0078A600;
extern struct Rq D_00789E40;
extern char D_00789D40[];
extern void func_004DEC40(const char *, ...);
extern void func_004FA840(int);
extern int func_004FA860(int);
extern void func_004FB118(void *, void *);
extern int func_004FE530(void *, int, int, void *, int, void *, int, void *, int);
extern int func_005038D8(void);
extern int func_00503928(void);

int func_004DE018(int idx) {
    int r;
    func_004FB118(&D_0078A540, &D_0078A540 + 2);
    func_005038D8();
    D_0078A5C0 = D_0078A540;
    func_00503928();
    if (((int *)&D_0078A5C0)[idx] != 1) return -12;
    func_004FA860(D_0078A600);
    D_00789E40.v0 = idx;
    if (func_004FE530(D_00789D40, 0x80001303, 0, &D_00789E40, 0x90, &D_00789E40, 0x90, 0, 0) < 0) {
        func_004DEC40("sceDbcGetDepNumber: rpc error\n");
        func_004FA840(D_0078A600);
        return 0;
    }
    r = D_00789E40.v4;
    func_004FA840(D_0078A600);
    return r;
}
