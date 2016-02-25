/*************************************************************************
	> File Name: TestStackIfIntegers.java
	> Author: 
	> Mail: 
	> Created Time: Mon 22 Feb 2016 03:03:02 PM CST
 ************************************************************************/

public class TestStackIfIntegers {
    public static void main(String[] args) {
        StackOfIntegers stack = new StackOfIntegers();

        for (int i = 0; i < 10; i++) {
            stack.push(i);
        }

        while (!stack.empty()) {
            System.out.print(stack.pop() + " ");
        }

        System.out.println();
    }
}
