extern "C" float func_0044D008(float *o0, float *o1, float *o2, float *o3, float *o4, float *o5, float *o6, float *o7, float *o8, float *o9, float *o10, float *o11, float *o12, float *o13, float *o14, float *o15, float a00, float a01, float a02, float a03, float a10, float a11, float a12, float a13, float a20, float a21, float a22, float a23, float a30, float a31, float a32, float a33) {
    float s0 = a00*a11-a10*a01;
    float c5 = a22*a33-a32*a23;
    float s1 = a00*a21-a20*a01;
    float c4 = a12*a33-a32*a13;
    float s2 = a00*a31-a30*a01;
    float c3 = a12*a23-a22*a13;
    float s3 = a10*a21-a20*a11;
    float c2 = a02*a33-a32*a03;
    float s4 = a10*a31-a30*a11;
    float c1 = a02*a23-a22*a03;
    float s5 = a20*a31-a30*a21;
    float c0 = a02*a13-a12*a03;
    float det = s0*c5-s1*c4+s2*c3+s3*c2-s4*c1+s5*c0;
    if (det != 0.0f) {
        float inv = 1.0f/det;
        *o0 = (a11*c5+a31*c3-a21*c4)*inv;
        *o1 = (a21*c2-a31*c1-a01*c5)*inv;
        *o2 = (a01*c4+a31*c0-a11*c2)*inv;
        *o3 = (a11*c1-a21*c0-a01*c3)*inv;
        *o4 = (a20*c4-a10*c5-a30*c3)*inv;
        *o5 = (a00*c5+a30*c1-a20*c2)*inv;
        *o6 = (a10*c2-a30*c0-a00*c4)*inv;
        *o7 = (a00*c3+a20*c0-a10*c1)*inv;
        *o8 = (a13*s5-a23*s4+a33*s3)*inv;
        *o9 = (-a03*s5+a23*s2-a33*s1)*inv;
        *o10 = (a03*s4-a13*s2+a33*s0)*inv;
        *o11 = (a13*s1-a03*s3-a23*s0)*inv;
        *o12 = (-a12*s5+a22*s4-a32*s3)*inv;
        *o13 = (a02*s5-a22*s2+a32*s1)*inv;
        *o14 = (a12*s2-a02*s4-a32*s0)*inv;
        *o15 = (a02*s3-a12*s1+a22*s0)*inv;
    }
    return det;
}
