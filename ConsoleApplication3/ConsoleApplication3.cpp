#include <iostream>
#include <memory>

// ����������� ���� ���������
class Car {
public:
    virtual void showInfo() const = 0;
    virtual ~Car() {}
};

// ��� ���������� ����� ���������
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

// ����������� ���� ������������
class CarOptions {
public:
    virtual void showOptions() const = 0;
    virtual ~CarOptions() {}
};

// ��� ���������� ����� ������������
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

// ���������� �������
class CarFactory {
public:
    virtual std::shared_ptr<Car> createCar() const = 0;
    virtual std::shared_ptr<CarOptions> createOptions() const = 0;
    virtual ~CarFactory() {}
};

// ��� �������� ������� ��� ��������� Sedan �� SUV
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
    // ������������ ���������� ������� ��� ��������� ��������� �� ������������
    std::unique_ptr<CarFactory> sedanFactory = std::make_unique<SedanFactory>();
    std::shared_ptr<Car> sedanCar = sedanFactory->createCar();
    std::shared_ptr<CarOptions> sedanOptions = sedanFactory->createOptions();

    std::unique_ptr<CarFactory> suvFactory = std::make_unique<SUVFactory>();
    std::shared_ptr<Car> suvCar = suvFactory->createCar();
    std::shared_ptr<CarOptions> suvOptions = suvFactory->createOptions();

    // ��������� ���������� ��� �������� �� �� ������������
    sedanCar->showInfo();
    sedanOptions->showOptions();

    suvCar->showInfo();
    suvOptions->showOptions();

    return 0;
}
