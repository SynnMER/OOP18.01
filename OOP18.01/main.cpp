#include <iostream>
#include <unordered_map>
#include <vector>
//русский язык , cin
//Наследование шаблонных классов
template <class T>
class Shape {
public:
	Shape(T width, T height) : _width(width), _height(height) {
		std::cout << "Constructor Shape()" << std::endl;
	}

	T calculateSquare() {
		return _width * _height;
	}
private:
	T _width;
	T _height;
};

template <class T>
class Square :public Shape<T> //публичные данные из Shape также будут публичными в Square
{
public:
	Square(T width,T height): Shape<T>(width, height),_width(width){
		std::cout << "Constructor Square()" << std::endl;
	}
	T calculateSquare() {
		return _width * _width;
	}
private:
	T _width;
};
// Variadic Templates - Вариабельные шаблоны
// template <typename ... Args> void f(Args ... args); - пример вариабельной фуннкции 
template <typename ... Types>
class MyClass {
public:
	void printAll(Types ... args) {
		std::cout << sizeof...(args) << std::endl;
		(std::cout << ... << args) << std::endl;
	}
};
int main() {
	Square <int> s(5,4);
	s.calculateSquare();
	std::cout << std::endl;
	MyClass <int,double,float,std::string> a;
	int x = 5;
	double y = 3.4;
	float z = 11.2f;
	std::string str = "Hello world";
	a.printAll(x, y, z, str);
	return 0;

}
//Свертки
//template <typename ... T>
//auto sum_all (T ... args){return (args + ...);}
//
//template <typename ... T>
//void print_All (T ... args){(cout<< ... <<args)<<endl;}