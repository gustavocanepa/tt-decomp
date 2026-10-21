/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Handler { void (*fn)(void); void *arg; int pad; };
struct Cmd { void *packet,*unused; void *iop; struct Handler *sys; int nsys; struct Handler *usr; int nusr; int *regs; };
struct Packet { int hdr[3]; int zero; void *buf; };
extern int D_005A30CC,D_0078C254;
extern char D_0078C180[],D_0078C200[];
extern struct Cmd D_0078C258;
extern struct Handler D_0078C280[32];
extern int D_0078C400[32];
extern struct Packet D_0078C240;
int func_005038D8(void),func_00503928(void);
void func_004FAAA0(int),func_004FAC00(void);
int func_004FA530(int,void (*)(void),int);
int func_004FB438(int),func_004FAC30(unsigned int);
int func_004FAC20(int,int);
int func_004FD930(int,void *,int,int,int,int);
void func_004FD3F0(void),func_004FD3D0(void),func_004FD9B0(void);
void func_004FD448(void) {
    struct Cmd *c;
    struct Handler *h;
    int i,addr;
    void *p1,*p2;
    struct Cmd *cmd;
    func_005038D8();
    if(D_005A30CC) { func_00503928(); return; }
    p2=(void *)((u32)D_0078C180|0x20000000);
    p1=(void *)((u32)D_0078C200|0x20000000);
    D_005A30CC=1;
    D_0078C258.packet=p2;
    D_0078C258.unused=p1;
    D_0078C258.iop=0;
    D_0078C258.sys=D_0078C280;
    D_0078C258.nsys=32;
    D_0078C258.usr=0;
    D_0078C258.nusr=0;
    D_0078C258.regs=D_0078C400;
    h=D_0078C280;
    do { h->fn=0; h->arg=0; h++; } while((int)h<(int)(D_0078C280+32));
    for(i=31;i>=0;i--) D_0078C400[i]=0;
    c=&D_0078C258;
    i=32;
    D_0078C280[0].fn=func_004FD3F0;
    D_0078C280[0].arg=c;
    D_0078C280[1].fn=func_004FD3D0;
    D_0078C280[1].arg=c;
    func_00503928();
    func_004FAAA0(0);
    if(*(volatile int *)0x1000e010&32) *(volatile int *)0x1000e010=i;
    if(!(*(volatile int *)0x1000c000&0x100)) func_004FAC00();
    D_0078C254=func_004FA530(5,func_004FD9B0,0);
    func_004FB438(5);
    addr=func_004FAC30(0x80000000);
    c->iop=(void *)addr;
    if(addr) {
        D_0078C240.buf=D_0078C180;
        func_004FD930(0x80000000,&D_0078C240,20,0,0,0); return;
    }
    while(!(func_004FAC30(4)&0x20000)) {}
    addr=func_004FAC30(2);
    cmd=&D_0078C258;
    cmd->iop=(void *)addr;
    func_004FAC20(0x80000000,addr);
    func_004FAC20(0x80000001,(int)cmd);
    D_0078C240.buf=D_0078C180;
    D_0078C240.zero=0;
    func_004FD930(0x80000002,&D_0078C240,20,0,0,0);
}
