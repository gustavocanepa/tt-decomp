/* compiler: ee-gcc2.9-991111 */
extern int D_005A0D90,D_005A0DD0,D_005A0DC0;
extern volatile int D_005A0DB0;
extern char D_00614D30[],D_00614CF8[],D_00614D18[];
extern int D_0078A8D0,D_005A2800;
struct Cl { char pad[36]; int server; };
extern struct Cl D_0078A890;
void func_004DEF98(void);
int func_004DFD80(int);
void func_004FA840(int);
int func_004FA870(int);
void func_004FD2D0(const char *,...);
void func_004FDAF8(void *,int);
void func_004FDBA8(int);
int func_004FE350(void *,int,int);
int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
int func_005038D8(void);
int func_00503928(void);
int func_004DFF98(int mode) {
 int i,j,r;
 if(D_005A0D90>0) func_004FD2D0(D_00614D30);
 func_004DEF98();
 if(D_005A0DB0!=func_004FA870(D_005A0DB0)) return mode!=8?6:-1;
 func_004FDBA8(0);
 i=0;
 if(D_005A0DD0<0) {
  for(;;) {
   if(func_004FE350(&D_0078A890,0x8000059C,0)<0) {
    if(D_005A0D90>0) func_004FD2D0(D_00614CF8);
    for(j=0x100000;j!=-1;j--);
    continue;
   }
   if(D_0078A890.server) { D_005A0DD0=0; break; }
   if(i>=17) {
    func_004FA840(D_005A0DB0);
    return func_004DFD80(mode);
   }
   for(j=0x100000;j!=-1;j--);
   i++;
  }
 }
 r=func_005038D8();
 D_005A0DC0=0;
 if(r) func_00503928();
 D_0078A8D0=mode;
 func_004FDAF8(&D_0078A8D0,4);
 if(func_004FE530(&D_0078A890,0,0,&D_0078A8D0,4,&D_005A2800,4,0,0)<0) {
  func_004FA840(D_005A0DB0);
  return mode!=8?6:-1;
 }
 if(D_005A0D90>0) func_004FD2D0(D_00614D18);
 r=*(int *)((unsigned)&D_005A2800|0x20000000);
 func_004FA840(D_005A0DB0);
 return r;
}
