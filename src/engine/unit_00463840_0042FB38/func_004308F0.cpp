/* compiler: ee-gcc2.96-no-strict-aliasing */
float func_004308F0(float a, float b, float c, float d) {
    float x = a - b;
    if (x < -0x1.638e36p+1f) x = -0x1.638e36p+1f;
    else if (x > 0x1.638e36p+1f) x = 0x1.638e36p+1f;
    x = c + d * x;
    if (x > 1.0f) x = 1.0f;
    else if (x < 0.0f) x = 0.0f;
    return x;
}
