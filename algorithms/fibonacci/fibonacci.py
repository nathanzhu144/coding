

def fibonacci(num):
    fibonacci_list = []

    fibonacci_list.append(0)
    fibonacci_list.append(1)

    for i in xrange(2, num + 1):
        fibonacci_list.append(fibonacci_list[i - 1] + fibonacci_list[i - 2])

    return fibonacci_list[num]


def main():
    print(fibonacci(500000))

if __name__ == "__main__":
    main()