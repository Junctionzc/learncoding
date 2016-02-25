/*************************************************************************
	> File Name: ChainedExceptionDemo.java
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Feb 2016 05:19:32 PM CST
 ************************************************************************/

public class ChainedExceptionDemo {
    public static void main(String[] args) {
        try {
            method1();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public static void method1() throws Exception {
        try {
            method2();
        } catch (Exception ex) {
            throw new Exception("New info from method1", ex);
        }
    }

    public static void method2() throws Exception {
        throw new Exception("New info from method2");
    }
}
