abstract class ParameterDescriptor extends Descriptor {
    ParameterDescriptor(String name_, String description_) {
        super(name_, description_);
    }

    abstract public Parameter instantiate();
}
