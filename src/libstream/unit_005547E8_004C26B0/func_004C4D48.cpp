struct Elem {
    char data[0x34];
    Elem() __asm__("func_004C47C0");
};

struct ElemArray {
    Elem elems[48];
    ElemArray() __asm__("func_004C4D48");
};

ElemArray::ElemArray() {
}
