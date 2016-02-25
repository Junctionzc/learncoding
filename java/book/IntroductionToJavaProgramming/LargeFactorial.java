/*************************************************************************
	> File Name: LargeFactorial.java
	> Author: 
	> Mail: 
	> Created Time: Mon 22 Feb 2016 04:03:27 PM CST
 ************************************************************************/

import java.math.*;

public class LargeFactorial {
    public static void main(String[] args) {
        System.out.println("50! is \n" + factorial(50));
    }

    public static BigInteger factorial(long n) {
        BigInteger result = BigInteger.ONE;
        for (int i = 1;  i <= n; i++) {
            result = result.multiply(new BigInteger(i + ""));
        }

        return result;
    }
}

