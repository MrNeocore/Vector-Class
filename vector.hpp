#include <iostream>

template<typename T>
class Vector
{
public:
	Vector(T* values, int size);
	Vector(Vector<T>& vec);
	Vector();
	~Vector();

	bool operator==(Vector<T> vec);
	Vector<T> operator+(Vector<T> vec);
	Vector<T> operator-(Vector<T> vec);
	Vector<T> operator/(Vector<T> vec);
	Vector<T> operator*(Vector<T> vec);

	Vector<T> operator+(int value);
	Vector<T> operator-(int value);
	Vector<T> operator/(int value);
	Vector<T> operator*(int value);

	Vector<T> cross(Vector<T> vec);
	T dot(Vector<T> vec);

	T* GetArray();

	int GetSize();
	bool IsValid() { return isValid; }
	friend std::ostream & operator<<(std::ostream &os, Vector &vec)
	{
		if (vec.IsValid())
		{
			os << "Vector of size : " << vec.size << "\n";
			T* vec_array = vec.GetArray();

			for (int i = 0; i < vec.size; i++)
				os << "[" << vec_array[i] << "]" << "\n";
		}

		else
			std::cerr << "Vector is invalid, cannot print !" << std::endl;
		return os;
	}


private:
	T* values;
	int size;
	bool isValid;
	std::string name;
};
