/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_003E6678(void *, float *, float *);
extern "C" float *func_003E5E70(float *, float *);
extern "C" double func_004B4C18(float);
extern "C" void func_004A6448(const char *, ...);
extern char D_005F8C70[];
extern "C" void func_003E1B60(float *o) {
    float pos[4], rot[4], tmp[4];
    func_003E6678(o+4,pos,rot);
    double a = func_004B4C18(o[0]);
    double b = func_004B4C18(o[1]);
    double c = func_004B4C18(o[2]);
    double d = func_004B4C18(pos[0]);
    double e = func_004B4C18(pos[1]);
    double f = func_004B4C18(pos[2]);
    float *p = tmp;
    func_003E5E70(p,rot);
    double g = func_004B4C18(*p);
    func_004A6448(D_005F8C70,a,b,c,d,e,f,g);
}
