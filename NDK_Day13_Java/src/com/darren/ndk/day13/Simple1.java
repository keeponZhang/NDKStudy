package com.darren.ndk.day13;

import java.util.UUID;

public class Simple1 {

	public static void main(String[] args) {
		// callStaticMethod();
		
		Point point = createPoint();
		
		System.out.println("point: x = "+point.getX()+" , y = "+point.getY());
		
		// android �÷��� ��jni ��������ֵ�������ԭ��
	}

	private native static Point createPoint();

	private native static void callStaticMethod();

	// С��˼������̬��ȡ uuid �ķ�����Ȼ���� c �������������ȡuuid
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
