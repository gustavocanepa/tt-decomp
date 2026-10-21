/* compiler: ee-gcc2.9-991111 */
extern int D_005A23C0;
extern int D_005A1F80[];
extern int D_005A0DAC;
extern char D_005A2900[];
int func_004DF890(int);
void func_004FDAF8(void *,int);
void func_004FA840(int);
int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
int func_004E1928(int param,int *stat) {
 int *buf;
 int r;
 int *send=&D_005A23C0;
 if(!func_004DF890(13)) return 0;
 D_005A23C0=param;
 func_004FDAF8(send,4);
 buf=D_005A1F80;
 if(func_004FE530(D_005A2900,21,0,send,4,buf,8,0,0)<0) {
 func_004FA840(D_005A0DAC); return 0;
 }
 *stat=*(int *)((unsigned int)(buf+1)|0x20000000);
 r=*(int *)((unsigned int)buf|0x20000000);
 func_004FA840(D_005A0DAC);
 return r;
}
