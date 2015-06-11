class Block {
    Block(int input_n_, int output_n_, Parameter[] parameters) {
        _inputs = new Block[input_n_];
        _outputs = new Block[output_n_];
        _parameters = parameters;
    }

    public int input_free() {
        return first_free(_inputs);
    }

    public int output_free() {
        return first_free(_outputs);
    }

    public boolean input_full() {
        return input_free() == -1;
    }

    public boolean output_full() {
        return output_free() == -1;
    }

    public Block input_at(int i) {
        return _inputs[i];
    }

    public Block output_at(int i) {
        return _outputs[i];
    }

    public int input_n() {
        return _inputs.length;
    }

    public int output_n() {
        return _outputs.length;
    }

    private static int first_free(Block[] arr) {
        int i = arr.length - 1;
        for (; i > 0; --i) {
            if (arr[i] == null) {
                return i;
            }
        }
        return i;
    }

    private final Block[] _inputs;
    private final Block[] _outputs;
    private final Parameter[] _parameters;
}
