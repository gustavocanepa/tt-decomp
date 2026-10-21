/* compiler: ee-gcc2.9-991111 */
extern volatile int D_005A0DE0;
extern volatile int D_005A0DE4, D_005A0DB4;
extern volatile int D_005A0DA8, D_005A0DA0;
extern volatile int D_005A0D94, D_0078A640;
extern int func_004FA850(int);
void func_004DECD0(int *p) {
 D_005A0DE0 = *p;
 D_005A0DE4 = D_005A0DE0;
 if (D_005A0DE0 == 11) {
  D_005A0DE0 = 0;
  D_005A0DB4 = 0;
  return;
 }
 func_004FA850(D_005A0DA8);
 if (D_005A0D94 && D_0078A640) func_004FA850(D_005A0DA0);
 else D_005A0DB4 = 0;
 D_005A0DE0 = 0;
}
