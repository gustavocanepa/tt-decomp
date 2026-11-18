/* compiler: ee-gcc2.9-991111 */
struct Block { int w[4]; };
extern int D_005A1F80[6];
extern int D_005A0DAC;
extern char D_005A2900[];
extern int func_004DF890(int);
extern void func_004FA840(int);
extern int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
int func_004E1730(struct Block *out,int *n) {
 int *buf;
 int r;
 if(!func_004DF890(5)) return 0;
 buf=D_005A1F80;
 if(func_004FE530(D_005A2900,26,0,0,0,buf,24,0,0)<0) {
 func_004FA840(D_005A0DAC); return 0;
 }
 *out=*(struct Block *)((unsigned int)(buf+2)|0x20000000);
 *n=*(int *)((unsigned int)(buf+1)|0x20000000);
 r=*(int *)((unsigned int)buf|0x20000000);
 func_004FA840(D_005A0DAC);
 return r;
}
