class Vector : virtual public MyCollection<int>
{
	int size = 0;
	int capacity = 10;
	int* data;

public:
	Vector() : Vector(10)
	{
	}

	Vector(int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		if (capacity > 500000000)
		{
			capacity = 500000000;
		}
		this->capacity = capacity;
		data = new int[capacity];
	}

	~Vector()
	{
		delete[] data;
	}

private:
	void EnsureCapacity(int count)
	{
		if (capacity >= count) return;
		int new_capacity = capacity * 3 / 2 + 1;
		int* temp = new int[new_capacity];

		for (int i = 0; i < capacity; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;

		capacity = new_capacity;
		cout << "NEW CAP: " << capacity << "\n";
	}
public:

	void SetCapacity()
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
	}

	int Getsize()
	{
		return size;
	}

	int GetCapacity()
	{
		return capacity;
	}

	void PushBack(int value)
	{
		EnsureCapacity(size + 1);
		data[size++] = value;
	}

	Vector operator+(const Vector& another)
	{
		Vector result;

		result.capacity = this->capacity + another.capacity;
		result.size = this->size + another.size;
		result.data = new int[result.capacity];

		int index = 0;
		for (; index < this->size; index++)
		{
			result.data[index] = this->data[index];
		}

		for (; index < this->size + another.size; index++)
		{
			result.data[index] = another.data[index - this->size];
		}

		return result;
	}


	bool Equals(const Vector& another)const
	{
		if (size == another.size)
		{
			int result = 0;
			for (int i = 0; i < size; i++)
			{
				if (data[i] == another.data[i])
				{
					result++;
				}
			}
			return result == size;
		}

		return false;
	}

	void PushFront(int value)
	{
		for (int i = size; i > 0; i--)
		{
			data[i] = data[i - 1];
		}
		data[0] = value;
		size++;
	}

	void Insert(int index, int value)
	{
		if (index > 0 || index < size)
		{
			EnsureCapacity(size + 1);
			size++;

			for (int i = size - 1; i >= index; i--)
			{
				data[i] = data[i - 1];
			}
			data[index] = value;
		}
		else
		{
			return;
		}
	}

	void RemoveAt(int index)
	{
		if (index > 0 || index < size)
		{
			for (int i = index; i < size; i++)
			{
				data[i] = data[i + 1];
			}
		}
		else
		{
			return;
		}

		size--;
	}

	void Remove(int value) override
	{
		int i = 0;
		while (data[i] == value)
		{
			RemoveAt(i);
			i--;
		}
	}

	void PopFront()
	{
		RemoveAt(0);
	}

	void PopBack()
	{
		RemoveAt(size - 1);
	}

	Vector(const Vector& original)
	{
		this->size = original.size;
		this->capacity = original.capacity;
		this->data = new int[original.capacity];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = original.data[i];
		}
	}

	void Clear()
	{
		size = 0;
	}

	bool IsEmpty()
	{
		return size == 0;
	}

	void TrimToSize()
	{
		capacity = size;
		int* tmp = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
	}

	void Print() override
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << data[i] << " ";
			}
			cout << "\n";
		}
	}

	int IndexOf(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->data[i] == value)
			{
				return i;
			}
		}
		return -1;
	}

	int LastIndexOf(int value)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if (this->data[i] == value)
			{
				return i;
			}
		}
		return -1;
	}

	void Reverse()
	{
		reverse(data, data + size);
	}

	void SortAsc()
	{
		sort(data, data + size);
	}
	void SortDesc()
	{
		sort(data, data + size);
		Reverse();
	}

	void Shuffle()
	{
		random_shuffle(data, data + size);
	}

	void  RandomFill()
	{		
		for (int i = 0; i < size; i++)
		{
			data[i] = (rand() % 10);
		}
	}

	int GetElementAt(unsigned int index) const
	{
		if (index >= size) throw "Incorrect index!";
		return data[index];
	}

	Vector Clone(const Vector& clone)
	{
		size = clone.size;
		capacity = clone.capacity;
		data = new int[clone.capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = clone.data[i];
		}
		return clone;
	}

	bool operator==(const Vector& another)
	{
		return Equals(another);
	}

	Vector operator=(const Vector& another)
	{
		return Clone(another);
	}

	const int& operator[](unsigned int index) const
	{
		if (index >= size) throw "Incorrect index!";
		return data[index];
	}

	friend istream& operator>>(istream& is, Vector& original)
	{
		for (int i = 0; i <= original.size; i++)
		{
			is >> original.data[i];
		}
		return is;
	}

	int GetCount() override
	{
		return capacity;
	}

	void Add(int value) override
	{
		PushFront(value);
	}

	int Search(int value) override
	{
		for (int i = 0; i < size; i++)
		{
			if (this->data[i] == value)
			{
				return i;
			}
		}
		return -1;
	}

	void Replace(int value) override
	{
		RemoveAt(value);
		PushFront(value);

	}

	void Sort() override
	{
		sort(data, data + size);
	}
};

