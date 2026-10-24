/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot { float pad; float a, b, c, d; };
extern "C" int func_00397420(void *, int, int) throw();
extern "C" void func_00397148(float *, float *, int, int, int) throw();

extern "C" void func_00397AF0(char *self, int idx, int arg2)
{
    float v[3];
    float w[4];
    float x, y, z;
    char *car = self + idx * 0x8D0;
    Slot *s0 = (Slot *)(car + 0x3E4);
    func_00397148(v, w, arg2, func_00397420(self, idx, 0), 0);
    float *py = &v[1];
    float *pz = &v[2];
    x = v[0]; z = *pz; y = *py; s0->a = x; s0->c = z; s0->b = y; s0->d = w[0];
    func_00397148(v, w, arg2, func_00397420(self, idx, 1), 1);
    Slot *s1 = (Slot *)(car + 0x55C);
    x = v[0]; z = *pz; y = *py; s1->a = x; s1->c = z; s1->b = y; s1->d = w[0];
    func_00397148(v, w, arg2, func_00397420(self, idx, 2), 0);
    Slot *s2 = (Slot *)(car + 0x6D4);
    x = v[0]; z = *pz; y = *py; s2->a = x; s2->c = z; s2->b = y; s2->d = w[0];
    func_00397148(v, w, arg2, func_00397420(self, idx, 3), 1);
    Slot *s3 = (Slot *)(car + 0x84C);
    float y2 = *py; float z2 = *pz; float x2 = v[0]; s3->b = y2; s3->a = x2; s3->c = z2; s3->d = w[0];
}
