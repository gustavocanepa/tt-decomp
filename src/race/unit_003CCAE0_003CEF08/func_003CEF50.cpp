/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_003CEF50(float *box, float *obj) {
    float radius = obj[0];
    float *px = obj + 1;
    float *py = obj + 2;
    float left = box[0];
    float x = *px;
    float lo = left - radius;
    float p[2];
    float right, hi, bottom, y;
    p[0] = x;
    p[1] = *py;
    if (x <= lo) goto fail;
    right = box[2];
    hi = right + radius;
    if (hi <= x) return 0;
    bottom = box[1] - radius;
    y = *(volatile float *)&p[1];
    if (y <= bottom) goto fail;
    if (!(box[3] + radius <= y)) goto success;
fail:
    return 0;
success:
    if (x - left < right - x) p[0] = lo - 0x1.47ae14p-7f;
    else p[0] = hi + 0x1.47ae14p-7f;
    *px = p[0];
    *py = p[1];
    return 1;
}
