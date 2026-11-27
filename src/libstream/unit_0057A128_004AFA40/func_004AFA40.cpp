extern "C" void func_004AFA40(float *arg0, float *arg1, float *arg2, float fparg0, float fparg1, float fparg2) {
    float var_f0;
    float var_f1;

    if (fparg1 < fparg0) {
        var_f1 = fparg2;
        if (fparg2 < fparg0) {
            var_f1 = fparg0;
        }
    } else {
        var_f1 = fparg1;
        if (!(fparg2 < fparg1)) {
            var_f1 = fparg2;
        }
    }
    if (fparg0 < fparg1) {
        var_f0 = fparg2;
        if (fparg0 < fparg2) {
            var_f0 = fparg0;
        }
    } else {
        var_f0 = fparg1;
        if (!(fparg1 < fparg2)) {
            var_f0 = fparg2;
        }
    }
    *arg2 = var_f1;
    float delta = var_f1 - var_f0;
    if (var_f1 != 0.0f) {
        *arg1 = delta / var_f1;
    } else {
        *arg1 = 0.0f;
    }
    *arg0 = 0.0f;
    if (*arg1 != *arg0) {
        if (fparg0 == var_f1) {
            *arg0 = (fparg1 - fparg2) / delta;
        } else if (fparg1 == var_f1) {
            *arg0 = (fparg2 - fparg0) / delta + 2.0f;
        } else if (fparg2 == var_f1) {
            *arg0 = (fparg0 - fparg1) / delta + 4.0f;
        }
        float hue = *arg0 * 60.0f;
        *arg0 = hue;
        if (hue < 0.0f) {
            *arg0 = hue + 360.0f;
        }
    }
}
