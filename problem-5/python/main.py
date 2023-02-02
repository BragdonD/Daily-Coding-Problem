def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def first(a, b):
    return a;
def second(a, b):
    return b;

def car(pair):
    return pair(first);
def cdr(pair):
    return pair(second);     

def main():
    print(car(cons(3, 4)))
    print(cdr(cons(3, 4)))

if __name__ == "__main__":
    main()