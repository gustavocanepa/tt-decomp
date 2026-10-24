/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Boost { char pad[0xc]; float c; float lo; float hi; };
struct Car { char pad[0x4D1]; unsigned char flags; };
extern "C" float func_0030D118(Boost *self, Car *car, int n, float x) {
    float result;
    if (car->flags & 0x10) result = 1.0f;
    else if (n > 0 || self->hi <= x) result = self->c + 1.0f;
    else if (self->lo < x) {
        float ratio = (x - self->lo) / (self->hi - self->lo);
        result = self->c * ratio + 1.0f;
    } else result = 1.0f;
    return result;
}
