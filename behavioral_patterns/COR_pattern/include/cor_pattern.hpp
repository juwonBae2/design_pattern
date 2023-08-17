#include <iostream>
#include <memory>
#include <stdexcept>
#include <sstream>

class Handler
{
public:
    virtual ~Handler() = default;

    void SetNext(std::unique_ptr<Handler> next)
    {
        next_ = std::move(next);
    }

    virtual void HandleRequest(int request)
    {
        if (next_)
        {
            next_->HandleRequest(request);
        }
        else
        {
            std::ostringstream msg;
            msg << "Request not processed: " << request;
            throw std::runtime_error(msg.str());
        }
    }

private:
    std::unique_ptr<Handler> next_ = nullptr;
};

class ConcreteHandler1 : public Handler
{
public:
    virtual void HandleRequest(int request) override
    {
        if (request == 1)
        {
            std::cout << "ConcreteHandler1 process\n";
        }
        else
        {
            Handler::HandleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler
{
public:
    virtual void HandleRequest(int request) override
    {
        if (request == 2)
        {
            std::cout << "ConcreteHandler2 process\n";
        }
        else
        {
            Handler::HandleRequest(request);
        }
    }
};
