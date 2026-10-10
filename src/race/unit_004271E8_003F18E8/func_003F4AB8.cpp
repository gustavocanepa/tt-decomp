struct Loop {
    float end;
    float start;
};

extern "C" int func_003E6F48(float x);

extern "C" float func_003F4AB8(const Loop *l, float t) {
    if (t < 0.0f)
        return 0.0f;
    if (t < l->end)
        return t;
    float start = l->start;
    float len = l->end - start;
    float off = t - start;
    if (len != 0.0f)
        off -= len * (float)func_003E6F48(off / len);
    return off + start;
}
