
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import javax.swing.ImageIcon;
public class Gui  implements ActionListener {
	private Dictionary store;
    private JFrame frame;
    private JTextField wordField;
    private JTextArea definitionArea;
    private JButton searchButton;
    private	JButton clearButton;

    public Gui() {
        store = new Dictionary();
        this.Frame();
    }
    public void clearbutton() {
    	clearButton = new JButton("Clear");
        clearButton.setBounds(180, 240, 80, 30);
        clearButton.addActionListener(this);
        clearButton.setFocusable(false);
    }

public void searchbutton() {
	searchButton = new JButton("Search");
    searchButton.setBounds(280, 20, 100, 30);
    
    searchButton.addActionListener(this);
    searchButton.setFocusable(false);

}

@Override
public void actionPerformed(ActionEvent e) {
	if(e.getSource() == searchButton) {
    
	String word = wordField.getText();
	word=word.toLowerCase();
    String Definition = store.Definitions.get(word);
    String Synonym = store.Synnonyms.get(word);
    String Antonym = store.Antonyms.get(word);
    
    if (Definition != null || Synonym!=null || Antonym != null)
    {
    	if(Definition != null && Synonym != null && Antonym == null)
    		definitionArea.setText("Definition:  " + Definition+ "\nSynonym:  "+Synonym+"\nAntonym not found");
    	else if(Definition != null && Synonym == null && Antonym != null)
        	definitionArea.setText("Definition:  " + Definition+ "\nSynonym not found"+"\nAntonym:  "+Antonym);
    	else 
    		definitionArea.setText("Definition:  " + Definition+ "\nSynonym:  "+Synonym+"\nAntonym:  "+Antonym);

    } 
    else 
    {
        	definitionArea.setText("Word not found in the dictionary.");
    }
    
	}
	else if(e.getSource() == clearButton )
	{
		  wordField.setText("");
          definitionArea.setText("");
	}
}

public void Frame() {
	ImageIcon icon = new ImageIcon("icon.png");
	 frame = new JFrame("Dictionary App");
     frame.setSize(450, 350);
     frame.setIconImage(icon.getImage());
     frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     frame.setResizable(false);
     frame.setLayout(null);

     JLabel wordLabel = new JLabel("Word:");
     wordLabel.setBounds(60, 20, 50, 30);
     frame.add(wordLabel);
     
     this.searchbutton();
     frame.add(searchButton);
     
     this.clearbutton();
     frame.add(clearButton);
     
     wordField = new JTextField();
     wordField.setBounds(120, 20, 150, 30);
     frame.add(wordField);
     
     definitionArea = new JTextArea();
     JScrollPane scrollPane = new JScrollPane(definitionArea);
     scrollPane.setBounds(50, 70, 350, 150);
     frame.add(scrollPane);
     
     frame.setVisible(true);
}
}
