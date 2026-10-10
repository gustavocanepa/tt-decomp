struct Mat3 {
    float m[9];
};

extern "C" void func_00454290(Mat3 *r, int row, const Mat3 *a, const Mat3 *b);

extern "C" void func_004546A0(Mat3 *r, const Mat3 *a, const Mat3 *b)
{
    func_00454290(r, 0, a, b);
    func_00454290(r, 1, a, b);
    r->m[8] = a->m[8] * b->m[8];
}
