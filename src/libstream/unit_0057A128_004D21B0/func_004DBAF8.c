/* compiler: ee-gcc2.9-991111 */
extern int D_005A0BF0;
extern int D_005A0BF4;
extern int D_005A0BF8;
extern int D_00784080;
void func_004FA840(int);
int func_004FA860(int);
int func_004FA870(int);

int func_004DBAF8(int arg0, int *arg1, int *arg2) {
    int state;
    if (D_005A0BF0 == 0) return -1;
    if (func_004FA870(D_005A0BF8) < 0) state = 1;
    else state = 0;
    if (arg0 == 0 && state != 0) {
        state = 0;
        func_004FA860(D_005A0BF8);
    }
    state = state == 0;
    if (arg1 != 0) *arg1 = D_005A0BF0;
    if (state != 0) {
        D_005A0BF0 = 0;
        if (arg2 != 0) *arg2 = D_00784080;
        func_004FA840(D_005A0BF4);
    }
    return state;
}
