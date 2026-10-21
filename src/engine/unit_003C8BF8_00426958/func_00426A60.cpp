typedef int s32;
extern "C" void func_004A6328(float *a0, float *a1, float a2);

extern "C" void func_00426A60(char *arg0) {
    float s[2];
    float s0;
    float s1;
    float c;
    char *v0;
    char *v1;
    s32 n;
    func_004A6328(&s[0], &s[1], *(float *)(arg0 + 0x3A0));
    v0 = arg0 + 0x10;
    v1 = arg0 + 0xC;
    s1 = s[1];
    s0 = s[0];
    n = 7;
    do {
        c = *(float *)v1;
        n -= 1;
        *(float *)(v1 + 0x10) = ((s1 * c) - (s0 * *(float *)v0)) + *(float *)(arg0 + 0x394);
        v1 += 0x44;
        *(float *)(v0 + 0x10) = ((s0 * c) + (s1 * *(float *)v0)) + *(float *)(arg0 + 0x398);
        v0 += 0x44;
    } while (n >= 0);
}
