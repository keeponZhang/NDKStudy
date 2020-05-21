#include <jni.h>
#include <string>
#include <android/log.h>
#include "md5.h"

// 额外附加的字符串
static char *EXTRA_SIGNATURE = "DARREN";
// 校验签名
static int is_verify = 0;
static char *PACKAGE_NAME = "com.darren.ndk.day01";
static char *APP_SIGNATURE = "308201dd30820146020101300d06092a864886f70d010105050030373116301406035504030c0d416e64726f69642044656275673110300e060355040a0c07416e64726f6964310b3009060355040613025553301e170d3137303332303035313232375a170d3437303331333035313232375a30373116301406035504030c0d416e64726f69642044656275673110300e060355040a0c07416e64726f6964310b300906035504061302555330819f300d06092a864886f70d010101050003818d003081890281810086b740fcbbfcc9eda5ec12cd85f427d7912bdb9a9c19f1bef22311969b2b4a1f4110c96574cca48707cf5104c28f539a68a5d22bf107d6500e998fdc3d18281b15e8c07d5d39c3dd85f70fc4fbd4c61d8e2eb205e530e66b3c5023a7e9e6441994dfb609dbaedba2348ecc33ad5e24137a41dfa3488e09c719491a4e041032b10203010001300d06092a864886f70d01010505000381810033174c069272fbc9872261b35c767ac465ead2cf66cf61cb15734e55f565de51bfedc819ce1deb46f4d2c49fa1d735b1ea0c94319d54777458a42c514c12e7a8b75bf9735393c68192b425ec9fcc0ace035a54ca5ce7fd7c5825949df44f29ef87f4b6731724bd19467c8b4243d37e862851ac86554d4fc3b9680a54ab5ebf8d";

using namespace std;

extern "C" {
JNIEXPORT jstring JNICALL
Java_com_darren_ndk_day01_SignatureUtils_signatureParams(JNIEnv *env, jclass type,
                                                         jstring params_);

JNIEXPORT void JNICALL
Java_com_darren_ndk_day01_SignatureUtils_signatureVerify(JNIEnv *env, jclass type,
                                                         jobject context);
}

JNIEXPORT jstring JNICALL
Java_com_darren_ndk_day01_SignatureUtils_signatureParams(JNIEnv *env, jclass type,
                                                         jstring params_) {

    if (is_verify == 0) {
        return env->NewStringUTF("error_signature");
    }

    const char *params = env->GetStringUTFChars(params_, 0);

    // MD5 签名规则，加点料
    // 1. 字符串前面加点料
    string signature_str(params);
    signature_str.insert(0, EXTRA_SIGNATURE);
    // 2. 后面去掉两位
    signature_str = signature_str.substr(0, signature_str.length() - 2);

    // 3. md5 去加密 C++ 和 Java 是一样的，唯一不同就是需要自己回收内存
    MD5_CTX *ctx = new MD5_CTX();
    MD5Init(ctx);
    MD5Update(ctx, (unsigned char *) signature_str.c_str(), signature_str.length());
    unsigned char digest[16] = {0};
    MD5Final(digest, ctx);

    // 生成 32 位的字符串
    char md5_str[32];
    for (int i = 0; i < 16; i++) {
        // 不足的情况下补0 f = 0f, ab = ab
        sprintf(md5_str, "%s%02x", md5_str, digest[i]);
    }

    // 释放资源
    env->ReleaseStringUTFChars(params_, params);
    return env->NewStringUTF(md5_str);
}

//extern "C"
/**
PackageInfo packageInfo = context.getPackageManager().getPackageInfo(context.getPackageName(), PackageManager.GET_SIGNATURES);
Signature[] signatures = packageInfo.signatures;
return signatures[0].toCharsString();
 */
// C 调用 Java 代码 JNI 基础
JNIEXPORT void JNICALL
Java_com_darren_ndk_day01_SignatureUtils_signatureVerify(JNIEnv *env, jclass type,
                                                         jobject context) {
    // 1. 获取包名
    jclass j_clz = env->GetObjectClass(context);
    jmethodID j_mid = env->GetMethodID(j_clz, "getPackageName", "()Ljava/lang/String;");
    jstring j_package_name = (jstring) env->CallObjectMethod(context, j_mid);
    // 2 . 比对包名是否一样
    const char *c_package_name = env->GetStringUTFChars(j_package_name, NULL);
    if (strcmp(c_package_name, PACKAGE_NAME) != 0) {
        return;
    }
    // 3. 获取签名
    // 3.1 获取 PackageManager
    j_mid = env->GetMethodID(j_clz,"getPackageManager","()Landroid/content/pm/PackageManager;");
    jobject pack_manager = env->CallObjectMethod(context,j_mid);
    // 3.2 获取 PackageInfo
    j_clz = env->GetObjectClass(pack_manager);
    j_mid = env->GetMethodID(j_clz,"getPackageInfo","(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");
    jobject package_info = env->CallObjectMethod(pack_manager,j_mid,j_package_name,0x00000040);
    // 3.3 获取 signatures 数组
    j_clz = env->GetObjectClass(package_info);
    jfieldID j_fid = env->GetFieldID(j_clz,"signatures","[Landroid/content/pm/Signature;");
    jobjectArray signatures = (jobjectArray) env->GetObjectField(package_info, j_fid);
    // 3.4 获取 signatures[0]
    jobject signatures_first = env->GetObjectArrayElement(signatures,0);
    // 3.5 调用 signatures[0].toCharsString();
    j_clz = env->GetObjectClass(signatures_first);
    j_mid = env->GetMethodID(j_clz,"toCharsString","()Ljava/lang/String;");
    jstring j_signature_str = (jstring) env->CallObjectMethod(signatures_first, j_mid);
    const char * c_signature_str = env->GetStringUTFChars(j_signature_str,NULL);
    // 4. 比对签名是否一样
    if (strcmp(c_signature_str, APP_SIGNATURE) != 0) {
        return;
    }
    __android_log_print(ANDROID_LOG_ERROR,"JNI_TAG","签名校验成功: %s",c_signature_str);
    // 签名认证成功
    is_verify = 1;
}