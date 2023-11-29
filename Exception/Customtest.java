package Exception;

import java.util.Scanner;

public class Customtest {
    public static void main(String[] args) {
        System.out.println("Enter your lover name :");
        Scanner sc = new Scanner(System.in);
        try{
            checkname(sc.nextLine());
        }
        catch (Myexception e){
            System.out.println(e);
        }
    }
    public static void checkname(String str)throws Myexception{
        if(str.equalsIgnoreCase("raimee") ){
            System.out.println("Congrats.");

        }
        else {
            throw new Myexception("\n"+"Wrong Name.");
        }
    }
}
