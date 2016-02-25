/*************************************************************************
	> File Name: PolymorphismDemo.java
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Feb 2016 10:29:00 AM CST
 ************************************************************************/

public class PolymorphismDemo {
    public static void main(String[] args) {
        displayObject(new CircleFromSimpleGeometricObject
            (1, "red", false));
        displayObject(new RectangleFromSimpleGeometricObject
            (1, 1, "black", true));
    }

    public static void displayObject(SimpleGeometricObject object) {
        System.out.println("Created on " + object.getDateCreated() +
            ". Color is " + object.getColor());
    }
}
