extern "C" int D_00583FD4;
extern "C" int D_00583FD8;
extern "C" void func_00346CF0(float scale, float alpha);

extern "C" void func_00346D88(void)
{
    float scale = 1.0f;
    if (D_00583FD4)
        scale = 0.45f;
    if (D_00583FD8)
        scale = 0.2f;
    func_00346CF0(scale, 1.0f);
}
