package FILE;
import java.util.*;
import java.io.*;
public class srlacc {
private ObjectOutputStream output;
public void openFile(){
    try {
        output = new ObjectOutputStream(new FileOutputStream("testfile.ser"));
    }
    catch (IOException e){
        System.out.println(e);
    }
}
public void addrecord(){
    AccountRecordSerializable acc = new AccountRecordSerializable();
    AccountRecordSerializable record;
    Scanner input = new Scanner(System.in);
    int accountNumber = 0;
    String firstName;
    String lastName;
    double balance;
    System.out.printf("%s\n%s\n%s\n%s\n\n",
            "To terminate input, type the end-of-file indicator ",
            "when you are prompted to enter input.",
            "On UNIX/Linux/Mac OS X type <ctrl> d then press Enter",
            "On Windows type <ctrl> z then press Enter");

    System.out.printf("%s\n%s",
            "Enter account number (> 0), first name, last name and balance.",
            "? ");
    while(input.hasNext()){

    }
}
}

