#include <jni.h>
#include <string>


//JNIEXPORT jstring JNICALL
//Java_org_wutao_ndkdemo_NativeHelper_getAppKey(JNIEnv *env, jclass type) {
//
//    // TODO
//
//
//    return env->NewStringUTF(returnValue);
//}

extern "C"
jstring
Java_org_wutao_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++  wutao";
    return env->NewStringUTF(hello.c_str());
}
