/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Anim { float limit; float speed; float accum; int done; };
/* Advances a fractional counter; returns 1 when the integer part changed. */
extern "C" int func_004C8008(Anim *a, int *pos) {
    int moved = 0;
    if (a->done == 0) {
        float old = a->accum;
        float next = old + a->speed;
        int whole = (int)next;
        a->accum = next;
        if (whole != (int)old) {
            moved = 1;
            *pos += whole;
            a->accum = a->accum - (float)whole;
            float s = a->speed;
            int limit = (int)a->limit;
            if ((s > 0.0f && *pos >= limit) || (s < 0.0f && *pos <= limit)) {
                a->speed = 0.0f;
                *pos = limit;
                a->done = 1;
            }
        }
    }
    return moved;
}
