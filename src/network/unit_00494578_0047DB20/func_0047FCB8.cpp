/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    char pad[0x10];
    int m14;
};
extern char D_0058E060[];
extern char D_0079DD80[];
extern "C" void func_004A4D68(void *);
extern "C" void func_0047D988(O *);
extern "C" void func_004A4DD8(void *);

extern "C" void func_0047FCB8(O *o) {
    func_004A4D68(D_0058E060);
    o->m14 = (int)D_0079DD80;
    func_0047D988(o);
    func_004A4DD8(D_0058E060);
}
