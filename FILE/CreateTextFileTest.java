package FILE;

public class CreateTextFileTest {
    public static void main(String[] args) {
        CTF application=new CTF();
        application.openFile("C:\\Users\\Munim\\IdeaProjects\\Sem3\\src\\FILE\\emni.txt");
        application.addrecords();
        application.closefile();
    }
}