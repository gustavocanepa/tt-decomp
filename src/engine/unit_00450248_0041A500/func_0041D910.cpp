extern "C" void func_004755EC(float x, float y, float z);
extern "C" void func_00475758(float a);
extern "C" void func_00475780(float a);

extern "C" void func_0041D910(float *v, int flip)
{
    func_004755EC(v[0], v[1], v[2]);
    func_00475758(v[4]);
    func_00475780(flip ? -v[5] : v[5]);
    func_004755EC(flip ? v[6] * 0.5f : v[6] * -0.5f, 0.0f, 0.0f);
}
