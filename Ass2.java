import java.util.*;

class Base {
    void area(){
        System.out.println("\nShape Area\n");
    }
}

class Circle extends Base {
    double radius;
    
    Circle(int r){
        radius = r;
    }
    
    void area(){
        double result = 3.14 * radius * radius;
        System.out.println("\nResult : " + result);
    }
}

class Rectangle extends Base {
    int len;
    int width;
    
    Rectangle(int l, int w){
        len = l;
        width = w;
    }
    
    void area(){
        double result = len * width;
        System.out.println("\nResult : " + result);
    }
}

class Triangle extends Base {
    int base;
    int height;
    
    Triangle(int b,int h){
        base = b;
        height = h;
    }
    
    void area(){
        double result = 0.5 * base * height;
        System.out.println("\nResult : " + result);
    }
}

public class Ass2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int choice;
        
        do {
            System.out.println("1.Circle Area\n2.Rectangle Area\n3.Triangle Area\nEnter your choice:");
            choice = sc.nextInt();
            switch(choice){
            case 1:
                int r1;
                System.out.println("\nEnter Radius:");
                r1 = sc.nextInt();
                
                Circle c = new Circle(r1);
                c.area();
                break;
            case 2:
                int l1,w1;
                System.out.println("\nEnter Length:");
                l1 = sc.nextInt();
                System.out.println("\nEnter Width:");
                w1 = sc.nextInt();
                
                Rectangle r = new Rectangle(l1,w1);
                r.area();
                break;
            case 3:
                int b1, h1;
                System.out.println("\nEnter Base:");
                b1 = sc.nextInt();
                System.out.println("\nEnter Height:");
                h1 = sc.nextInt();
                
                Triangle t = new Triangle(b1,h1);
                t.area();
                break;
            default:
            System.out.println("Invalid");
        }
        }while(choice != 4);
        sc.close();
    }
    
}