struct Canvas;
struct Vec2 { float x, y; };
struct V4 { float a, b, c, d; };

extern "C" void func_004399D0(Canvas *c, Vec2 *p0, Vec2 *p1);

extern "C" void func_004454F8(Canvas *arg0, V4 *arg1) {
    Vec2 t0;
    Vec2 t1;
    Vec2 *p2 = (Vec2 *)((char *)arg1 + 8);

    t0.x = arg1->a;
    t0.y = arg1->d;
    t1.x = p2->x;
    t1.y = arg1->b;

    func_004399D0(arg0, (Vec2 *)arg1, &t0);
    func_004399D0(arg0, &t0, p2);
    func_004399D0(arg0, p2, &t1);
    func_004399D0(arg0, &t1, (Vec2 *)arg1);
}
