/*************************************************************************
	> File Name: WriteData.java
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Feb 2016 08:22:42 PM CST
 ************************************************************************/
import java.io.IOException;

public class WriteData {
    public static void main(String[] args) throws IOException {
        java.io.File file = new java.io.File("scores.txt");
        if (file.exists()) {
            System.out.println("File already exists");
            System.exit(1);
        }

        java.io.PrintWriter output = new java.io.PrintWriter(file);

        output.print("John T Smith ");
        output.println(90);
        output.print("Eric K Jones ");
        output.println(85);

        output.close();
    }
}
