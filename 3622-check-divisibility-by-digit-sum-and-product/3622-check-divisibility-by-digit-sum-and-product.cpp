class Solution {
public:
    int sumOfDigit(int n) {
        int sum = 0;
        while (n > 0){
            sum += n % 10;
            n = n / 10;
        }

            return sum;
    }

    int productofDigit(int n) {
        int product = 1;
        while (n > 0) {
            product = product * (n % 10);
            n = n / 10;
        }

        return product;
    }
    bool checkDivisibility(int n) {
        return (n % (sumOfDigit(n) + productofDigit(n)) == 0);
    }
};