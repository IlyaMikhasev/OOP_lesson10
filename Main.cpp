#include <iostream>
#include <string>
//������������
//class A {
//public:
//	void public_metod() {}
//protected:
//	void protected_metod() {}
//private:
//	void private_metod() {}
//};
//class B : public A {
//private:
//	void func() {
//		protected_metod();
//	}
//};

//����������
//��������� � ����������
//���������� - ����� ����� �� ���������� ��� �������

//class Engine {
//public:
//	Engine(int p) : _power(p) {
//		std::cout << "Engine constructor was called\n";
//	}
//	Engine(Engine& other):_power(other._power) {//����������� �����������(����� ��������� � private ����� ������)
//		std::cout << "Engine copy constructor was called\n";
//	}
//	int GetPower() {
//		return _power;
//	}
//private:
//	int _power;
//};

//class Cars {
//public:
//	//���������� 
//	Cars(int enginePower) :_engine(enginePower) {
//		std::cout << "Composite constructor was called\n";
//	}
//	//���������
//	Cars(Engine& e):_engine(e) {
//		std::cout << "Agregation constructor was called\n";
//	}
//	int getPower() {
//		return _engine.GetPower();
//	}
//private:
//	std::string _model = "Porshe";
//	Engine _engine;//car ����������� � Engine
//};
//		����������� ������������
//				Vehicle
//				/	\
//			Car		Airplane
//				\	/
//				FlyCar
//class Vehicle {
//public:
//	Vehicle(int speed) :_speed(speed) {
//		std::cout << "Vehicle()" << '\n';
//	}
//	int getSpeed() {
//		return _speed;
//	}
//private:
//	int _speed;
//};
//enum Transmition {
//	Auto,//��������������
//	Manual//������
//};
//class Car :public virtual Vehicle {//����������� ������������ �� ������� ��� ������� vehicle
//public:
//	Car(int speed, Transmition transmation):Vehicle(speed),_transmition(transmation) {}
//private:
//	Transmition _transmition;
//};
//enum OriginCountry {
//	Russia,
//	USA
//};
//class Airplane : public virtual  Vehicle {//����������� ������������ �� ������� ��� ������� vehicle
//public:
//	Airplane(int speed, OriginCountry country) :Vehicle(speed), _country(country) {}
//private:
//	OriginCountry _country;
//};
//enum FlyCarMode {
//	Drive,
//	Fly
//};
//class FlyCar :public Car, Airplane {
//public:
//	FlyCar(int speed, OriginCountry country, Transmition transmition, FlyCarMode initialMode)
//		:Car(speed, transmition), Airplane(speed, country), _mode(initialMode), Vehicle(speed) {}
//	//� ����� ��� ����������� ������ ������������� � ����� Vehicle  ����������� speed
//private:
//	FlyCarMode _mode;
//};
//����������� �������//������������ �����������
class A {
public:
	//static dispath/early binding(����������� �����, ����� ��������)
	void func() {
		std::cout << "A::func()" << '\n';
	}

};
class B {
public:
	virtual void bar() {
		std::cout << "B::Bar\n";
	}
	virtual void qux() {
		std::cout << "B::Qux\n";
	}	
};
class C : public B{
public:
	void bar() override{//override - ���������� ������������ �������
		std::cout << "C::Bar\n";
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	/*A a;
	B b;
	Engine e(333);
	Cars car1(200),car2(e);
	
	std::cout << car1.getPower() << '\n';
	std::cout << car2.getPower() << '\n';*/
	//FlyCar flycar(800, OriginCountry::Russia, Transmition::Auto, FlyCarMode::Fly);
	//std::cout << flycar.Car::getSpeed() << std::endl;//��� Car:: - ������� ��� �������� ������������ /������/
	//Vehicle* flycar2 = new FlyCar(800, OriginCountry::Russia, Transmition::Auto, FlyCarMode::Fly);


	//delete flycar2;//�������� ���������� ������(�����������)
	B b1;
	B* b = new C;
	b->bar();
	b1.bar();
	return 0;
}