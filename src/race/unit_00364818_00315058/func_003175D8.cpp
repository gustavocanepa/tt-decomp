extern "C" float func_00317438(float a);
extern "C" float func_003174F8(float a, float b);

extern "C" float func_003175D8(float from, float to, float t)
{
    float a = func_00317438(from);
    float b = func_00317438(to);
    return a + func_003174F8(b, a) * t;
}
