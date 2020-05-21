package com.darren.day15;

import java.util.Collections;

import javax.naming.ldap.SortControl;

public class Simple1 {
	private static String name;// 一大堆变量
	private static String name1;// 一大堆变量
	private static String name3;// 一大堆变量

	static {
		System.load("C:/Users/hcDarren/Desktop/android/NDK/NDK_Day15_VS/x64/Debug/NDK_Day15_VS.dll");
	}

	public Simple1() {

	}

	public static void main(String[] args) {
		// 1. 数组处理的一些细节
		/*
		 * int[] arr = {11,22,-3,2,4,6,-15};
		 * 
		 * 
		 * sort(arr);
		 * 
		 * for (int i = 0; i < arr.length; i++) { System.out.print(arr[i]+"\t");
		 * }
		 * 
		 * // 2. 局部引用和全局引用 // localRef();
		 * 
		 * // saveGlobalRef("Darren");
		 * 
		 * // System.out.println(getGlobalRef());
		 * 
		 * // 合适的时机去释放 // delteGlobalRef();
		 * 
		 * // 再次获取 // System.out.println(getGlobalRef());
		 * 
		 * // 3.缓存策略 static，native层有一大堆方法要去获取 name 属性 // 初始化全局静态缓存
		 * initStaticCache();
		 * 
		 * staticLocalCache("Darren");
		 * 
		 * System.out.println("name = "+name);
		 * 
		 * staticLocalCache("Jack");// not null
		 * 
		 * System.out.println("name = "+name);
		 * 
		 * staticLocalCache("Rose"); // not null System.out.println("name = "
		 * +name);
		 */

		// 异常处理（简单讲，C++异常）

		try {
			exception();
		} catch (NoSuchFieldException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		System.out.println("name3 = " + name3);
	}

	private static final native void exception() throws NoSuchFieldException;

	private static final native void initStaticCache();

	private static final native void staticLocalCache(String name);

	private static final native void delteGlobalRef();

	private static final native String getGlobalRef();

	private static final native void saveGlobalRef(String str);

	private static final native void localRef();

	private static final native void sort(int[] arr);

}
