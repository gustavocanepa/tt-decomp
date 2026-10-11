extern "C" float func_003151F0(float);

extern "C" float func_003152A0(float a, float b)
{
    float d = func_003151F0(a) - func_003151F0(b);
    if (d >= 3.14159274101257324f) d -= 6.28318548202514648f;
    else if (d < -3.14159274101257324f) d += 6.28318548202514648f;
    return d;
}
