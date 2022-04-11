#pragma once
template <class T>
class Stek {
private:
	T* ptr;
	int Size;
	int Index;
	static const int MAX = 50;
public:
	Stek(int);
	~Stek();
	bool Put(const T&);
	bool Get(T&);
	bool Full();
	bool Empty();


};
template<class T>
Stek<T>::Stek(int n) {
	if (n > 0 && n < MAX) Size = n;
	else Size = 50;
	Index = -1;
	ptr = new T[Size];
}

template<class T>
Stek<T>::~Stek() { delete[] ptr; }

template<class T>
bool Stek<T>::Put(const T& Element) {
	if (Full() == false) {
		ptr[++Index] = Element;
		return true;
	}
	else
		return false;
}
template<class T>
bool Stek<T>::Get(T& Element) {
	if (Empty() == false) {
		Element = ptr[Index--];
		return true;
	}
	return false;

}
template<class T>
bool Stek<T>::Full() {
	if (Index == Size - 1)
		return true;
	else
		return false;
}
template<class T>
bool Stek<T>::Empty() {
	if (Index == -1)
		return true;
	else
		return false;
}

