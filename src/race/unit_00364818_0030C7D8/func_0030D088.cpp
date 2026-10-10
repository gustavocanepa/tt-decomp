struct Joint;

struct Obj {
    char pad[0x7C];
    char springs[0xC];
    float strength;
};

extern "C" void func_0030DC40(Obj *o, Joint *a, Joint *b, int *ival, float *fval);
extern "C" void func_0030CFF0(void *springs, Joint *a, Joint *b, int ival, float fval);

extern "C" void func_0030D088(Obj *o, Joint *a, Joint *b) {
    int iv;
    float fv;
    if (o->strength == 0.0f)
        return;
    func_0030DC40(o, a, b, &iv, &fv);
    func_0030CFF0(o->springs, a, b, iv, fv);
    func_0030CFF0(o->springs, b, a, -iv, -fv);
}
