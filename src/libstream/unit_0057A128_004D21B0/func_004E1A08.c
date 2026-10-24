/* compiler: ee-gcc2.9-991111 */
extern int D_005A23C0;
extern volatile int D_005A0DAC;
extern int D_005A1F80[2];
extern char D_005A2900[];
extern int func_004DF890(int);
extern void func_004FA840(int);
extern void func_004FDAF8(void *,int);
extern int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
int func_004E1A08(int a,unsigned int *out) {
 int *send=&D_005A23C0;
 int *buf;
 int r;
 if(!func_004DF890(26)) return -1;
 D_005A23C0=a;
 func_004FDAF8(send,4);
 buf=D_005A1F80;
 if(func_004FE530(D_005A2900,5,0,send,4,buf,8,0,0)<0) {
 func_004FA840(D_005A0DAC); return -1;
 }
 if(out) *out=*(unsigned int *)((unsigned int)(buf+1)|0x20000000);
 r=*(int *)((unsigned int)buf|0x20000000);
 func_004FA840(D_005A0DAC);
 return r;
}
