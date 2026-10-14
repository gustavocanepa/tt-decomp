/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void ModelSet2__begin(void *, void *);
extern "C" void ModelSet2__end(void *);
extern "C" void ModelSet2__render(void *, void *);
extern "C" void ModelSet2___render(void *, int, void *);
extern "C" int func_0034D008(void *, void *model, const unsigned short *list) {
    if (model) {
        if (list) {
            ModelSet2__begin(model, 0);
            int n = *list++;
            for (int i = 0; i < n; i++) {
                ModelSet2___render(model, *list++, 0);
            }
            ModelSet2__end(model);
        } else {
            ModelSet2__render(model, 0);
        }
    }
}
