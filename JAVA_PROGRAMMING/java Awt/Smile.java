
import java.awt.*;

public class Smile extends Canvas  {
   public void paint(Graphics g) {
        g.drawOval(420, 135, 500, 500);
        g.drawLine(649, 200, 649, 400);

   }
   public static void main(String args[]) {
        Smile s = new Smile();
        Frame f = new Frame();
        f.add(s);
        f.setTitle("Smile");
        f.setSize(300, 400);
        f.setVisible(true);
   }
}
