/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[8]; int width; };
extern "C" void func_00104C88(void *);
extern "C" int func_00104E00(void *);
extern "C" void func_0046F0F8(int);
extern "C" void func_00477DC0(int);
extern "C" void func_004702D8(int, float);
extern "C" void func_00474090(int, int, int, int);
extern "C" void func_00391788(void *unused, Obj *obj, float amount) {
    func_00104C88(obj);
    func_0046F0F8(6);
    float one = 1.0f;
    float blend = one - amount;
    func_00477DC0(0xFFFFFF);
    int width = obj->width;
    int height = func_00104E00(obj);
    func_004702D8(0x68, blend);
    func_00474090(0, 0, width, height);
    func_004702D8(0x62, blend);
    func_00474090(0, 0, width, height);
}
