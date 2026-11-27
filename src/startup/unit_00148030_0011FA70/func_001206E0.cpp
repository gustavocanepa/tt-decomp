// Native object wrapper: the constructor installs its func_005AE2E8-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_002A7618");virtual ~hObject();int unknown8,unknownC;};
struct mCalendar:hObject {void* const data;mCalendar(void*) __asm__("func_001206E0");virtual ~mCalendar();};
mCalendar::mCalendar(void* value):data(value){}
