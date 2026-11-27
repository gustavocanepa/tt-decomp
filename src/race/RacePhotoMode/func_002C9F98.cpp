/* compiler: ee-gcc2.96-nosib */
struct Cam { char pad[0x327B0]; int mode; };
extern "C" void func_00104C88(void *);
extern "C" void func_00104D10(void *);
extern "C" void func_00477DC0(int);
extern "C" int func_00475B38(float, float, float, float, float, float, float);

extern "C" void func_002C9F98(Cam *o, void *p)
{
    if (o->mode != 0) {
        func_00104C88(p);
        func_00104D10(p);
        func_00477DC0(0x808080);
        int m = o->mode;
        switch (m) {
        case 2:
            func_00475B38(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 255.0f);
            break;
        case 4:
            func_00475B38(1.5f, 0x1.e66666p-1f, 0x1.333332p-1f, 0.0f, 1.0f, 0x1.333332p-2f, 255.0f);
            break;
        }
    }
}
