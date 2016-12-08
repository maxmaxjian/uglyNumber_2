#include <iostream>


class solution {
public:
    int nthUglyNumber(int n) {
	int result;
	if (n == 1)
	    result = 1;
	else {
	    result = nthUglyNumber(n-1);
	    result++;
	    while (!isUgly(result))
		result++;
	}
	return result;
    }

private:
    bool isUgly(int n) {
	if (n == 1)
	    return true;
	else if (n >= 2) {
	    for (int i = 2; i <= n; i++) {
		if (isPrime(i) && !(n%i)) {
		    if (i != 2 && i != 3 && i != 5)
			return false;
		}
	    }
	    return true;
	}
    }

    bool isPrime(int n) {
	if (n == 2)
	    return true;
	else if (n > 2) {
	    for (int i = 2; i < n; i++)
		if (n%i == 0)
		    return false;
	    return true;
	}
    }
};

int main() {
    int nth = 15;

    solution soln;
    int nthUgly = soln.nthUglyNumber(nth);
    std::cout << "The " << nth << "-th ugly number is:\n"
	      << nthUgly << std::endl;
}
