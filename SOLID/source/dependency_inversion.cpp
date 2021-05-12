/*
 * Dependency Inversion Principal:
 * HIGH LEVEL modules should not depend on LOW LEVEL modules and. Both should
 * depend on Abstraction. ABSTRACTIONS should not depend upon DETAILS. DETAILS
 * should depend upon ABSTRACTIONS. Dependency inversion principal has 2 parts
 * to it:- INVERSION OF CONTROL IoC- the actual process of creating abstractions
 * and getting them to replace dependencies. Dependency Injection - using a
 * software framework/library for injecting dependency in a program, for eg.
 * boost::di
 */

#include <di.hpp>
#include <iostream>
#include <memory>
#include <string>

/* A logger utlity which gets called in the constructors to log the object
 * construction! */
/* @todo: design the logger. */
class iLogger {
public:
  virtual void Log(std::string str) = 0;
};

class ConsoleLogger : public iLogger {
public:
  virtual void Log(std::string str) override { std::cout <<"CONSOLE_LOG: "<< str << std::endl; }
};

class Engine {
private:
  int horse_power = 700;
  float volume = 500;
  std::string manufacturer = "Rolls Royce";

public:
  /* DI seems to be working with default constructor only, need to figure out?
   */
  /* Engine() {} */
  /* explicit Engine(int v, std::string name) : volume(v), manufacturer(name) {}
   */

  friend std::ostream &operator<<(std::ostream &os, const Engine &e) {
    return os << "horse_power:" << e.horse_power << " Volume:" << e.volume
              << " Manufacturer:" << e.manufacturer << std::endl;
  }
};

class Car {
private:
  std::string brand_name = "Jaguar";
  /* having e as a raw pointer didn't work! */
  std::shared_ptr<Engine> engine = nullptr;
  std::shared_ptr<iLogger> loggerObj;

public:
  /* Car() {} */

  /* explicit Car(Engine *e, std::string name) : e(e), brand_name(name) {} */
  explicit Car(std::shared_ptr<Engine> e) : engine(e) {}
  explicit Car(std::shared_ptr<Engine> e, std::shared_ptr<iLogger> lObj) : engine(e), loggerObj(lObj) {
      lObj->Log("Constructing Car");
  }

  friend std::ostream &operator<<(std::ostream &os, const Car &obj) {
    os << "brand_name:" << obj.brand_name << " Engine:" << *obj.engine
       << std::endl;
    return os;
  }
};

int main() {
  /* traditional way for dependency injection. */
  /* auto engine = std::make_shared<Engine>(); */
  /* auto car = std::make_shared<Car>(engine); */

    const auto injector = boost::di::make_injector(
            boost::di::bind<iLogger>().to<ConsoleLogger>()
            );
  auto car = injector.create<std::shared_ptr<Car>>();

  std::cout << "Car:" << *car;
}
