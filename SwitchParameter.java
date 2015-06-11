class SwitchParameter extends Parameter {
    SwitchParameter(SwitchParameterDescriptor descr) {
        _descriptor = descr;
    }

    public ParameterDescriptor descriptor() {
        return _descriptor;
    }

    private final SwitchParameterDescriptor _descriptor;
}
