/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a,max,init,d,e; const char *opt; };
struct Blk { int sema; int *res; int n8; char path[0x400]; char newname[0x400]; };
extern struct Blk D_0078DD00;
extern int D_005A315C;
extern char D_0078F400[], D_0078E940[], D_00617BC0[];
extern int func_004FA820(struct Sema *);
extern void func_004FA830(int);
extern int func_004FA860(int);
extern u32 func_004FEDD8(int,int,int,int,int,int,int,int,int,int);
extern int func_004FF348(int);
extern void func_004FF378(void),func_004FF470(void);
int func_005024C0(const char *path, const char *newname) {
 struct Blk *b=&D_0078DD00;
 int i,sema,res,ok;
 struct Sema sp;
 func_004FF348(0x11);
 if (D_005A315C==0) func_004FF470();
 for(i=0;i<0x400;i++) { if((b->path[i]=path[i])==0) break; }
 if(i==0x400) b->path[0x3ff]=0;
 for(i=0;i<0x400;i++) { if((b->newname[i]=newname[i])==0) break; }
 if(i==0x400) b->newname[0x3ff]=0;
 sp.max=1; sp.opt=D_00617BC0; sp.init=0;
 sema=func_004FA820(&sp);
 b->res=&res; b->sema=sema; b->n8=4;
 if((int)func_004FEDD8((int)D_0078F400,0x18,0,(int)&D_0078DD00,0x80c,(int)D_0078E940,4,0,0,0)<0) {
 func_004FA830(sema); func_004FF378(); return -11; }
 ok=*(int *)((u32)D_0078E940|0x20000000);
 func_004FF378();
 if(ok==0) { func_004FA830(sema); return -11; }
 func_004FA860(sema); func_004FA830(sema); return res;
}
