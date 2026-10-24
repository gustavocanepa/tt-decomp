/* compiler: ee-gcc2.96-no-strict-aliasing */
struct PaletteFlowAnimation {
    unsigned char reverse;
    float speed;
    float phase;
    float color[6];
};

float PaletteFlowAnimation__func(float x, float y);

float PaletteFlowAnimation__getColor(struct PaletteFlowAnimation *self, int i, float t)
{
    float x;
    float f;

    if (self->reverse)
        x = t + self->phase;
    else
        x = t - self->phase;
    x = x - (float)(int)x;
    f = PaletteFlowAnimation__func(x, x);
    return f * self->color[i] + (1.0f - f) * self->color[i + 3];
}
