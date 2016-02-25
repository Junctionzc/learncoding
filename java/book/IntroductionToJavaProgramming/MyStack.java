/*************************************************************************
	> File Name: MyStack.java
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Feb 2016 01:52:00 PM CST
 ************************************************************************/
import java.util.ArrayList;

public class MyStack {
    private ArrayList<object> list = new ArrayList<>();

    public boolean isEmpty() {
        return list.isEmpty();
    }

    public int getSize() {
        return list.size();
    }

    public Object peek() {
        return list.get(getSize() - 1);
    }

    public Object pop() {
        Object o = list.get(getSize() - 1);
        list.remove(getSize() - 1);
        return o;
    }

    public void push(Object o) {
        list.add(o);
    }

    @Override
    public String toString() {
        return "stack: " + list.toString();
    }
}

