struct P38 { char pad0[0x38]; float f38; };
struct P80 { char pad0[0x80]; P38 *p80; };
struct P4 { char pad0[4]; P80 *p4; };
struct P6C { char pad0[0x80]; P4 *p80; };
struct Self { char pad0[0x6C]; P6C *p6c; };

extern "C" void func_002D5D68(void *arg0, float arg1, float arg2);

extern "C" void func_002D1340(Self *arg0, void *arg1) {
    P6C *a2 = arg0->p6c;
    P38 *a1 = a2->p80->p4->p80;
    func_002D5D68(arg1, a1->f38, 1.0f);
}
