#include "vector.hpp"

using namespace std;

template<typename T> class Vector;
template class Vector<int>;
template class Vector<float>;

template<typename T>
Vector<T>::Vector(T* values, int size)
{
	this->isValid = false;
	this->size = 0;
	this->values = NULL;
	this->name = name;

	if (size != 0)
	{
		this->size = size;
		this->values = new T[size];
		this->isValid = true;

		for (int i = 0; i < size; i++)
			this->values[i] = values[i];
	}
}

template<typename T>
Vector<T>::Vector(Vector<T> & vec)
{
	if (vec.IsValid())
	{
		size = vec.GetSize();
		values = new T[vec.GetSize()];
		isValid = vec.IsValid();

		for (int i = 0; i < size; i++)
			values[i] = vec.GetArray()[i];
	}
}

template<typename T>
Vector<T>::Vector()
{
	this->isValid = false;
	this->size = 0;
	this->values = NULL;
}

template<typename T>
Vector<T>::~Vector()
{
	if (isValid)
		delete[]values;
}

template<typename T>
T* Vector<T>::GetArray()
{
	return values;
}

template<typename T>
int Vector<T>::GetSize()
{
	return size;
}

// Had to put it in the header file...
/*template<typename T>
ostream & operator<<(ostream &os, Vector<T> &vec)
{
	if (vec.IsValid())
	{
		os << "Vector of size : " << vec.size << "\n";
		T* vec_array = vec.GetArray();

		for (int i = 0; i < vec.size; i++)
			os << "[" << vec_array[i] << "]" << "\n";
	}

	else
		cerr << "Vector is invalid, cannot print !" << endl;
	return os;
}*/

template<typename T>
bool Vector<T>::operator==(Vector<T> vec)
{
	if (size != vec.GetSize())
		return false;

	else
	{
		T* vec_array = vec.GetArray();

		for (int i = 0; i < size; i++)
			if (values[i] != vec_array[i])
				return false;
	}

	return true;
}


template<typename T>
Vector<T> Vector<T>::operator+(Vector<T> vec)
{
	if (vec.IsValid() && this->isValid && size == vec.GetSize())
	{
		Vector<T> new_vec(values, size);
		T* vec_array = vec.GetArray();

		for (int i = 0; i < size; i++)
			new_vec.values[i] += vec_array[i];

		return new_vec;
	}
	return Vector<T>();
}

template<typename T>
Vector<T> Vector<T>::operator-(Vector<T> vec)
{
	if (vec.IsValid() && this->isValid && size == vec.GetSize())
	{
		Vector<T> new_vec(values, size);
		T* vec_array = vec.GetArray();

		for (int i = 0; i < size; i++)
			new_vec.values[i] -= vec_array[i];

		return new_vec;
	}

	return Vector<T>();
}

template<typename T>
Vector<T> Vector<T>::operator*(Vector<T> vec)
{
	if (vec.IsValid() && this->isValid && size == vec.GetSize())
	{
		Vector<T> new_vec(values, size);
		T* vec_array = vec.GetArray();

		for (int i = 0; i < size; i++)
			new_vec.values[i] *= vec_array[i];

		return new_vec;
	}

	return Vector<T>();
}

template<typename T>
Vector<T> Vector<T>::operator/(Vector<T> vec)
{
	if (vec.IsValid() && this->isValid && size == vec.GetSize())
	{
		Vector<T> new_vec(values, size);
		T* vec_array = vec.GetArray();

		for (int i = 0; i < size; i++)
		{
			if (vec_array[i] != 0)
				new_vec.values[i] /= vec_array[i];
			else
			{
				cerr << "Right hand side Vector<T> contains \"0\" values, divide by 0 error !" << endl;
				return Vector<T>();
			}
		}
		return new_vec;
	}

	return Vector<T>();
}

template<typename T>
Vector<T> Vector<T>::operator+(int value)
{
	if (this->isValid)
	{
		Vector<T> new_vec(values, size);

		for (int i = 0; i < size; i++)
			new_vec.values[i] += value;

		return new_vec;
	}
	else
		return Vector<T>();
}

template<typename T>
Vector<T> Vector<T>::operator-(int value)
{
	if (this->isValid)
	{
		Vector<T> new_vec(values, size);

		for (int i = 0; i < size; i++)
			new_vec.values[i] -= value;

		return new_vec;
	}
	else
		return Vector<T>();
}

template<typename T>
Vector<T> Vector<T>::operator*(int value)
{
	if (this->isValid)
	{
		Vector<T> new_vec(values, size);

		for (int i = 0; i < size; i++)
			new_vec.values[i] *= value;

		return new_vec;
	}
	else
		return Vector<T>();
}

template<typename T> 
Vector<T> Vector<T>::operator/(int value)
{
	if (this->isValid)
	{
		Vector<T> new_vec(values, size);

		for (int i = 0; i < size; i++)
			new_vec.values[i] /= value;

		return new_vec;
	}
	else
		return Vector<T>();
}

// Only for 3d vectors, not 7d. Other dimensions impossible.
template<typename T> 
Vector<T> Vector<T>::cross(Vector<T> vec)
{
	if (vec.IsValid() && this->isValid && size == 3 && vec.GetSize() == 3)
	{
		T* values = new T[size];
		T* vec_array = vec.GetArray();

		values[0] = this->values[1] * vec_array[2] - this->values[2] * vec_array[1];
		values[1] = this->values[0] * vec_array[2] - this->values[2] * vec_array[0];
		values[2] = this->values[0] * vec_array[1] - this->values[1] * vec_array[0];
		return Vector<T>(values, size);
	}
	cerr << "Cannot compute cross product : Vectors size is != 3" << endl;
	return Vector<T>();
}

template <typename T>
T Vector<T>::dot(Vector<T> vec)
{
	if (vec.IsValid() && this->isValid && size == vec.GetSize())
	{
		T result = T(); // Default value for any type (int, float..)
		T* vec_array = vec.GetArray();

		for (int i = 0; i < size; i++)
			result += this->values[i] * vec_array[i];

		return result;
	}
	else
	{
		cerr << "Cannot compute dot product : One or both vectors are invalid or their sizes are not identical !" << endl;
		return -1;
	}
}