package Reflection;

public class Cat {
    private String Name;
    private int age;

    public Cat(String name, int age) {
        Name = name;
        this.age = age;
    }
    public Cat(){
        this("",0);
    }
    private static void meow(){
        System.out.println("Meow meow");
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public static void eat(){
        System.out.println("Fish");
    }
}
