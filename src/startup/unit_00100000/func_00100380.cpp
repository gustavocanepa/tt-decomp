struct func_00100380_Vec {
    float x, y, z;
};

struct func_00100380_Obj {
    char pad0[0x6C];
    char x6c[0x9C - 0x6C];
    int mode;
    int pending;
};

extern char D_005794F0[];
extern func_00100380_Vec D_00578D10;

extern "C" {
void func_00105D18(void *p);
void func_001059B0(void *p);
void func_001063B0(void *p, int a, int b, int c, int d);
void func_00470450(int a);
void func_00470B10(float x, float y, float z, float w);
void func_00100330(void);
void func_004AEB30(void *p);
}

extern "C" void func_00100380(func_00100380_Obj *self) {
    if (self->pending) {
        switch (self->mode) {
        case 1:
            func_00105D18(D_005794F0);
            break;
        case 2:
            func_001059B0(D_005794F0);
            break;
        case 3:
            func_001063B0(D_005794F0, 1, 2, -1, -1);
            break;
        case 4:
            func_001063B0(D_005794F0, 2, 0x50, -1, -1);
            break;
        case 5:
            func_001063B0(D_005794F0, 2, 0x51, -1, -1);
            break;
        }
        func_00470450(-1);
        func_00470B10(D_00578D10.x, D_00578D10.y, D_00578D10.z, 0.0f);
        func_00100330();
        func_004AEB30(self->x6c);
        self->pending = 0;
    }
}
