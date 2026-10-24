/* compiler: ee-gcc2.9-991111 */
struct Req { int a, result, cmd, d, x, y; };
struct Arg { int a,b,x,y; };
extern int D_0078A600;
extern struct Req D_00789E40;
extern char D_00789D40[];
extern void func_004DEC40(const char *, ...);
extern void func_004FA840(int);
extern int func_004FA860(int);
extern int func_004FE530(void *, int, int, void *, int, void *, int, void *, void *);
int func_004DE490(struct Arg *arg) {
    struct Req *r;
    int result;
    func_004FA860(D_0078A600);
    r = &D_00789E40;
    r->cmd = 2;
    r->x = arg->x;
    r->y = arg->y;
    if (func_004FE530(D_00789D40, 0x8000131D, 0, r, 0x90, r, 0x90, 0, 0) < 0) {
        func_004DEC40("sceDbcGetDeviceStatus: rpc error\n");
        func_004FA840(D_0078A600);
        return -1;
    }
    result = r->result;
    func_004FA840(D_0078A600);
    return result;
}
