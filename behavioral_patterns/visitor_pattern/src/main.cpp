#include "visitor_pattern.hpp"

int main()
{
    PassbookAccount name_a{"Juwon Bae"};
    PassbookAccount name_b{"Seonham Lee"};

    name_a.deposit(1000);
    name_a.deposit(200);

    name_b.deposit(10);
    name_b.withdraw(100);
    name_b.deposit(2000);

    HistoryReporter hr;
    hr.visitPassbookAccount(&name_a);
    hr.visitPassbookAccount(&name_b);

    std::cout << "\n";

    TotalSumReporter sr;
    sr.visitPassbookAccount(&name_a);
    sr.visitPassbookAccount(&name_b);

    return 0;
}
