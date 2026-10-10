struct Mat {
    char pad[0x20];
    float w;
};

extern "C" void func_00454210(Mat *out, int row, Mat *a, Mat *b);

extern "C" void func_004545C0(Mat *out, Mat *a, Mat *b) {
    func_00454210(out, 0, a, b);
    func_00454210(out, 1, a, b);
    out->w = a->w + b->w;
}
