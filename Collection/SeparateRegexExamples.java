package Collection;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SeparateRegexExamples {
    public static void main(String[] args) {
        // Sample data
        String[] rollNumbers = {"1107", "1234", "abcd"};
        String[] emails = {"bsse1234@iit.du.ac.bd", "invalid@domain.com", "bsse5678@iit.du.ac.bd"};
        String[] sessions = {"2022-2023", "2023-2024", "invalid-format"};

        // Roll Number Validation
        Pattern rollNumberPattern = Pattern.compile("^\\d{4}$");
        for (String rollNumber : rollNumbers) {
            Matcher matcher = rollNumberPattern.matcher(rollNumber);
            System.out.println(rollNumber + " is " + (matcher.matches() ? "valid" : "invalid") + " for Roll Number.");
        }

        // Email Validation
        Pattern emailPattern = Pattern.compile("^bsse[0-9]{4}@iit\\.du\\.ac\\.bd$");
        for (String email : emails) {
            Matcher matcher = emailPattern.matcher(email);
            System.out.println(email + " is " + (matcher.matches() ? "valid" : "invalid") + " for Email.");
        }

        // Session Validation
        Pattern sessionPattern = Pattern.compile("^\\d{4}-\\d{4}$");
        for (String session : sessions) {
            Matcher matcher = sessionPattern.matcher(session);
            System.out.println(session + " is " + (matcher.matches() ? "valid" : "invalid") + " for Session.");
        }
    }
}

