package com.darren.ndk.day13;

import java.util.UUID;

public class Simple1 {

	public static void main(String[] args) {
		// callStaticMethod();
		
		Point point = createPoint();
		
		System.out.println("point: x = "+point.getX()+" , y = "+point.getY());
		
		// android 用反射 ，jni 设置属性值，反射的原理？
	}

	private native static Point createPoint();

	private native static void callStaticMethod();

	// 小的思考：静态获取 uuid 的方法，然后再 c 调用这个方法获取uuid
	public static String getUUID() {
		return UUID.randomUUID().toString();
	}
	
	public static Point test(int x,float y){
		return null;
	}
	
	static{
		System.load("C:/Users/hcDarren/Desktop/android/NDK/NDK_Day13/x64/Debug/NDK_Day13.dll");
	}

}
