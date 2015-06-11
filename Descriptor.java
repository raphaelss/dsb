class Descriptor implements Describable {
    public Descriptor(String name_, String description_)
    {
        _name = name_;
        _description = description_;
    }

    public String name() {
        return _name;
    }

    public String description() {
        return _description;
    }

    private final String _name;
    private final String _description;
}
