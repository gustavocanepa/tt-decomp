struct Config {
    char pad[0xED];
    unsigned char a;
    unsigned char b;
    unsigned char angle[2];
    unsigned char scale[2];
    unsigned char count[2];
};

struct Settings {
    int a;
    int b;
    float angle[2];
    float scale[2];
    float count[2];
};

extern Config D_00583868;
extern Settings D_007672A8;

extern "C" void func_002EF900(void) {
    D_007672A8.a = D_00583868.a;
    D_007672A8.b = D_00583868.b;
    for (int i = 0; i < 2; i++) {
        float f = D_00583868.angle[i];
        if (D_00583868.angle[i] == 0) D_007672A8.a = 0;
        D_007672A8.angle[i] = f * 0.0017453288892284036f;
        D_007672A8.scale[i] = D_00583868.scale[i] * 10.0f;
        D_007672A8.count[i] = D_00583868.count[i];
    }
}
