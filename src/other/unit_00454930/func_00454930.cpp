typedef unsigned int u128 __attribute__((mode(TI)));

struct Mat {
    u128 row[3];
};

extern "C" void func_00454970(Mat *self, Mat *m, void *arg);

extern "C" void func_00454930(Mat *self, void *arg) {
    Mat tmp;
    tmp.row[0] = self->row[0];
    tmp.row[1] = self->row[1];
    tmp.row[2] = self->row[2];
    func_00454970(self, &tmp, arg);
}
