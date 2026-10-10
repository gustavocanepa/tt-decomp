struct VEntry { short delta; short index; void *pfn; };
struct hObject { int pad; VEntry *vptr; };

extern "C" char func_0051DB58[];
extern "C" char func_0054D6E8[];
/* __dynamic_cast (old ABI): from, to, require_public, address, sub, subptr */
extern "C" void *GT4MC__FileGT4GameData__loadInstance(void *from, void *to, int require_public, void *address, void *sub, void *subptr);
extern "C" void func_0020AD80(void *self, hObject *obj);

/* The parent's handler, then dynamic_cast<mPhotoRenderFace *>(obj) with the result unused. */
extern "C" void func_0018B570(void *self, hObject *obj)
{
    func_0020AD80(self, obj);
    if (obj)
        GT4MC__FileGT4GameData__loadInstance(obj->vptr[0].pfn, func_0051DB58, 0, (char *)obj + obj->vptr[0].delta, func_0054D6E8, obj);
}
