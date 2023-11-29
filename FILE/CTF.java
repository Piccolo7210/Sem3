package FILE;

import java.util.*;
import java.io.*;

public class CTF {
    private Formatter output;
    public void openFile(String path){
        try {
            output = new Formatter(path);
        }
        catch(SecurityException e){
            System.out.println("no right to write in this file");
        }
        catch(FileNotFoundException e){
            System.out.println("File not Found and not able to open a file");
        }

        }
    public void addrecords(){
        System.out.println("Add 5 Records");
        System.out.println("Acc No\t: First Name \t: Last Name\t Acc balance");
        Scanner sc = new Scanner(System.in);
        AccountRecord acc = new AccountRecord();
        for(int i=0;i<5;i++){
        acc.setAccount(sc.nextInt());
        acc.setFirstName(sc.next());
        acc.setLastName(sc.next());
        acc.setBalance(sc.nextDouble());
        output.format("%d %s %s %.2f\n",acc.getAccount(),acc.getFirstName(),acc.getLastName(),acc.getBalance());
        System.out.println("Acc No\t: First Name \t: Last Name\t Acc balance");
        }
    }
    public void closefile(){
        if(output!=null){
            output.close();
        }
    }
}
