struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

struct Canvas {
    char pad0[0x14];
    int ready;
};

extern "C" void func_0043A180(Canvas *c);
extern "C" void func_00474E90(Vec3 *a, Vec3 *b);

extern "C" void func_004399D0(Canvas *c, Vec2 *p0, Vec2 *p1)
{
    if (c->ready == 0)
        func_0043A180(c);
    Vec3 a;
    Vec3 b;
    a.x = p0->x;
    a.y = p0->y;
    a.z = 0.0f;
    b.x = p1->x;
    b.y = p1->y;
    b.z = 0.0f;
    func_00474E90(&a, &b);
}
