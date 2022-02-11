template <class T>

class MyCollection //abstract
{
protected:
	int count;

public:
	MyCollection(int count = 4)
	{
		this->count = count;
	}
	virtual int GetCount()
	{
		return count;
	}

	virtual void Add(T count)
	{
	}

	virtual void Remove(int count)
	{
	}

	virtual void Print()
	{
		cout << "MyCollection have: " << GetCount() << " classes\n\n";
	}

	virtual T Search(T count)
	{
		return 0;
	}

	virtual void Replace(T count)
	{
	}

	virtual void Sort()
	{
	}
};

