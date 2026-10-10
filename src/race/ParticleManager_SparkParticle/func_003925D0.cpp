struct Vec3 { float x, y, z; };
extern "C" void func_00474E90(Vec3 *a, Vec3 *b);

extern "C" void func_003925D0(Vec3 *a, Vec3 *b)
{
    int behind_a = a->z < -0.1f;
    int behind_b = b->z < -0.1f;
    if (behind_a && behind_b)
        return func_00474E90(a, b);
}
