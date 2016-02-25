/*************************************************************************
	> File Name: ComparableRectangle.java
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Feb 2016 03:51:11 PM CST
 ************************************************************************/

public class ComparableRectangle extends Rectangle 
    implements Comparable<ComparableRectangle> {
    public ComparableRectangle(double width, double height) {
        super(width, height);
    }

    @Override
    public int compareTo(ComparableRectangle o) {
        if (getArea() > o.getArea()) {
            return 1;
        } else if (getArea() < o.getArea()) {
            return -1;
        } else {
            return 0;
        }
    }

    @Override
    public String toString() {
        return super.toString() + " Area: " + getArea();
    }
}
