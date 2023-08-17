#include "proxy_pattern.hpp"

void clientCode(const Subject &subject)
{
    subject.request();
}

int main()
{
    RealSubject *real_subject = new RealSubject;
    clientCode(*real_subject);
    std::cout << "\n";

    Proxy *proxy = new Proxy(real_subject);
    clientCode(*proxy);

    delete real_subject;
    delete proxy;

    return 0;
}
