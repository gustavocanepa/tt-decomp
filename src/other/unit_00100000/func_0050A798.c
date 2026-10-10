/* libgcc fp-bit.c __addsf3 (single precision): unpack both operands, _fpadd_parts, pack */
typedef float FLO_type;
typedef unsigned int fractype;

typedef enum {
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} fp_class_type;

typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union {
        fractype ll;
    } fraction;
} fp_number_type;

typedef union {
    FLO_type value;
    fractype value_raw;
} FLO_union_type;

extern void func_0050A538(FLO_union_type *src, fp_number_type *dst); /* unpack_d */
extern fp_number_type *func_0050A598(fp_number_type *a, fp_number_type *b, fp_number_type *tmp); /* _fpadd_parts */
extern FLO_type func_0050A480(fp_number_type *src); /* pack_d */

FLO_type func_0050A798(FLO_type arg_a, FLO_type arg_b) {
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    fp_number_type *res;
    FLO_union_type au, bu;

    au.value = arg_a;
    bu.value = arg_b;

    func_0050A538(&au, &a);
    func_0050A538(&bu, &b);

    res = func_0050A598(&a, &b, &tmp);

    return func_0050A480(res);
}
