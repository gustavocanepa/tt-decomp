typedef float f32;

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern Vec3 D_00582AB8;

extern "C" void func_002E0C38(Vec3 *arg0) {
    D_00582AB8.x = arg0->x;
    D_00582AB8.y = arg0->y;
    D_00582AB8.z = arg0->z;
}
