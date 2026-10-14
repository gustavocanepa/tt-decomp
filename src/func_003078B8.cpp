extern unsigned char D_00583868[];
extern int D_00583840;
extern float D_00583848[];
extern float D_00583850[];
extern float D_00583858[];
extern float D_00583860[];
extern "C" void func_003078B8(void) {
    unsigned char *a;
    float *b1;
    float *b2;
    float *b3;
    float *b4;
    float f0;
    float f1;
    float f2;
    float f3;
    int i;
    float k;
    float h;
    D_00583840 = D_00583868[0x102] != 0;
    if (D_00583840 != 0) {
        b1 = D_00583848;
        b2 = D_00583850;
        b3 = D_00583858;
        b4 = D_00583860;
        a = D_00583868 + 0x10B;
        k = 0.01f;
        h = 100.0f;
        i = 0;
        do {
            f1 = (float)a[-6] * k;
            f3 = (float)a[-4] / h;
            f0 = (float)a[-2] * k;
            f2 = (float)a[0] / h;
            b1[i] = f1;
            b2[i] = f3;
            b3[i] = f0;
            b4[i] = f2;
            a = a + 1;
            i = i + 1;
        } while (i < 2);
    }
}
