struct Vec2 { float x, y; };
struct Mat { float m[16]; };

struct Node {
    char pad[0x2C];
    char xform[0x2C];
    Node *parent;
};

extern "C" void func_00445118(void *xform, Mat *m);
extern "C" void func_00444ED0(const Mat *m, const Vec2 *in, Vec2 *out);

extern "C" void func_00444920(Node *n, Vec2 *p) {
    Vec2 v = *p;
    Mat m;
    func_00445118(n->xform, &m);
    func_00444ED0(&m, &v, p);
    if (n->parent)
        func_00444920(n->parent, p);
}
