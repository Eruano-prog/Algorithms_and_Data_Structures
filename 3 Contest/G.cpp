#include <iostream>
using std::cout;
using std::cin;


int main() {
    int n;
    double l1;
    cin >> n >> l1;
    double last = -1;
    double left = 0;
    double right = l1;
    while ((right-left) > 0.000001){
        double mid = (left + right) / 2;
        double prev = l1;
        double cur = mid;
        bool aboveGround = cur > 0;
        for (int i = 3; i <= n; i++) {
            double next = 2 * cur - prev + 2;
            aboveGround &= next > 0;
            prev = cur;
            cur = next;
        }
        if (aboveGround){
            right = mid;
            last = cur;
        }
        else{
            left = mid;
        }
    }
    printf("%.2f", last);
    return 0;
}
