#include <iostream>
#include <memory>

// Абстрактний клас автомобіля
class Car {
public:
    virtual void showInfo() const = 0;
    virtual ~Car() {}
};

// Два конкретних класи автомобіля
class Sedan : public Car {
public:
    void showInfo() const override {
        std::cout << "Sedan" << std::endl;
    }
};

class SUV : public Car {
public:
    void showInfo() const override {
        std::cout << "SUV" << std::endl;
    }
};

// Абстрактний клас комплектації
class CarOptions {
public:
    virtual void showOptions() const = 0;
    virtual ~CarOptions() {}
};

// Два конкретних класи комплектації
class LuxuryPackage : public CarOptions {
public:
    void showOptions() const override {
        std::cout << "Luxury Package" << std::endl;
    }
};

class SportsPackage : public CarOptions {
public:
    void showOptions() const override {
        std::cout << "Sports Package" << std::endl;
    }
};

// Абстрактна фабрика
class CarFactory {
public:
    virtual std::shared_ptr<Car> createCar() const = 0;
    virtual std::shared_ptr<CarOptions> createOptions() const = 0;
    virtual ~CarFactory() {}
};

// Два конкретні фабрики для створення Sedan та SUV
class SedanFactory : public CarFactory {
public:
    std::shared_ptr<Car> createCar() const override {
        return std::make_shared<Sedan>();
    }

    std::shared_ptr<CarOptions> createOptions() const override {
        return std::make_shared<LuxuryPackage>();
    }
};

class SUVFactory : public CarFactory {
public:
    std::shared_ptr<Car> createCar() const override {
        return std::make_shared<SUV>();
    }

    std::shared_ptr<CarOptions> createOptions() const override {
        return std::make_shared<SportsPackage>();
    }
};

int main() {
    // Використання абстрактної фабрики для створення автомобіля та комплектації
    std::unique_ptr<CarFactory> sedanFactory = std::make_unique<SedanFactory>();
    std::shared_ptr<Car> sedanCar = sedanFactory->createCar();
    std::shared_ptr<CarOptions> sedanOptions = sedanFactory->createOptions();

    std::unique_ptr<CarFactory> suvFactory = std::make_unique<SUVFactory>();
    std::shared_ptr<Car> suvCar = suvFactory->createCar();
    std::shared_ptr<CarOptions> suvOptions = suvFactory->createOptions();

    // Виведення інформації про автомобілі та їх комплектації
    sedanCar->showInfo();
    sedanOptions->showOptions();

    suvCar->showInfo();
    suvOptions->showOptions();

    return 0;
}
