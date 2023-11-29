package FILE;

 import java.io.FileOutputStream;
 import java.io.IOException;
 import java.io.ObjectOutputStream;
 import java.util.FormatterClosedException;
 import java.util.NoSuchElementException;
 import java.util.Scanner;



 public class CreateSequentialFile {
     private ObjectOutputStream output; // outputs data to file

     // allow user to specify file name
     public void openFile() {
         try // open file
         {
             output = new ObjectOutputStream(
                     new FileOutputStream("clients.ser"));
         } // end try
         catch (IOException ioException) {
             System.err.println("Error opening file");
         } // end catch
     } // end method openFile

     public void addRecords() {
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
         while (input.hasNext()) {
             try {
                 accountNumber = input.nextInt();
                 firstName = input.next();
                 lastName = input.next();
                 balance = input.nextDouble();
                 if (accountNumber > 0) {
                     record = new AccountRecordSerializable(accountNumber, firstName, lastName, balance);
                     output.writeObject(record);
                 } else {
                     System.out.println("Account number must be greater than 0");
                 }
             } catch (IOException e) {
                 System.out.println("Error writing to file");
                 return;
             } catch (NoSuchElementException noSuchElementException) {
                 System.out.println("Invalid input. PLease try again.");
                 input.nextLine();
             }
             System.out.printf("%s %s\n%s", "Enter account number (>0),",
                     "first name, last name and balance", "?");
         }
     }
     public void closeFile(){
         try {
             if (output != null) {
                 output.close();
             }
         }
         catch (IOException e){
             System.out.println("error on closing file");
             System.exit(1);
         }
     }
 }