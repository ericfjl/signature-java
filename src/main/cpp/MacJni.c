#include <stdio.h>
#include "MacJni.h"

JNIEXPORT void Java_MacJni_sayHello(JNIEnv * env, jobject obj){
    printf("hello from jni");
}
JNIEXPORT jstring JNICALL Java_MacJni_getSign(JNIEnv *, jobject, jstring, jstring){

    //获取jclass
    jclass jclz = env->GetObjectClass(jobj);

    //三个参数：1：对应类的jclass 2：方法名 3：方法签名
    jmethodID jmid = env->GetMethodID(jclz,"Sign","()Ljava/lang/String;");
    //根据返回值，调用相应方法，我这边返回值是int,第三个参数为可变参数，就是调用方法需要传入的参数
    jString sign = env->CallStringMethod(jobj, jmid,500);
}
//JNIEXPORT jString Java_MacJni_getSign(JNIEnv * env, jobject obj){
//    //获取jclass
//    jclass jclz = env->GetObjectClass(jobj);
//
//    //三个参数：1：对应类的jclass 2：方法名 3：方法签名
//    jmethodID jmid = env->GetMethodID(jclz,"Sign","()Ljava/lang/String;");
//    //根据返回值，调用相应方法，我这边返回值是int,第三个参数为可变参数，就是调用方法需要传入的参数
//    jString sign = env->CallStringMethod(jobj, jmid,500);
//}