def get_output(array):
    output = [1] * 5;
    i = 0;
    j = 0;
    while i < len(array):
        j = 0
        while j < len(array):
            output[i] *= array[j]
            j += 1;
        output[i] /= array[i];
        i += 1;
    return output;

def get_output_wo_div(array):
    output = [1] * 5;
    i = 0;
    j = 0;
    while i < len(array):
        j = 0
        while j < len(array):
            if(i != j):
                output[i] *= array[j]
            j += 1;
        i += 1;
    return output;

def main():
    print(get_output([1, 2, 3, 4, 5]));
    print(get_output_wo_div([1, 2, 3, 4, 5]));

if __name__ == "__main__":
    main()
