extern "C" void func_00552A68(float *a, float *b);

extern "C" void func_00317960(float *arg0, const float *m, const float *v)
{
    float buf[4];
    float x = v[0];
    float y = v[1];
    float z = v[2];
    buf[0] = m[0] * x + m[4] * y + m[8] * z + m[12];
    buf[1] = m[1] * x + m[5] * y + m[9] * z + m[13];
    buf[2] = m[2] * x + m[6] * y + m[10] * z + m[14];
    func_00552A68(buf, arg0);
}
