// Apply eight-byte parameter rows to eleven records with a 0x44-byte stride.
// Settings remains opaque: access only the observed vector components and flag.
struct Settings;
struct Geometry { char unknown[0x80]; Settings* settings; };
struct Owner { unsigned int unknown; Geometry* geometry; };
struct Object { char unknown[0x20A20]; Owner* owner; };
extern "C" int func_002F0D10(Object*);
extern "C" int func_002F0D48(Object*);
extern "C" unsigned char D_00582EC0[][8];
inline float& component(Settings* settings,int offset,int field,const int& part) {
    return *(float*)((unsigned)settings + (unsigned)part + (unsigned)(offset + field));
}
extern "C" void SetupEffectParameters(Object* self) {
    Owner* owner = self->owner;
    int i = 0;
    for (int offset = 0; i < 11; offset += 0x44, ++i) {
        int row = i;
        if(func_002F0D10(self) == 2 && i == 4) row = 11;
        if(func_002F0D10(self) == 0 && func_002F0D48(self) == 0 && i == 5) row = 12;
        Settings* settings = owner->geometry->settings;
        unsigned char* values = D_00582EC0[row];
        if(component(settings,offset,0x4d0,12) < 0.01f) component(settings,offset,0x4d0,12) = 1.0f;
        component(settings,offset,0x4e0,0) = values[0] * 0.01f;
        component(settings,offset,0x4e0,4) = values[1] * 0.1f;
        component(settings,offset,0x4e0,8) = values[2] * 0.01f;
        component(settings,offset,0x4e0,12) = values[3];
        component(settings,offset,0x4f0,0) = values[4] * 0.01f;
        component(settings,offset,0x4f0,12) = values[5] * 0.01f;
        component(settings,offset,0x500,0) = values[6] * 0.01f;
        *(unsigned int*)((unsigned)offset + (unsigned)settings + 0x510) = values[7];
    }
}
