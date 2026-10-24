/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004A6328(float *, float *, float);
struct Vec3 {
    float x, y, z;
    float &operator[](const int &i) { return (&x)[i]; }
    const float &operator[](const int &i) const { return (&x)[i]; }
};
struct Quat {
    float x, y, z, w;
    float &operator[](const int &i) { return (&x)[i]; }
    const float &operator[](const int &i) const { return (&x)[i]; }
    Quat &operator*=(float f) { (*this)[0] *= f; (*this)[1] *= f; (*this)[2] *= f; (*this)[3] *= f; return *this; }
    void Scale(float f) { x *= f; y *= f; z *= f; w *= f; } void ScaleR(float f) { w *= f; z *= f; y *= f; x *= f; }
    Quat &operator+=(const Quat &o) { x = (*this)[0] + o[0]; y = (*this)[1] + o[1]; z = (*this)[2] + o[2]; w = (*this)[3] + o[3]; return *this; }
};
extern "C" void func_00451580(Quat *q, const Vec3 *a, float ang)
{
    float s, c;
    func_004A6328(&s, &c, ang * 0.5f);
    Quat t;
    Quat &r = *q;
    const Vec3 &v = *a;
    t[0] = r[3] * v[0] - r[1] * v[2] + r[2] * v[1];
    t[1] = r[3] * v[1] + r[0] * v[2] - r[2] * v[0];
    t[2] = -r[0] * v[1] + r[1] * v[0] + r[3] * v[2];
    t[3] = -r[0] * v[0] - r[1] * v[1] - r[2] * v[2];
    t *= s;
    r.Scale(c);
    r += t;
}
