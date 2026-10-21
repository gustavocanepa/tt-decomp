/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    char pad[0x1A80];
    int m3290;
};
extern "C" void func_0047FCB8(O *) throw();
extern "C" void func_004AEAF8(void *);
extern "C" void func_004AEB30(void *);

extern "C" void func_0047FF30(O *o) {
    for (;;) {
        func_004AEAF8((char *)o + 0x1960);
        if (o->m3290 == 0) {
            break;
        }
        func_0047FCB8(o);
        func_004AEB30((char *)o + 0x1990);
    }
}
