/* compiler: ee-gcc2.9-991111 */
/* Synchronous operation 21: serialize the shared packet, submit the RPC,
 * release the semaphore, then return the server's result word. */
struct Client { char unknown0[0x24]; void *server; };
struct Command { int argument0, argument1; char unknown8[40]; };
extern struct Client D_00782AC0;
extern struct Command D_00782B40;
extern int D_005A0BF4, D_00784080;
extern int func_004FA870(int);
extern int func_004FA840(int);
extern int func_004FE530(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_004DB3F8(int argument) {
    if(!D_00782AC0.server) return -100;
    if(func_004FA870(D_005A0BF4)<0) return -200;
    D_00782B40.argument1=argument;
    if(func_004FE530(&D_00782AC0,21,0,&D_00782B40,48,&D_00784080,4,0,0)) {
        func_004FA840(D_005A0BF4);
        return -91;
    }
    func_004FA840(D_005A0BF4);
    return D_00784080;
}
