/*************************************************************************
	> File Name: WriteDataWithAutoClose.java
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Feb 2016 08:27:51 AM CST
 ************************************************************************/

public class WriteDataWithAutoClose {
    public static void main(String[] args) throws Exception {
        java.io.File file = new java.io.File("scores.txt");
        if (file.exists()) {
            System.out.println("File already exists");
            System.exit(0);
        }

        try (
            java.io.PrintWriter output = new java.io.PrintWriter(file);
        ) {
            output.print("John T Smith ");
            output.println(90);
            output.print("Eric K JOhn");
            output.println(85);
        }
    }
}

