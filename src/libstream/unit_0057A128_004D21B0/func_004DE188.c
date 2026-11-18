/* compiler: ee-gcc2.9-991111 */
struct Block { int w[16]; };
extern struct Block D_0078A540, D_0078A5C0;
extern void func_004FB118(void *,void *);
extern int func_005038D8(void);
extern int func_00503928(void);
int func_004DE188(int i) {
 func_004FB118(&D_0078A540,(char *)&D_0078A540+128);
 func_005038D8();
 D_0078A5C0=D_0078A540;
 func_00503928();
 return D_0078A5C0.w[i]==1 ? 1:3;
}
