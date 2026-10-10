struct Vec3 {
    float x, y, z;
};

extern "C" int func_00469340(Vec3 *min, Vec3 *max);

extern "C" bool func_003D1158(float x, float y, float z)
{
    Vec3 min;
    Vec3 max;
    min.x = x - 10.0f;
    min.y = y - 2.0f;
    min.z = z - 10.0f;
    max.x = x + 10.0f;
    max.y = y + 2.0f;
    max.z = z + 10.0f;
    return func_00469340(&min, &max) != 0;
}
