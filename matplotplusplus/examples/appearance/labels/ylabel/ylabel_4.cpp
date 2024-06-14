#include <matplot/matplot.h>

int main() {
    using namespace matplot;
    auto x = transform(iota(1, 10), [](double x) { return pow(x, 2); });
    plot(x);
    int year = 2014;
    ylabel("Population for Year " + num2str(year));

    show();
    return 0;
}