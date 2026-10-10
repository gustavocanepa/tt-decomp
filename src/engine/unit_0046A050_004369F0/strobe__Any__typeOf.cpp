/* strobe (Flash player) Any::typeOf: the ActionScript type name of a value. */
extern const char D_00601620[]; /* "function" */
extern const char D_00601630[]; /* "null" */
extern const char D_00601638[]; /* "string" */
extern const char D_00601640[]; /* "boolean" */
extern const char D_00601648[]; /* "number" */
extern const char D_00601650[]; /* "object" */
extern const char D_00601658[]; /* "movieclip" */
extern const char D_00601668[]; /* "undefined" */
extern const char D_00601678[]; /* "unknown..." */

struct Any {
    int type;
    int getType() const { return type; }
    /* Separate inline predicates: the range test is not folded into one unsigned compare
       and the first comparison is materialised as a value (slti; xori 1; xori 0; movn). */
    bool isFunctionFirst() const { return getType() >= 13; }
    bool isFunction() const { return isFunctionFirst() && getType() < 28; }
};

extern "C" const char *strobe__Any__typeOf(Any *a) {
    if (a->isFunction())
        return D_00601620;
    switch (a->getType()) {
    case 0: return D_00601630;
    case 3: case 4: return D_00601638;
    case 5: return D_00601640;
    case 6: return D_00601648;
    case 7: case 8: return D_00601650;
    case 10: return D_00601658;
    case 1: return D_00601668;
    default: return D_00601678;
    }
}
