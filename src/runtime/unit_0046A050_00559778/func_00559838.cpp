extern "C" int func_00559838(int lo, int hi, const float *keys, float t)
{
    while (hi - lo > 4) {
        int mid = ((lo + hi) >> 1) & ~3;
        if (t < keys[mid])
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}
