/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00475440(void *);
extern "C" void func_00468A90(float a, float b, float c, float x, float y, float z) {
    a *= x;
    b *= y;
    c *= z;
    a += b;
    a += c;
    a += a;
    float m[16];
    m[0] = 1.0f - (x+x)*x;
    m[1] = (x*-2.0f)*y;
    m[2] = (x*-2.0f)*z;
    m[3] = 0;
    m[4] = (y*-2.0f)*x;
    m[5] = 1.0f - (y+y)*y;
    m[6] = (y*-2.0f)*z;
    m[7] = 0;
    m[8] = (z*-2.0f)*x;
    m[9] = (z*-2.0f)*y;
    m[10] = 1.0f - (z+z)*z;
    m[11] = 0;
    m[12] = a*x;
    m[13] = a*y;
    m[14] = a*z;
    m[15] = 1;
    func_00475440(m);
}
