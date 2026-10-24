/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Range { unsigned start, size; };

extern "C" Range *func_004AE568(Range *out, const Range *in, unsigned align) {
    if (align < 2) {
        out->start = in->start;
        out->size = in->size;
    } else {
        unsigned aligned = (in->start + align - 1) / align * align;
        unsigned pad = aligned - in->start;
        unsigned n = in->size >= pad ? in->size - pad : 0;
        out->size = n / align * align;
        out->start = aligned;
    }
    return out;
}
