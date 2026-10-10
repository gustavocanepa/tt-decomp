/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
} State_005636E8;

extern State_005636E8 D_00779FB8;

int func_004CC818(int n);

void func_004CCAF8(int arg) {
    D_00779FB8.m8 = func_004CC818(3);
    D_00779FB8.mC = func_004CC818(4);
    D_00779FB8.m10 = func_004CC818(5);
    D_00779FB8.m4 = arg;
    D_00779FB8.m0 = 1;
}
