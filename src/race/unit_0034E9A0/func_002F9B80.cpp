extern "C" void func_002F9A58(void *, float);
extern "C" float func_002F9A78(void *);
extern "C" void func_002F9B38(void *, float);
extern float D_0076739C;

extern "C" float func_002F9B80(void *self, float v) {
    float out = func_002F9A78(self);
    func_002F9B38(self, v);
    float sum = out + v;
    float lim = D_0076739C;
    if (lim < sum) {
        v -= sum - lim;
        out = lim;
    } else {
        out = sum;
    }
    func_002F9A58(self, out);
    return v;
}
