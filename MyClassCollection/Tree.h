class Tree : virtual public MyCollection<int>
{
	set <int> st;
	set <int> ::iterator it = st.begin();
	map <int, int> mp;
	map <int, int> ::iterator im = mp.begin();

public:
	void Add(int data) override
	{
		st.insert(data);
	}

	void Remove(int data)
	{
		st.erase(data);
	}

	int Search(int data) override
	{
		it = st.find(3);
		return *it;
	}

	void Replace(int data) override
	{
		st.erase(it);
		Add(data);
	}

	void Print() override
	{
		for (it = st.begin(); it != st.end(); it++)
			cout << *it << " ";
		cout << "\n";
	}
};
