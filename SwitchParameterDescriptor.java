class SwitchParameterDescriptor extends ParameterDescriptor {
    SwitchParameterDescriptor(String name_, String description_,
                              String[] options) {
        super(name_, description_);
        _options = options;
    }


    public Parameter instantiate() {
        return new SwitchParameter(this);
    }

    public String at(int index) {
        return _options[index];
    }

    public int length() {
        return _options.length;
    }

    private final String[] _options;
}
