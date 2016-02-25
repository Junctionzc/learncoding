/*************************************************************************
	> File Name: RectangleFromSimpleGeometricObject.java
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Feb 2016 08:39:56 AM CST
 ************************************************************************/

public class RectangleFromSimpleGeometricObject
    extends SimpleGeometricObject {
    private double width;
    private double height;

    public RectangleFromSimpleGeometricObject() {

    }

    public RectangleFromSimpleGeometricObject(
        double width, double height) {
        this.width = width;
        this.height = height;
    }

    public RectangleFromSimpleGeometricObject(
        double width, double height, String color, boolean filled) {
        this.width = width;
        this.height = height;
        setColor(color);
        setFilled(filled);
    }

    public double getWidth() {
        return width;
    }

    public void setWidth() {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getArea() {
        return width * height;
    }

    public double getPerimeter() {
        return 2 * (width + height);
    }
}
