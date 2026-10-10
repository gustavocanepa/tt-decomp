struct Obj {
    int handle;
};

extern "C" void CameraSys__CameraControl__init(Obj *o, int handle, int flags);
extern "C" void func_003A62E0(Obj *o);
extern "C" void func_003A6070(Obj *o);
extern "C" void func_003A64D8(Obj *o);

extern "C" void func_003A5F88(Obj *o, int mode) {
    CameraSys__CameraControl__init(o, o->handle, 0);
    if (o->handle == 0)
        return;
    switch (mode) {
    case 1:
        func_003A62E0(o);
        break;
    case 2:
        func_003A6070(o);
        break;
    default:
        func_003A64D8(o);
        break;
    }
}
