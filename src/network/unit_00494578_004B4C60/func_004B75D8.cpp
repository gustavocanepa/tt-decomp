/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char flag; char pad[0x3f]; int a40; char pad44[0x10]; int a54; char pad58[0xc]; int a64, a68; };
extern "C" void func_004B7588(Obj *) throw();
extern "C" int func_005038D8(void);
extern "C" void func_004B75D8(Obj *o, int value, int data) {
    int enabled = func_005038D8();
    o->a68 = data;
    int command = value;
    if (value < -10) command = -11;
    if (value < 0) {
        o->flag = 0;
        o->a40 = 0;
        if (command != -11) {
            if (command == -1) {
                func_004B7588(o);
                o->a54 = 1;
                o->a64 = 1;
            }
        } else {
            func_004B7588(o);
        }
    }
    if (enabled) __asm__ volatile("ei");
}
