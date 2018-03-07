import java.util.LinkedList;

public abstract class numbers{
    private String name;
    public numbers(String nm) {
        name = nm;
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    @Override 
    public abstract boolean equals(Object o);

    @Override 
    public abstract numbers clone();

    @Override 
    public abstract String toString();
    public abstract void clear();
    public abstract void add_value(Integer n);
    public abstract void sub_value(Integer n);
    public abstract void add_list(LinkedList<Integer> l);
    public abstract void sub_list(LinkedList<Integer> l);
}

