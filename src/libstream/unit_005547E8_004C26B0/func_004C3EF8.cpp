struct Elem {
    char data[0x60];
    Elem() __asm__("func_004C35F8");
};

struct ElemArray {
    Elem elems[24];
    ElemArray() __asm__("func_004C3EF8");
};

ElemArray::ElemArray() {
}
