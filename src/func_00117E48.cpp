extern "C" float func_00117E48(float fparg0, float fparg1, float fparg2, float fparg3, float fparg4, float fparg5)
{
    float var_f12 = fparg0;
    float var_f13 = fparg1;
    float var_f14 = fparg2;
    float var_f15 = fparg3;

    if (var_f13 < fparg4 || fparg5 < var_f12) {
        return 0.0f;
    }
    if (var_f12 < fparg4 || fparg5 < var_f13) {
        float temp_f4 = 1.0f / (var_f13 - var_f12);
        float temp_f2 = var_f15 - var_f14;
        float temp_f3 = (var_f14 * var_f13) - (var_f15 * var_f12);
        if (var_f12 < fparg4) {
            float t = temp_f2 * fparg4;
            var_f12 = fparg4;
            var_f14 = (t + temp_f3) * temp_f4;
        }
        if (fparg5 < var_f13) {
            float t = temp_f2 * fparg5;
            var_f13 = fparg5;
            var_f15 = (t + temp_f3) * temp_f4;
        }
    }
    return (var_f14 + var_f15) * (var_f13 - var_f12) * 0.5f;
}
