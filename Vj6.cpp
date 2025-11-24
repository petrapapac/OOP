#include <iostream>
#include <utility> 

class container {
private:
	int* data;       
	size_t _size;     
	size_t _capacity; 

public:
	
	container(size_t initial_capacity = 0)
		: data(nullptr), _size(0), _capacity(initial_capacity)
	{
		if (_capacity > 0)
			data = new int[_capacity];

		std::cout << "Kreiran container (capacity = " << _capacity << ")\n";
	}

	container(const container& other)
		: _size(other._size), _capacity(other._capacity)
	{
		data = new int[_capacity];
		for (size_t i = 0; i < _size; i++)
			data[i] = other.data[i];

		std::cout << "Copy konstruktor pozvan!\n";
	}

	container(container&& other) noexcept
		: data(other.data), _size(other._size), _capacity(other._capacity)
	{
		other.data = nullptr;
		other._size = 0;
		other._capacity = 0;

		std::cout << "Move konstruktor pozvan!\n";
	}

	~container() {
		std::cout << "Unisten container.\n";
		delete[] data;
	}

	void push_back(int value) {
		if (_size == _capacity) {
			size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
			int* new_data = new int[new_capacity];

			for (size_t i = 0; i < _size; i++)
				new_data[i] = data[i];

			delete[] data;
			data = new_data;
			_capacity = new_capacity;

			std::cout << "Realokacija! Novi capacity = " << _capacity << "\n";
		}

		data[_size++] = value;
	}

	void clear() {
		_size = 0;
	}

	int& at(size_t index) {
		return data[index];
	}

	const int& at(size_t index) const {
		return data[index];
	}

	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }
};

container napravi_container() {
	container c(2);
	c.push_back(10);
	c.push_back(20);
	return c; 
}

void funkcija_po_vrijednosti(container c) {
	std::cout << "Funkcija primila container po vrijednosti.\n";
}

int main() {

	std::cout << "\n1) Default konstruktor + dodavanje:\n";
	container a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	std::cout << "\n2) Copy konstruktor:\n";
	container b = a;

	std::cout << "\n3) Move konstruktor:\n";
	container c = std::move(a);

	std::cout << "\n4) Prosljeđivanje funkciji po vrijednosti:\n";
	funkcija_po_vrijednosti(b);

	std::cout << "\n5) Vraćanje containera iz funkcije:\n";
	container d = napravi_container();

	std::cout << "\n6) Ispis elemenata containera d:\n";
	for (size_t i = 0; i < d.size(); i++) {
		std::cout << "Index " << i << " = " << d.at(i) << "\n";
	}

	return 0;
}
