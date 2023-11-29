package FILE;
import java.io.*;
public class demo {
    private String path ="C:\\Users\\Munim\\IdeaProjects\\Sem3\\src\\FILE\\emni.txt";
    public demo(){
        File file = new File(path);
        System.out.print("Exist? ");
        System.out.println(file.exists()?"YES":"NO");
        System.out.println("Name: "+file.getName());
        System.out.println(file.isFile()?"is a File":"not a file");
        System.out.println(file.isDirectory()?"is a directory":"not a directory");
        System.out.println("Absolute path: "+file.getAbsolutePath());
        System.out.println(file.isAbsolute()?"YEs aboslute path":"Not a absolute path");
//        System.out.println("Content of the directory: \n"+file.list());
        String lisst[] = file.list();
        for(String element : lisst) System.out.println(element);
    }

    public static void main(String[] args) {
        new demo();
    }
}
