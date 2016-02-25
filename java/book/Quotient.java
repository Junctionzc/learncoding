/*************************************************************************
	> File Name: Quotient.java
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Feb 2016 02:32:53 PM CST
 ************************************************************************/
import java.util.Scanner;

public class Quotient {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter two integers: ");
        int number1 = input.nextInt();
        int number2 = input.nextInt();

        System.out.println(number1 + " / " + number2 + " is " +
            (number1 / number2));
    } 
}
