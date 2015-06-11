abstract class Parameter implements Describable {
    public String name() {
        return descriptor().name();
    }

    public String description() {
        return descriptor().description();
    }

    abstract public ParameterDescriptor descriptor();
}
