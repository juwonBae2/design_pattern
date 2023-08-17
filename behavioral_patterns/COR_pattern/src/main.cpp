#include "cor_pattern.hpp"

int main()
{
    auto h1 = std::make_unique<ConcreteHandler1>();
    auto h2 = std::make_unique<ConcreteHandler2>();

    h1->SetNext(std::move(h2));

    try
    {
        h1->HandleRequest(1);
        h1->HandleRequest(2);
        h1->HandleRequest(3); // 처리되지 않음
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
