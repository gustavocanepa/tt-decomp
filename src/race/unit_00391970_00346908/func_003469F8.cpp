struct Pair { float a, b; };
struct Item { char pad[0x2C]; };
extern Item D_00583F38[3];
extern int D_00583FBC;
extern Pair D_005F3EF8[][3];
extern "C" int func_0042DC88(void);
extern "C" void func_0034F4F0(Item *, int, float, float);

extern "C" void func_003469F8(void)
{
    int n = func_0042DC88();
    for (int i = 0; i < 3; i++)
        func_0034F4F0(&D_00583F38[i], 1, D_005F3EF8[n][i].a, D_005F3EF8[n][i].b);
    D_00583FBC = n;
}
