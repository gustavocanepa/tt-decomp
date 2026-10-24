/* compiler: ee-gcc2.9-991111 */
extern volatile int D_005A0DAC;
extern volatile int D_005A0DE0;
extern char D_005A2900[];
extern int D_005A1F80[];
int func_004DF890(int);
void func_004FA840(int);
int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
int func_004E1408(void) {
 int r;
 if(!func_004DF890(30)) return 0;
 D_005A0DE0=8;
 if(func_004FE530(D_005A2900,22,0,0,0,D_005A1F80,4,0,0)<0) {
 func_004FA840(D_005A0DAC);
 D_005A0DE0=0;
 return 0;
 }
 D_005A0DE0=0;
 r=*(int *)((unsigned int)D_005A1F80|0x20000000);
 func_004FA840(D_005A0DAC);
 return r;
}
