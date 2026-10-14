struct In {char pad[0x30]; float d;};
struct Obj {char pad0[0x34]; float x; char pad1[4]; float z; char pad2[0x20]; float v60[3]; float v6C[4]; int cnt;};
extern "C" void func_00318E60(Obj *, float, float) throw();
extern "C" void func_00552A68(float *, float *);
extern "C" void func_0031A3E8(Obj *self, In *in){
    float *p60 = self->v60;
    float *p6c = self->v6C;
    float a = self->v6C[2];
    float d = in->d * 2.0f;
    float old = a;
    if (d != 0.0f) {
        if (a == 0.0f) {
            int c = self->cnt;
            if (c <= 0) {
                a = a + d;
                if (a <= -90.0f) a = -90.0f;
                if (a >= 90.0f) a = 90.0f;
            } else self->cnt = c - 1;
        } else {
            a = a + d;
            int hit = 0;
            if (a <= -90.0f) a = -90.0f;
            if (a >= 90.0f) a = 90.0f;
            if (a < 0.0f) { if (old > 0.0f) hit=1; }
            else if (a > 0.0f) { if (old < 0.0f) hit=1; }
            else if (a == 0.0f) hit=1;
            if (hit) { a = 0.0f; self->cnt = 9; }
            else self->cnt = 0;
        }
    } else self->cnt = 0;
    p6c[2] = a;
    func_00552A68(p60, &self->x);
    func_00318E60(self, self->x, self->z);
}
