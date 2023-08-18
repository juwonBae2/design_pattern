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
    hr.visit_passbook_account(&name_a);
    hr.visit_passbook_account(&name_b);

    TotalSumReporter sr;
    sr.visit_passbook_account(&name_a);
    sr.visit_passbook_account(&name_b);

    return 0;
}
