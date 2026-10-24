/* compiler: ee-gcc2.9-991111 */
/* SIF reboot command. Layout follows the packet fields and DMA descriptor in
 * the executable; names are provisional pending SDK header identification. */
typedef unsigned int u32;
struct Packet {
    unsigned long long size:8;
    unsigned long long data_size:24;
    unsigned long long destination:32;
    u32 command, option;
    int argument_length, mode;
    char arguments[80];
};
struct Dma { void *source; u32 destination; int size, attributes; };
extern struct Packet D_0078F740;
extern void func_00505AD0(int, int);
extern void func_004FAAF0(void);
extern u32 func_004FAC30(int);
extern void func_004FAC20(u32, u32);
extern int func_004FABE0(struct Dma *, int);
extern void func_004FDAF8(void *, int);
int func_005035F8(char *arguments, int mode) {
    struct Dma transfer;
    u32 destination;
    int length;
    func_00505AD0(0,0);
    func_00505AD0(1,0);
    func_004FAAF0();
    destination=func_004FAC30(0x80000000);
    D_0078F740.mode=mode;
    for(length=0; arguments[length]; ++length)
        D_0078F740.arguments[length]=arguments[length];
    D_0078F740.destination=0;
    D_0078F740.argument_length=length;
    D_0078F740.command=0x80000003;
    D_0078F740.data_size=0;
    D_0078F740.size=104;
    transfer.source=&D_0078F740;
    transfer.destination=destination;
    transfer.size=104;
    transfer.attributes=0x44;
    func_004FDAF8(&D_0078F740,104);
    func_004FAC20(4,0x40000);
    if(func_004FABE0(&transfer,1)) {
        func_004FAC20(4,0x10000);
        func_004FAC20(4,0x20000);
        func_004FAC20(0x80000002,0);
        func_004FAC20(0x80000000,0);
        return 1;
    }
    return 0;
}
