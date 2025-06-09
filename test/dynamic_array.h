#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
using namespace std;
template <typename T>
class Dynamic_array {
private:
	T* arr;
	int len;
	int cap;

	// Doubles the current capacity when needed
	void double_capacity() {
		T* temp = new T[this->cap + this->cap + 1];
		for (int i = 0; i < this->len; i++) {
			temp[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = temp;
		this->cap = this->cap + this->cap + 1;
	}
public:
	// Constructors & Destructor
	Dynamic_array() : arr{ new T[1] }, len{ 0 }, cap{ 1 } {}
	// Default constructor
	Dynamic_array(int count, const T value) {
		this->cap = count + 2;
		this->len = count;
		this->arr = new T[this->cap];
		for (int i = 0; i < count; i++) {
			this->arr[i] = value;
		}
	}// Fill constructor
	Dynamic_array(const Dynamic_array& other) {
		this->cap = other.cap;
		this->len = other.len;
		this->arr = new T[this->cap];
		for (int i = 0; i < this->len; i++) {
			this->arr[i] = other.arr[i];
		}
	} // Copy constructor
	~Dynamic_array() {
		delete[] this->arr;
	}                      // Destructor

	// Operators
	Dynamic_array& operator=(const Dynamic_array& other) {
		if (this != &other) {
			this->cap = other.cap;
			this->len = other.len;
			this->arr = new T[this->cap];
			for (int i = 0; i < this->len; i++) {
				this->arr[i] = other.arr[i];
			}
		}
		return *this;
	} // Copy assignment
	T& operator[](int index) const {
		if (index > -1 && index < this->len) {
			return this->arr[index];
		}
		else {
			exit(1);
		}
	}
	// Subscript operator
//const int& operator[](int index) const;            // Const subscript operator
	bool operator==(const Dynamic_array& other) const {
		if (this->len != other.len) {
			return false;
		}
		for (int i = 0; i < this->len; i++) {
			if (this->arr[i] != other.arr[i]) {
				return false;
			}
		}
		return true;
	}// Equality comparison
	bool operator!=(const Dynamic_array& other) const {
		if (*this == other) {
			return false;
		}
		return true;
	} // Inequality comparison
	Dynamic_array operator+(const Dynamic_array& other) const {
		Dynamic_array res;
		res.cap = this->cap + other.cap;
		res.len = this->len + other.len;
		res.arr = new T[res.cap]{};
		int k = 0;
		for (int i = 0; i < this->len; i++) {
			res.arr[k++] = this->arr[i];
		}
		for (int i = 0; i < other.len; i++) {
			res.arr[k++] = other.arr[i];
		}
		return res;
	} // Concatenation
	Dynamic_array& operator+=(const Dynamic_array& other) {
		*this = *this + other;
		return *this;
	}    // Append

	// Modifiers
	void push(const T value) {
		if (this->len >= this->cap - 1) {
			this->double_capacity();
		}
		this->arr[this->len++] = value;
	}                // Adds an element to the end
	void pop() {
		this->len--;
	}                           // Removes the last element
	void insert_at(int index, const T value) {
		if (index > -1 && index < this->len + 1) {
			if (index == this->len && this->len >= this->cap + 1) {
				this->double_capacity();
			}
			if (index == this->len) {
				this->len++;
			}
			this->arr[index] = value;
		}
	} // Inserts value at index
	void delete_at(int index) {
		T* temp = this->arr;
		this->arr = new T[this->cap]{};
		int k = 0;
		for (int i = 0; i < this->len; i++) {
			if (i != index) {
				this->arr[k++] = temp[i];
			}
		}
		this->len--;
		delete[] temp;
	}        // Deletes value at index
	void reserve(int new_capacity) {
		if (new_capacity > -1) {
			T* temp = new T[new_capacity]{};
			for (int i = 0; i < this->len && i < new_capacity; i++) {
				temp[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = temp;
			this->cap = new_capacity;
			this->len = new_capacity;
		}
	}    // Reserves a new capacity
	void clear() {
		for (int i = 0; i < this->len; i++) {
			this->arr[i] = 0;
		}
		this->len = 0;
	}                         // Clears all elements
	void swap(Dynamic_array& other) {
		delete this->arr;
		*this = other;
	}     // Swaps with another array
	void shrink_to_fit() {
		this->reserve(this->len);
	}                 // Reduces capacity to match size
	void reverse() {
		T* temp = new T[this->cap]{};
		int k = 0;
		for (int i = this->len - 1; i > -1; i--) {
			temp[k++] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = temp;
	}                      // Reverses the array elements

	// Accessors
	bool empty() const {
		if (this->len == 0) {
			return true;
		}
		return false;
	} // Checks if array is empty
	int size() const {
		return this->len;
	}   // Returns current size

	T& at(int index) const {
		if (index > -1 && index < this->len) {
			return this->arr[index];
		}
		else {
			exit(1);
		}
	} // Bounds-checked element access

	T& front() {
		return this->arr[0];
	} // Returns first element
	const T& front() const {
		return this->arr[0];
	}

	T& back() {
		return this->arr[this->len - 1];
	} // Returns last element
	const T& back() const {
		return this->arr[this->len - 1];
	}

	int find(const T value) const {
		for (int i = 0; i < this->len; i++) {
			if (this->arr[i] == value) {
				return i;
			}
		}
		return -1;
	} // Return index of first instance, or -1 if non-existent
	void print() const {
		for (int i = 0; i < this->len; i++) {
			std::cout << this->arr[i] << endl;
		}
	}
	friend std::ostream& operator<<(std::ostream& fout, Dynamic_array<T>& da) {
		da.print();
		return fout;
	}
};

#endif // DYNAMIC_ARRAY_H