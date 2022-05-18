#pragma once

class Garage {
private:
	Airplane** airplanes = nullptr;
	size_t _count = 0;
	char* _name;
	char* _address;

public:

	Garage();
	Garage(Airplane** airplanes, const char* name, const char* address);


	void setAirplanes(Airplane** airplanes);
	void setCount();
	void setName(const char* name);
	void setAddress(const char* address);

	size_t getCount();
	const char* getName();
	const char* getAddress();
	Airplane** getAirplanes();


	Airplane* getAirplaneById(int id);
	Airplane** getAirplanesCapacityGreaterThan(int cap);
	Airplane** getAirplanesByColor(const char* color);

	void print();
	~Garage();
};

/////////// CONSTRUCTORS

Garage::Garage() {
	_count = Airplane::staticId;
}

Garage::Garage(Airplane** airplanes, const char* name, const char* address) 
	:Garage()
{
	setAirplanes(airplanes);
	setName(name);
	setAddress(address);
}

////////// DECONSTRUCTOR
Garage::~Garage() {
	cout << "Deconstructor->"<<(_name ? "null" : _name) << endl;
	delete[]_name;
	delete[]_address;
	_name = _address = nullptr;
}

//////// ACESSORS
//// SETTERS

void Garage::setAirplanes(Airplane** airplanes){
	this->airplanes = airplanes;
}

void Garage::setCount() {
	_count = Airplane::staticId;
}
void Garage::setName(const char* name) {
	if (name == nullptr)
		assert(!"name==nullptr");
	if (_name != nullptr)
		delete[]_name;
	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}
void Garage::setAddress(const char* address) {
	if (address == nullptr)
		assert(!"address==nullptr");
	if (_address != nullptr)
		delete[]_address;
	size_t len = strlen(address) + 1;
	_address = new char[len];
	strcpy_s(_address, len, address);
}

///// GETTER

size_t Garage::getCount() { return _count; }
const char* Garage::getName() { return _name; }
const char* Garage::getAddress() { return _address; }
Airplane** Garage::getAirplanes() {return airplanes;}






//////// FUNCTIONS
void Garage::print() {
	cout << "Name: " << (_name? _name: "null") << endl;
	cout << "Address: " << (_address ? _address :"null" ) << endl;
	cout << "===== Airplanes =====" << endl;
	for (size_t i = 0; i < _count; i++)
	{
		airplanes[i]->print();
		cout << endl;
	}
}

Airplane* Garage::getAirplaneById(int id) {
	if (id > 0 && id <= _count) {
		for (size_t i = 0; i < _count; i++)
		{
			if (airplanes[i]->getId() == id)
				return airplanes[i];
		}
	}
	else {
		cout << "Incorrect input range" << endl;
		return nullptr;
	}
}

Airplane** Garage::getAirplanesCapacityGreaterThan(int cap) {
	Airplane** temp = new Airplane*[_count]{};
	for (size_t i = 0,j=0; i < _count; i++)
	{
		if (airplanes[i]->getCapasity() > cap)
			temp[j++] = airplanes[i];
	}
	return temp;
}

Airplane** Garage::getAirplanesByColor(const char* color) {
	Airplane** temp = new Airplane*[_count]{};
	for (size_t i = 0,j=0; i < _count; i++)
	{
		if (strcmp(airplanes[i]->getColor(), color) == 0)
			temp[j++] = airplanes[i];
		else continue;
	}
	return temp;
}