/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Config { char pad[0xac]; unsigned char a,b,c,d; };
struct Out { float a,b,c,d; };
extern Config D_00583868;
extern Out D_00768E20;
extern "C" void func_003A0888() {
    float k = 0x1.999998p-4f;
    int n = D_00583868.a;
    if (n == 0) n = 1;
    float x = (float)n * 0x1.323ffep+13f;
    n = D_00583868.b;
    if (n == 0) n = 1;
    float y = (float)n * k * 100.0f;
    float z = (float)D_00583868.c * 0x1.1c71c6p-2f;
    float w = (float)D_00583868.d * 0x1.47ae14p-7f;
    D_00768E20.c = z;
    D_00768E20.d = w;
    D_00768E20.a = 1.0f / x;
    D_00768E20.b = 1.0f / y;
}
