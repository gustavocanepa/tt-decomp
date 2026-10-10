typedef float f32;

/* CameraBase, named after its constructor so that __13func_0044F188 resolves */
struct func_00416E68 {
    func_00416E68();
    virtual ~func_00416E68();
};

/* a camera class with no known name: named after its vtable */
struct D_005D9890 : func_00416E68 {
    char pad[0x4C];
    f32 f50;
    f32 f54;
    D_005D9890();
    virtual ~D_005D9890();
};

D_005D9890::D_005D9890() {
    f50 = 15.0f;
    f54 = 0x1.999998p-1f;
}
