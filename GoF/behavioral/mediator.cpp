#include <iostream>
#include <string>
using namespace std;

// Colleague Interface
class Airplane {
  public:
    string id;
    virtual void requestTakeoff() = 0;
    virtual ~Airplane() {};
};

// Mediator Interface
class AirTrafficControlTower {
  public:
    virtual void takeoffClearance(Airplane* airplane) = 0;
    virtual ~AirTrafficControlTower() {};
};

// Concrete Mediator
class AirportControlTower : public AirTrafficControlTower {
  public:
    void takeoffClearance(Airplane* airplane) override {
      // Checking air traffic for example in here..

      cout << "Takeoff clearance for " + airplane->id << endl;
    }
};

// Concrete Colleague
class CommercialAirplane : public Airplane {
  private:
    AirTrafficControlTower* mediator;

  public:
    CommercialAirplane(AirTrafficControlTower* mediator, string id) : mediator(mediator) {
      this->id = id;
    }

    void requestTakeoff() override {
      mediator->takeoffClearance(this);
    }
};

// Main class
int main() {
  // Mediator
  AirTrafficControlTower* controlTower = new AirportControlTower();

  // Colleagues to be mediated
  Airplane* airplane1 = new CommercialAirplane(controlTower, "A1");
  Airplane* airplane2 = new CommercialAirplane(controlTower, "A2");

  // Collegues requesting takeoff to mediator
  airplane1->requestTakeoff();
  airplane2->requestTakeoff();

  delete controlTower;
  delete airplane1;
  delete airplane2;

  return 0;
}


/*
Output

Takeoff clearance for A1
Takeoff clearance for A2
*/