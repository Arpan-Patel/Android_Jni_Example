/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>

/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */
JNIEXPORT jintArray JNICALL
Java_com_example_hellojni_HelloJni_getElementsFromDLL( JNIEnv* env,
		jobject thiz, jint freq, jint size, jintArray regVals)
{
	jintArray rValues;
	int i = 0;
	jint *values;

	values = (*env)->GetIntArrayElements(env, regVals, 0);
	//jint *a = (*env)->GetIntArrayElements(env, a_bitmap, 0);

	for (i = 0; i < size; i++) {
		values[i] -= freq;
	}

    rValues = (*env)->NewIntArray(env, size);
	(*env)->SetIntArrayRegion(env, rValues, 0, size, values);

    return rValues;
}
