extern float D_00769D68;
extern float D_00769D6C;
extern float D_00769D70;
extern float D_00769D74;

extern "C" void func_00426400(float t)
{
    D_00769D68 = t * 0.0f + 0.5f;
    D_00769D6C = t * 0.0f + 0.05f;
    D_00769D70 = 10.0f - t * 7.0f;
    D_00769D74 = t * 0.2f + 0.5f;
}
