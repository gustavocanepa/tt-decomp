/* compiler: ee-gcc2.9-991111 */
/* Operation 5 submits a caller buffer plus a cache-visible scratch area.
 * Pointer and size fields follow the packet; their original names are unknown. */
struct Client { char unknown0[0x24]; void *server; };
struct Command {
    int argument;
    char unknown4[8];
    int size;
    char unknown10[8];
    void *buffer, *scratch;
    char unknown20[16];
};
extern struct Client D_00782AC0;
extern struct Command D_00782B40;
extern char D_00782FC0[0xC0];
extern int D_005A0BF4, D_005A0BF0, D_00784080;
extern void func_004DB7B8(void *);
extern int func_004FA870(int);
extern int func_004FA840(int);
extern void func_004FDAF8(void *, int);
extern int func_004FE530(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_004DB868(int argument, void *buffer, int size) {
    if(!D_00782AC0.server) return -100;
    if(func_004FA870(D_005A0BF4)<0) return -200;
    D_00782B40.argument=argument;
    D_00782B40.buffer=buffer;
    D_00782B40.size=size;
    D_00782B40.scratch=D_00782FC0;
    func_004FDAF8(buffer,size);
    func_004FDAF8(D_00782FC0,0xC0);
    if(func_004FE530(&D_00782AC0,5,1,&D_00782B40,48,&D_00784080,4,
        func_004DB7B8,D_00782FC0)) {
        func_004FA840(D_005A0BF4);
        return -91;
    }
    D_005A0BF0=5;
    return 0;
}
