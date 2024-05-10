import java.awt.*;
import java.awt.event.*;
/**
 * Event2
 */
public class Event2 extends Frame implements ActionListener {

    private Label l1, l2, l3;
    private TextField tf1, tf2, tf3;
    private Button b1, b2;
    int count = 0;

    public Event2() {
        l1 = new Label("First Number");
        l2 = new Label("Second Number");
        l3 = new Label("Result");

        tf1 = new TextField("0", 10);
        tf2 = new TextField("0", 10);
        tf3 = new TextField("0", 10);

        b1 = new Button("ADD");
        b2 = new Button("SUBTRACT");

        add(l1);
        add(tf1);
        add(l2);
        add(tf2);
        add(l3);
        add(tf3);
        add(b1);
        add(b2);

        b1.addActionListener(this);
        b2.addActionListener(this);

        setTitle("ADDITION AND SUBTRACTION");
        setSize(400, 400);
        setVisible(true);
        
    }

    public static void main(String args[]) {
        Event2 app = new Event2();
    }

    public void actionPerformed(ActionEvent evt) {
        int num1, num2, num3;
        num1 = Integer.parseInt(tf1.getText());
        num2 = Integer.parseInt(tf2.getText());
        
        if (evt.getSource() == b1) {
            num3 = num1 + num2;
            tf3.setText(num3 + " ");
        } else {
            num3 = num1 - num2;
            tf3.setText(num3 + " ");
        }
    }
}