/* libio (GNU iostream library, gcc 2000-10-03 snapshot): istream::operator>>.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
/* libio iostream.cc istream::operator>>(unsigned short&): read_int, negate, truncate. */
struct istream;
extern "C" int func_004E2D08(istream *s, long long *val, int *neg); /* read_int */

extern "C" istream *func_004E3018(istream *s, unsigned short *i)
{
    long long val;
    int neg;
    if (func_004E2D08(s, &val, &neg)) {
        if (neg)
            val = -val;
        *i = (unsigned short)val;
    }
    return s;
}
