/* compiler: ee-gcc2.9-991111 */
struct LoadReq { char pad[0x2C]; int result; };
struct ModLoad { int tid; int f4; int done_sema; int sema; struct LoadReq *req; };
extern struct ModLoad D_00782900;
extern int func_004FA710(void);
extern void func_004FA840(int);
extern int func_004FA860(int);
extern int func_004FA870(int);

/* _sceErxSync */
int func_004D6430(unsigned int mode, int *result)
{
    struct LoadReq *req;

    if (D_00782900.tid < 0)
        return 0x81058001;
    if (func_004FA710() == D_00782900.tid)
        return 0x8105002D;
    if (mode >= 2)
        return 0x81050016;
    if (result == 0)
        return 0x8105000E;
    if (D_00782900.req == 0)
        return 0x81050003;
    if (mode == 0) {
        func_004FA860(D_00782900.sema);
    } else if (mode == 1) {
        if (func_004FA870(D_00782900.sema) < 0)
            return 1;
    }
    req = D_00782900.req;
    D_00782900.req = 0;
    *result = req->result;
    func_004FA840(D_00782900.done_sema);
    return 0;
}
