#include <stdio.h>
#include "great_doctor_sincerity_SignJni.h"


JNIEXPORT jstring JNICALL Java_great_doctor_sincerity_SignJni_getSign(JNIEnv *, jobject, jstring encryptText, jstring encryptKey){

    printf("hello from jni");
    //获取jclass
    jclass jclz = env->GetObjectClass(jobj);

    //三个参数：1：对应类的jclass 2：方法名 3：方法签名
    jmethodID jmid = env->GetMethodID(jclz,"getSign","(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    //根据返回值，调用相应方法，我这边返回值是int,第三个参数为可变参数，就是调用方法需要传入的参数
    string sign = env->CallStringMethod(jobj, jmid,encryptText,encryptKey);
    return env->NewStringUTF(sign.data());

  }