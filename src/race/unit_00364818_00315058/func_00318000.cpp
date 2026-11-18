/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { signed char cur,max; };
extern "C" float func_00318000(State *s, int dir, float scale) {
    float result = 0.0f;
    float original = scale;
    if (dir == 0) {
        s->cur = 0;
        return result;
    }
    int old = s->cur;
    int limit = s->max;
    bool advance = old < limit;
    int cur = (signed char)old;
    scale = (float)limit;
    if (advance) {
        int next = cur + 1;
        s->cur = next;
        cur = next;
    }
    result = original * (float)(signed char)cur / scale;
    if (dir < 0) result = -result;
    return result;
}
