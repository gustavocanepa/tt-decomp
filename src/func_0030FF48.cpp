typedef float f32;

extern "C" f32 func_0030FF48(f32 x) {
    if (x < 400.0f)
        return 349.85992431640625f;
    if (x < 1040.0f)
        return 349.85992431640625f - (x - 400.0f) * 0.07212182168960571f;
    if (x < 5600.0f)
        return 315844.125f / x;
    if (x < 6000.0f)
        return (6000.0f - x) / 400.0f * 56.40073394775391f;
    return 0.0f;
}
