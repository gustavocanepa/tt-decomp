/* compiler: ee-gcc2.9-991111 */
extern int D_005A23C0[2];
extern int D_005A1F80[];
extern int D_005A0DAC;
extern char D_005A2900[];
int func_004DF890(int);
void func_004FDAF8(void *,int);
void func_004FA840(int);
int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
int func_004E1588(int a,int b) {
 int *send=D_005A23C0;
 int *buf;
 int r;
 if(!func_004DF890(37)) return 0;
 D_005A23C0[0]=a;
 send[1]=b;
 func_004FDAF8(send,8);
 buf=D_005A1F80;
 if(func_004FE530(D_005A2900,37,0,send,8,buf,4,0,0)<0) {
 func_004FA840(D_005A0DAC); return 0;
 }
 r=*(int *)((unsigned int)buf|0x20000000);
 func_004FA840(D_005A0DAC);
 return r;
}
