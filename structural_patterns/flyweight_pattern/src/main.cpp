#include "flyweight_pattern.hpp"

// 차량 정보를 데이터베이스에 추가하는 함수
void AddCarToPoliceDatabase(
    FlyweightFactory &flyweight_factory, const std::string &plates, const std::string &owner,
    const std::string &brand, const std::string &model, const std::string &color)
{
    std::cout << "\nClient: Adding a car to the database.\n";
    const Flyweight &flyweight = flyweight_factory.GetFlyweight({brand, model, color});
    flyweight.Operation({owner, plates});
}

int main()
{
    // 플라이웨이트 팩토리 초기화
    FlyweightFactory *factory = new FlyweightFactory({{"Chevrolet", "Camaro2018", "pink"},
                                                      {"Mercedes Benz", "C300", "black"},
                                                      {"Mercedes Benz", "C500", "red"},
                                                      {"BMW", "M5", "red"},
                                                      {"BMW", "X6", "white"}});
    factory->ListFlyweights();

    // 차량 정보를 데이터베이스에 추가
    AddCarToPoliceDatabase(*factory,
                           "CL234IR",
                           "Juwon Bae",
                           "BMW",
                           "M5",
                           "red");

    AddCarToPoliceDatabase(*factory,
                           "CL234IR",
                           "Naseong Boo",
                           "BMW",
                           "X1",
                           "black");
    factory->ListFlyweights();
    delete factory;

    return 0;
}
