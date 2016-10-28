package org.wutao.ndkdemo;

/**
 * Created by 凸显 on 2016/10/28.
 */

public class NativeHelper {

    static {
        System.loadLibrary("native-lib");
    }

    public static String getAppKeyFromC(){
        return getAppKey();
    }

    public static  String getAppSecretFromC(){
        return getAppSecret();
    }
    /**
     * 实现C语言的调用  需要用C语言来实现
     * @return
     */
    private static native String getAppKey();

    /**
     * 调用C语言
     * @return
     */
    private static native String getAppSecret();

    /**
     * java向C传递参数,并且 返回结果
     * @param a
     * @param b
     * @return
     */
    public static native int add(int a,int b);

    /**
     * java向C传递参数  没有返回值
     * @param name
     */
    public static native void sayHello(String name);

    /**
     * 转换bitmap颜色
     * @param colors
     * @param w
     * @param h
     */
    public static native int [] convertBitmap(int [] colors,int w, int h);
}
