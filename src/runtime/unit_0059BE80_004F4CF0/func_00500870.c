/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a,max,init,d,e; const char *opt; };
struct Blk { int sema; int *res; int n8; int fd,request; char data[0x400]; void *buf; u32 buflen,arglen; };
struct Entry { int fd,used; };
extern struct Blk D_0078DD00;
extern int D_005A315C;
extern char D_0078F400[],D_0078E940[],D_00617A70[];
extern int func_004FA820(struct Sema *);
extern void func_004FA830(int);
extern int func_004FA860(int);
extern void *func_004F64C4(void *,const void *,u32);
extern void func_004FDAF8(void *,int);
extern u32 func_004FEDD8(int,int,int,int,int,int,int,int,int,int);
extern struct Entry *func_004FEEC8(u32);
extern int func_004FF348(int);
extern void func_004FF378(void),func_004FF470(void);
int func_00500870(u32 fd,int request,const void *argp,u32 arglen,void *bufp,u32 buflen) {
 struct Blk *b=&D_0078DD00;
 struct Entry *e;
 int sema,res,ok;
 struct Sema sp;
 e=func_004FEEC8(fd);
 func_004FF348(0x1a);
 if(D_005A315C==0) func_004FF470();
 if(e==0 || e->used==0) { func_004FF378(); return -9; }
 if(arglen>0x400 || buflen>0x400) { func_004FF378(); return -22; }
 if(argp==0) b->arglen=0;
 else func_004F64C4(b->data,argp,arglen);
 b->fd=e->fd; b->request=request; b->arglen=arglen;
 sp.max=1; sp.init=0; sp.opt=D_00617A70;
 sema=func_004FA820(&sp);
 b->buflen=buflen; b->res=&res; b->n8=4; b->buf=bufp; b->sema=sema;
 func_004FDAF8(&D_0078DD00,0x420);
 if((int)func_004FEDD8((int)D_0078F400,0x1a,0,(int)&D_0078DD00,0x420,(int)D_0078E940,4,0,0,0)<0) {
 func_004FA830(sema); func_004FF378(); return -11; }
 ok=*(int *)((u32)D_0078E940|0x20000000);
 func_004FF378();
 if(ok==0) {func_004FA830(sema); return -11;}
 func_004FA860(sema); func_004FA830(sema); return res;
}
