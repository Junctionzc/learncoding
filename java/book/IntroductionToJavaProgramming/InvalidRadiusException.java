/*************************************************************************
	> File Name: InvalidRadiusException.java
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Feb 2016 05:26:37 PM CST
 ************************************************************************/

public class InvalidRadiusException extends Exception {
    private double radius;

    public InvalidRadiusException(double radius) {
        super("Invalid radius " + radius);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }
}
