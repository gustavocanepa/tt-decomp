typedef float f32;
typedef unsigned char u8;
void func_00303110(void);
void func_00303548(void *a);
f32 func_002F5040(char *a, void *b);
void func_002E4750(void *a, f32 b);
void func_002E4870(void *a, f32 b);
void func_002E4B50(void *a, f32 b);
void func_00303450(void *a);
void func_003031D8(void *a);
extern char D_00582E98[];
void func_00303668(char *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    char *temp_s1;
    char *temp_s2;

    temp_s2 = arg0 + 0x104;
    temp_s1 = arg0 + 0x6F8;
    func_00303110();
    *(f32 *)(temp_s2 + 0x5E0) = *(f32 *)(temp_s2 + 0x55C);
    func_00303548(arg0);
    temp_f1 = *(f32 *)(temp_s2 + 0x5E0);
    if (temp_f1 < 0.0f) {
        *(f32 *)(temp_s2 + 0x5E0) = -temp_f1;
    }
    if (*(u8 *)(temp_s1 + 0x14) == 0) {
        temp_f0 = func_002F5040(D_00582E98, arg0);
        func_002E4750(temp_s1, temp_f0);
        func_002E4870(temp_s1, temp_f0);
        func_002E4B50(temp_s1, temp_f0);
    }
    if (*(u8 *)(temp_s2 + 0x4D2) == 0) {
        if (*(f32 *)(arg0 + 0x6E8) < *(f32 *)(arg0 + 0x6E4)) {
            *(f32 *)(arg0 + 0x6E8) = *(f32 *)(arg0 + 0x6E4);
        }
    }
    func_00303450(arg0);
    func_003031D8(arg0);
}
