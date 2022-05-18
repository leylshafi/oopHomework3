#pragma once
class Airplane {
	int _id;
	char* _model;
	char* _color;
	double _engine;
	int _capacity;

public:
	static int staticId;
	static int MAXCOUNT;

	Airplane();
	Airplane(const char*model, const char*color, double engine, int capasity);

	size_t getStaticId();
	int getId();
	const char* getModel();
	const char* getColor();
	double getEngine();
	int getCapasity();

	void setModel(const char* model);
	void setColor(const char* color);
	void setEngine(double engine);
	void setCapasity(int capasity);

	static int getMaxCount();

	void print();
	~Airplane();
};
int Airplane::staticId = 0;
int Airplane::MAXCOUNT = 5;
// getMaxCount;


//////// CONSTRUCTOR
Airplane::Airplane(){
	if (MAXCOUNT == 0)
		assert(!"MAXCOUNT==0");
	_id = ++staticId;
	MAXCOUNT--;
}
Airplane::Airplane(const char* model, const char* color, double engine, int capasity)
	:Airplane()
{
	setModel(model);
	setColor(color);
	setEngine(engine);
	setCapasity(capasity);
}

//////// DESTRUCTOR
Airplane::~Airplane() {
	cout << "Destructor->" << (_model ? "null" : _model) << endl;
	delete[]_model;
	delete[]_color;
	_model = _color = nullptr;
}

//////// ACCESSORS

//// GETTER

int Airplane::getId() { return _id;}
const char* Airplane::getModel() { return _model; }
const char* Airplane::getColor() { return _color; }
double Airplane::getEngine() { return _engine; }
int Airplane::getCapasity() { return _capacity; }
size_t Airplane::getStaticId() { return staticId; }
int  Airplane::getMaxCount() { return MAXCOUNT; }

//// SETTER


void Airplane::setModel(const char* model) {
	if (model == nullptr)
		assert(!"model==nullptr");
	if (_model != nullptr)
		delete[]_model;
	size_t len = strlen(model) + 1;
	_model = new char[len];
	strcpy_s(_model, len, model);

}
void Airplane::setColor(const char* color) {
	if (color == nullptr)
		assert(!"color==nullptr");
	if (_color != nullptr)
		delete[]_color;
	size_t len = strlen(color) + 1;
	_color = new char[len];
	strcpy_s(_color, len, color);
}
void Airplane::setEngine(double engine) {
	if (engine >= 0 && engine <= 15)
		_engine = engine;
	else
		assert(!"engine >= 0 && engine <= 15");
}
void Airplane::setCapasity(int capacity) {
	if (capacity >= 100 && capacity <= 500)
		_capacity = capacity;
	else
		assert(!"capacity >= 100 && capacity <= 500");
}

////// FUNCTIONS
void Airplane::print() {
	cout << "ID: " << _id << endl;
	cout << "Model: " << _model << endl;
	cout << "Color: " << _color << endl;
	cout << "Engine: " << _engine << endl;
	cout << "Capacity: " << _capacity << endl;
}