//
// Created by 凸显 on 2016/10/28.
//

#ifndef NDKDEMO_ORG_WUTAO_NDKDEMO_NATIVEHELPER_H
#define NDKDEMO_ORG_WUTAO_NDKDEMO_NATIVEHELPER_H

#include <jni.h>

#endif //NDKDEMO_ORG_WUTAO_NDKDEMO_NATIVEHELPER_H

//声明两个方法，这些方法需要在 .c 的文件中实现
//*
// * 获取AppKey


JNIEXPORT jstring JNICALL
        Java_org_wutao_ndkdemo_NativeHelper_getAppSecret(JNIEnv *env, jclass type);

JNIEXPORT jstring JNICALL
        Java_org_wutao_ndkdemo_NativeHelper_getAppKey(JNIEnv *env, jclass type);


JNIEXPORT jint JNICALL
Java_org_wutao_ndkdemo_NativeHelper_add(JNIEnv *env, jclass type, jint a, jint b);

//JNIEXPORT
//JNICALL
JNIEXPORT void JNICALL
        Java_org_wutao_ndkdemo_NativeHelper_sayHello(JNIEnv *env,jclass type,jstring str);

