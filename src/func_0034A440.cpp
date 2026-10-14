struct S{float low,scale,high;union{int zeroBits;float zeroValue;}zero;float factor,extra;};
struct In{int a0;int a4;int a8;int aC;};

extern "C" void func_0034A260(S* self,float exponent,float factor,float extra,float a,float b);

extern "C" S *func_0034A440(S *arg0, In *arg1) {
    float k = 5500.0f;
    func_0034A260(arg0, (float)arg1->a0 / 10.0f, ((float)arg1->a4 * 3.0f) / 5.0f, ((float)arg1->a8 + 10.0f) / 10.0f, (((float)arg1->aC * 2000.0f) / 10.0f) + k, k);
    return arg0;
}
