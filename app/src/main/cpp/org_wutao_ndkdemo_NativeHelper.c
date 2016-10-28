//
// Created by 凸显 on 2016/10/28.
//

#include <jni.h>
#include "org_wutao_ndkdemo_NativeHelper.h"
//加载Android 日志
#include <android/log.h>
#include <stdio.h>

JNIEXPORT jstring JNICALL
Java_org_wutao_ndkdemo_NativeHelper_getAppSecret(JNIEnv *env, jclass type) {
    const char *str = "293229439234";
    //生成 java中的字符串对象
    //指针的指针
    // env => JNINativeInterface **   C语言
    jstring ret = (*env)->NewStringUTF(env, str);
    return ret;

}

JNIEXPORT jstring JNICALL
Java_org_wutao_ndkdemo_NativeHelper_getAppKey(JNIEnv *env, jclass type) {
    const char *str = "29322943923499998678678567";
    //生成 java中的字符串对象
    //指针的指针
    // env => JNINativeInterface **   C语言
    jstring ret = (*env)->NewStringUTF(env, str);
    return ret;
}

JNIEXPORT jint JNICALL
Java_org_wutao_ndkdemo_NativeHelper_add(JNIEnv *env, jclass type, jint a, jint b) {

    // TODO
    return a + b;
}

JNIEXPORT void JNICALL
Java_org_wutao_ndkdemo_NativeHelper_sayHello(JNIEnv *env, jclass type, jstring str) {
    //调用Android系统代码
    const char *TAG = "NativeHelper";
    jboolean b = JNI_FALSE;
    const char *text = (*env)->GetStringUTFChars(env, str, &b);
    //打印日志,显示字符串
    __android_log_write(ANDROID_LOG_DEBUG, TAG, text);
    (*env)->ReleaseStringUTFChars(env, str, text);
}

JNIEXPORT jintArray JNICALL
Java_org_wutao_ndkdemo_NativeHelper_convertBitmap(JNIEnv *env, jclass type, jintArray colors_,
                                                  jint w, jint h) {
    jintArray array=NULL;

    jint *colors = (*env)->GetIntArrayElements(env, colors_, NULL);

    //

    jsize size=  (*env)->GetArrayLength(env,colors_);

     array=(*env)->NewIntArray(env,size);

    int i=0;
    for (; i <size ; i++) {
        colors[i] ^= 0x0FFFFFF;
    }
    (*env)->SetIntArrayRegion(env,array,0,size,colors);

    (*env)->ReleaseIntArrayElements(env, colors_, colors, 0);

    return array;
}

