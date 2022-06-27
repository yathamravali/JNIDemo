#include "Crash.h"
#include "jni.h"
#include <stdio.h>
JNIEXPORT void JNICALL Java_Crash_printHello(JNIEnv *env, jobject obj){
    char *str;
    str = "GfG";
    *(str+1) = 'n';
    return;
}
