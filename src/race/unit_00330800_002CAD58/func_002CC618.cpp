/* compiler: ee-gcc2.96-nsa-nosib */
struct Obj { char pad[0x218]; int mode; };
extern "C" void func_00104C88(void *);
extern "C" void func_00104D10(void *);
extern "C" void func_00477DC0(int);
extern "C" int func_00475B38(float, float, float, float, float, float, float);
extern "C" void func_002CC618(Obj *o, void *p) {
    if (o->mode != 0) {
        func_00104C88(p);
        func_00104D10(p);
        func_00477DC0(0x808080);
        switch(o->mode) {
        case 2:
            func_00475B38(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 255.0f);
            break;
        case 4:
            func_00475B38(1.5f, 0.95f, 0.6f, 0.0f, 1.0f, 0.3f, 255.0f);
            break;
        }
    }
}
