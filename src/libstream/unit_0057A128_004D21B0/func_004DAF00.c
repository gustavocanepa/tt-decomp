/* compiler: ee-gcc2.9-991111 */
struct Time { unsigned char h, d, min; };
void func_004DAC78(struct Time *);
void func_004DAEA8(struct Time *);
void func_004DAED8(struct Time *);
void func_004DACE0(struct Time *);

void func_004DAF00(struct Time *t, int d)
{
    int m;
    func_004DAC78(t);
    m = t->min + d;
    if (m >= 0) {
        while (m >= 60) {
            func_004DAEA8(t);
            m -= 60;
        }
    } else {
        while (m < 0) {
            m += 60;
            func_004DAED8(t);
        }
    }
    t->min = m;
    func_004DACE0(t);
}
