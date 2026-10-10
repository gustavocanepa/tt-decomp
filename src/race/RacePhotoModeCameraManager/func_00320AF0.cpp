typedef int s32;

extern "C" void CameraSys__CameraControl__init(void *arg0, void *arg1, s32 arg2);

extern "C" void func_00320AF0(void *arg0, void *arg1) {
    CameraSys__CameraControl__init((char *)arg0 + 0xEA8, arg1, 1);
}
