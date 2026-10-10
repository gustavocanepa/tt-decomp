extern "C" float func_004A5DE0(float);

struct Camera {
    char pad0[0xC];
    float fov;
};

extern "C" void func_00321AF8(Camera *self, float x, float y, float z);

extern "C" void func_00322D80(Camera *self)
{
    float t = func_004A5DE0(self->fov * 0.5f * 0.017453292f);
    func_00321AF8(self, 1.0f, 1.0f, 1.0f / t);
}
