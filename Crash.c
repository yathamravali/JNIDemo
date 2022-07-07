#include "Crash.h"
#include "jni.h"
#include <stdio.h>
JNIEXPORT void JNICALL Java_Crash_printHello(JNIEnv *env, jobject obj){
	char name=(char*)malloc(8);
	strcpy(name,"Ravali Yatham");
	return;
}
