class NumberParameter extends Parameter {
    NumberParameter(NumberParameterDescriptor descr) {
        _descriptor = descr;
    }

    public ParameterDescriptor descriptor() {
        return _descriptor;
    }

    private final NumberParameterDescriptor _descriptor;
}
