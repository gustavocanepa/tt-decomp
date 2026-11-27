/* compiler: ee-gcc2.9-991111 */
/* Submit an asynchronous two-argument operation under the library semaphore.
 * The RPC callback signals a separate completion semaphore. */
struct Client { char unknown0[0x24]; void *server; };
struct Command { int argument0, argument1, argument2; char unknownC[36]; };
extern struct Client D_00782AC0;
extern struct Command D_00782B40;
extern int D_005A0BF4, D_005A0BF0;
extern char D_00784080;
extern void func_004DB328(void *);
extern int func_004FA870(int);
extern int func_004FA840(int);
extern int func_004FE530(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_004DC128(int argument0, int argument1) {
    if(!D_00782AC0.server) return -100;
    if(func_004FA870(D_005A0BF4)<0) return -200;
    D_00782B40.argument1=argument0;
    D_00782B40.argument2=argument1;
    if(func_004FE530(&D_00782AC0,16,1,&D_00782B40,48,&D_00784080,4,func_004DB328,0)) {
        func_004FA840(D_005A0BF4);
        return -91;
    }
    D_005A0BF0=16;
    return 0;
}
