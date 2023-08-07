import java.util.Comparable;
public class People implements Comparable
{
    private String name;
    private int age;

    public People(String name, int age)
    {
        this.name = name;
        this.age = age;
    }
    public People()
    {
        name = null;
        age = 0;
    }

    public String getName()
    {
        return this.name;
    }
    public int getAge()
    {
        return this.age;
    }

    public int compareTo(Person another)
    {
        return name.compareTo(another.getName()); // using the fact that String class implements Comparable
    }
    
}