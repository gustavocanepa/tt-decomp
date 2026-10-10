/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

/* hObject; its constructor is func_002A7618. The vptr follows its first word. */
struct func_002A7618 {
    s32 m0;
    func_002A7618();
    virtual ~func_002A7618();
};

struct Mat33 {
    float m[3][3];
    Mat33() {
        m[0][0] = 1.0f; m[1][0] = 0.0f; m[2][0] = 0.0f;
        m[0][1] = 0.0f; m[1][1] = 1.0f; m[2][1] = 0.0f;
        m[0][2] = 0.0f; m[1][2] = 0.0f; m[2][2] = 1.0f;
    }
};

struct mTransform : func_002A7618 {
    s32 m8, mC;
    Mat33 mat;
    mTransform();
    virtual ~mTransform();
};

mTransform::mTransform() {
}
