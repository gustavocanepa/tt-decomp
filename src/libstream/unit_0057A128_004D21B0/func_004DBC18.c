/* compiler: ee-gcc2.9-991111 */
/* Operation 1 requests up to three optional result words. Keep their output
 * pointers for the completion callback and pass presence flags in the packet. */
struct Client { char unknown0[0x24]; void *server; };
struct Command {
    int unknown0, argument0, argument1, want2, want1, want0;
    int unknown18;
    void *scratch;
    char unknown20[16];
};
extern struct Client D_00782AC0;
extern struct Command D_00782B40;
extern char D_00782FC0[0xC0];
extern int *D_00782AE8, *D_00782AEC, *D_00782AF0;
extern int D_005A0BF4, D_005A0BF0, D_00784080;
extern int func_004FA870(int);
extern int func_004FA840(int);
extern void func_004FDAF8(void *, int);
extern void func_004DBBC0(void *);
extern int func_004FE530(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_004DBC18(int argument0, int argument1, int *output0, int *output1, int *output2) {
    if(!D_00782AC0.server) return -100;
    if(func_004FA870(D_005A0BF4)<0) return -200;
    D_00782B40.argument0=argument0;
    D_00782B40.argument1=argument1;
    D_00782B40.scratch=D_00782FC0;
    if(output0) D_00782B40.want0=1; else D_00782B40.want0=0;
    if(output1) D_00782B40.want1=1; else D_00782B40.want1=0;
    if(output2) D_00782B40.want2=1; else D_00782B40.want2=0;
    D_00782AE8=output0;
    D_00782AEC=output1;
    D_00782AF0=output2;
    func_004FDAF8(D_00782FC0,0xC0);
    if(func_004FE530(&D_00782AC0,1,1,&D_00782B40,48,&D_00784080,4,
        func_004DBBC0,D_00782FC0)) {
        func_004FA840(D_005A0BF4);return -91;
    }
    D_005A0BF0=1;
    return 0;
}
