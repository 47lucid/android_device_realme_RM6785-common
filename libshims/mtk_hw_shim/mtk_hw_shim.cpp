#include <dlfcn.h>
#include <stdint.h>
#include <stddef.h>

namespace android {
    struct Rect { int32_t left, top, right, bottom; };
    struct native_handle;
}

extern "C" {
    // ---------------------------------------------------------
    // GraphicBufferMapper Shims
    // ---------------------------------------------------------
    __attribute__((visibility("default")))
    int _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPvPiS9_(
            void* mapper_this, 
            const android::native_handle* handle, 
            unsigned int usage, 
            const android::Rect& bounds, 
            void** vaddr, 
            int* outBytesPerPixel, 
            int* outBytesPerStride) {
        
        static void* libui = dlopen("libui.so", RTLD_NOW);
        static void* sym = dlsym(libui, "_ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv");
        
        int err = -1;
        if (sym) {
            typedef int (*LockFunc)(void*, const android::native_handle*, unsigned int, const android::Rect&, void**);
            LockFunc lock_func = (LockFunc)sym;
            err = lock_func(mapper_this, handle, usage, bounds, vaddr);
        }
        
        if (outBytesPerPixel) *outBytesPerPixel = 0;
        if (outBytesPerStride) *outBytesPerStride = 0;
        
        return err;
    }

    __attribute__((visibility("default")))
    int _ZN7android19GraphicBufferMapper6unlockEPK13native_handle(
            void* mapper_this,
            const android::native_handle* handle) {
        
        static void* libui = dlopen("libui.so", RTLD_NOW);
        static void* sym = dlsym(libui, "_ZN7android19GraphicBufferMapper6unlockEPK13native_handlePNS_4base14unique_fd_implINS4_13DefaultCloserEEE");
        
        if (sym) {
            typedef int (*UnlockFunc)(void*, const android::native_handle*, void*);
            UnlockFunc unlock_func = (UnlockFunc)sym;
            return unlock_func(mapper_this, handle, nullptr);
        }
        
        return -1;
    }

    // ---------------------------------------------------------
    // IMS / Stagefright Shims
    // ---------------------------------------------------------
    __attribute__((visibility("default")))
    void _ZN7android24MakeAVCCodecSpecificDataEPKcPiS2_S2_S2_S2_S2_(
        void* data, int* size, void* a, void* b, void* c, void* d, void* e) {
    }

    __attribute__((visibility("default")))
    void _ZN7android25MakeHEVCCodecSpecificDataEPKcPiS2_(
        void* data, int* size, void* a) {
    }

    __attribute__((visibility("default")))
    void* _ZN7android25parseAVCCodecSpecificDataEPKhm(
        void* data, size_t size) {
        return nullptr;
    }
}
