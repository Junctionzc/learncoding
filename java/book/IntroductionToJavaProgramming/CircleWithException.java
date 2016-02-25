/*************************************************************************
	> File Name: CircleWithException.java
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Feb 2016 04:18:21 PM CST
 ************************************************************************/

public class CircleWithException {
    private double radius;

    private static int numberOfObjects = 0;

    public CircleWithException() {
        this(1.0);
    }

    public CircleWithException(double newRadius) {
        setRadius(newRadius);
        numberOfObjects++;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double newRadius) 
        throws IllegalArgumentException {
        if (newRadius >= 0) {
            radius = newRadius;
        } else {
            throw new IllegalArgumentException(
                "Radius cannot be negative");
        }
    }

    public static int getNumberOfObjects() {
        return numberOfObjects;
    }

    public double findArea() {
        return radius * radius * 3.14159;
    }
}
