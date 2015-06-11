class NumberParameterDescriptor extends ParameterDescriptor {
    NumberParameterDescriptor(String name_, String description_, double min_,
                              double max_) {
        super(name_, description_);
        _min = min_;
        _max = max_;
    }

    public Parameter instantiate() {
        return new NumberParameter(this);
    }

    public double min() {
        return _min;
    }

    public double max() {
        return _max;
    }

    private final double _min;
    private final double _max;
}
